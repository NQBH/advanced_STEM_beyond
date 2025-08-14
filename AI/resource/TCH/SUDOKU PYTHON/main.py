import tkinter as tk
from tkinter import messagebox, filedialog
import random
import copy
import time
from datetime import datetime

trial_count = [0]

def get_symbols(N):
    if N <= 9:
        return [str(i) for i in range(1, N + 1)]
    return [str(i) for i in range(1, 10)] + [chr(ord('A') + i) for i in range(N - 9)]

def is_valid(board, row, col, val, N, box_size, is_sudoku_x):
    for i in range(N):
        if board[row][i] == val or board[i][col] == val:
            return False
    br, bc = (row // box_size) * box_size, (col // box_size) * box_size
    for i in range(box_size):
        for j in range(box_size):
            if board[br + i][bc + j] == val:
                return False
    if is_sudoku_x and N == 9:
        if row == col and any(board[i][i] == val for i in range(N)):
            return False
        if row + col == N - 1 and any(board[i][N - 1 - i] == val for i in range(N)):
            return False
    return True

def find_mrv_cell(board, N, box_size, is_sudoku_x, symbols):
    min_options = N + 1
    best_cell = None
    for row in range(N):
        for col in range(N):
            if board[row][col] == '0':
                options = [val for val in symbols if is_valid(board, row, col, val, N, box_size, is_sudoku_x)]
                if not options:
                    return None
                if len(options) < min_options:
                    min_options = len(options)
                    best_cell = (row, col, options)
                    if min_options == 1:
                        return best_cell
    return best_cell

def solve_sudoku(board, N, box_size, is_sudoku_x, symbols, trial_count):
    cell = find_mrv_cell(board, N, box_size, is_sudoku_x, symbols)
    if cell is None:
        return all(all(cell != '0' for cell in row) for row in board)
    row, col, options = cell
    for val in options:
        trial_count[0] += 1
        board[row][col] = val
        if solve_sudoku(board, N, box_size, is_sudoku_x, symbols, trial_count):
            return True
        board[row][col] = '0'
    return False

def is_initial_board_valid(board, N, box_size, is_sudoku_x):
    temp_board = copy.deepcopy(board)
    for r in range(N):
        for c in range(N):
            val = temp_board[r][c]
            if val != '0':
                temp_board[r][c] = '0'
                if not is_valid(temp_board, r, c, val, N, box_size, is_sudoku_x):
                    return False
                temp_board[r][c] = val
    return True

def generate_full_solution(N, box_size, symbols, is_sudoku_x):
    board = [['0' for _ in range(N)] for _ in range(N)]
    # Giảm số ô cố định ban đầu cho 16x16 để tăng tính ngẫu nhiên
    if N == 16:
        board[0][0] = random.choice(symbols)  # Chỉ khởi tạo 1 ô ngẫu nhiên
    def fill():
        cell = find_mrv_cell(board, N, box_size, is_sudoku_x, symbols)
        if cell is None:
            return True
        row, col, options = cell
        random.shuffle(options)
        for val in options:
            board[row][col] = val
            if fill():
                return True
            board[row][col] = '0'
        return False
    if fill():
        return board
    return None

def count_solutions(board, N, box_size, is_sudoku_x, symbols, limit=2):
    board_copy = copy.deepcopy(board)
    count = 0
    def backtrack():
        nonlocal count
        if count >= limit:
            return
        cell = find_mrv_cell(board_copy, N, box_size, is_sudoku_x, symbols)
        if cell is None:
            if all(all(cell != '0' for cell in row) for row in board_copy):
                count += 1
            return
        row, col, options = cell
        for val in options:
            board_copy[row][col] = val
            backtrack()
            board_copy[row][col] = '0'
    backtrack()
    return count

def generate_puzzle(N, box_size, symbols, is_sudoku_x, empty_cells, max_attempts=20):
    for attempt in range(max_attempts):
        solution = generate_full_solution(N, box_size, symbols, is_sudoku_x)
        if not solution:
            continue
        puzzle = [['0' for _ in range(N)] for _ in range(N)]
        positions = [(r, c) for r in range(N) for c in range(N)]
        random.shuffle(positions)
        fixed_positions = positions[:N * N - empty_cells]
        for r, c in fixed_positions:
            puzzle[r][c] = solution[r][c]
        temp_board = copy.deepcopy(puzzle)
        trial_count[0] = 0
        if count_solutions(temp_board, N, box_size, is_sudoku_x, symbols) == 1 and solve_sudoku(temp_board, N, box_size, is_sudoku_x, symbols, trial_count):
            return puzzle, solution
        # Giảm số ô trống nếu không tạo được đề hợp lệ
        if attempt == max_attempts - 1 and empty_cells > N * N // 4:
            return generate_puzzle(N, box_size, symbols, is_sudoku_x, empty_cells - 5, max_attempts)
    raise ValueError("Không thể tạo đề hợp lệ sau nhiều lần thử. Vui lòng thử lại hoặc giảm độ khó.")

class SudokuGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Sudoku GUI - Hoan Trương")
        self.root.geometry("700x800")  # Tăng kích thước cửa sổ
        self.entries = []
        self.solution = None
        self.start_time = None
        self.timer_running = False
        self.empty_cells = 0
        self.N = tk.IntVar(value=9)
        self.difficulty = tk.StringVar(value="Trung bình")
        self.is_sudoku_x = tk.BooleanVar()
        self.root.configure(bg="#ffffff")
        self.cell_font = ("Arial", 18)  # Tăng font cho dễ đọc
        self.button_font = ("Arial", 12)
        self.label_font = ("Arial", 12, "bold")
        self.colors = {
            "bg": "#ffffff",
            "fixed_cell": "#e0e0e0",
            "user_cell": "#ffffff",
            "hint_cell": "#d0f0c0",
            "solution_cell": "#d0ffd0",
            "error_cell": "#ffcccc",
            "button_bg": "#4CAF50",
            "button_fg": "#ffffff",
            "button_hover": "#45a049"
        }
        self.setup_menu()
        self.setup_board()
        self.setup_timer()

    def setup_menu(self):
        top = tk.Frame(self.root, bg=self.colors["bg"])
        top.pack(pady=10)
        tk.Label(top, text="Kích thước:", font=self.label_font, bg=self.colors["bg"]).pack(side=tk.LEFT, padx=10)
        tk.OptionMenu(top, self.N, 9, 16, command=self.reset_board).pack(side=tk.LEFT, padx=10)
        tk.Checkbutton(top, text="Sudoku X", variable=self.is_sudoku_x, font=self.label_font, bg=self.colors["bg"]).pack(side=tk.LEFT, padx=10)
        tk.Label(top, text="Độ khó:", font=self.label_font, bg=self.colors["bg"]).pack(side=tk.LEFT, padx=10)
        tk.OptionMenu(top, self.difficulty, "Dễ", "Trung bình", "Khó").pack(side=tk.LEFT, padx=10)
        buttons = [
            ("Tạo đề", self.generate_puzzle),
            ("Kiểm tra", self.check_result),
            ("Gợi ý", self.give_hint),
            ("Lời giải", self.reveal_solution),
            ("Hoàn thành", self.finish_and_save),
            ("Nhập và giải", self.input_and_solve),
            ("Xóa bảng", self.clear_board),
            ("Lưu đề", self.save_puzzle),
            ("Tải đề", self.load_puzzle),
            ("Hướng dẫn", self.show_help)
        ]
        for text, command in buttons:
            btn = tk.Button(top, text=text, command=command, font=self.button_font, bg=self.colors["button_bg"],
                            fg=self.colors["button_fg"], activebackground=self.colors["button_hover"],
                            relief=tk.FLAT, padx=10, pady=5)
            btn.pack(side=tk.LEFT, padx=5)
            btn.bind("<Enter>", lambda e, b=btn: b.config(bg=self.colors["button_hover"]))
            btn.bind("<Leave>", lambda e, b=btn: b.config(bg=self.colors["button_bg"]))

    def setup_board(self):
        self.grid_frame = tk.Frame(self.root, bg=self.colors["bg"])
        self.grid_frame.pack(pady=20)
        self.create_board(self.N.get())

    def setup_timer(self):
        self.timer_label = tk.Label(self.root, text="Thời gian: 00:00:000", font=self.label_font, bg=self.colors["bg"])
        self.timer_label.pack(pady=10)
        self.update_timer()

    def update_timer(self):
        if self.timer_running and self.start_time:
            elapsed = time.perf_counter() - self.start_time
            minutes = int(elapsed // 60)
            seconds = int(elapsed % 60)
            milliseconds = round((elapsed % 1) * 1000)
            self.timer_label.config(text=f"Thời gian: {minutes:02d}:{seconds:02d}:{milliseconds:03d}")
            self.root.after(100, self.update_timer)

    def create_board(self, N):
        self.entries = []
        cell_size = 50 if N == 9 else 45  # Tăng kích thước ô cho 16x16
        for r in range(N):
            row_entries = []
            for c in range(N):
                frame = tk.Frame(self.grid_frame, width=cell_size, height=cell_size, bg=self.colors["bg"])
                frame.grid(row=r, column=c, padx=1, pady=1)
                e = tk.Entry(frame, width=2, justify="center", font=self.cell_font, bd=1, relief=tk.SOLID,
                             highlightbackground="black", highlightcolor="black", highlightthickness=1)
                e.pack(fill=tk.BOTH, expand=True)
                row_entries.append(e)
            self.entries.append(row_entries)

    def reset_board(self, *_):
        for widget in self.grid_frame.winfo_children():
            widget.destroy()
        self.create_board(self.N.get())
        self.solution = None
        self.start_time = None
        self.timer_running = False
        self.timer_label.config(text="Thời gian: 00:00:000")
        self.empty_cells = 0

    def clear_board(self):
        N = self.N.get()
        for r in range(N):
            for c in range(N):
                entry = self.entries[r][c]
                entry.config(state=tk.NORMAL, fg="blue", bg=self.colors["user_cell"])
                entry.delete(0, tk.END)
        self.solution = None
        self.start_time = None
        self.timer_running = False
        self.timer_label.config(text="Thời gian: 00:00:000")
        self.empty_cells = N * N

    def generate_puzzle(self):
        N = self.N.get()
        box_size = int(N ** 0.5)
        symbols = get_symbols(N)
        is_x = self.is_sudoku_x.get()
        difficulty = self.difficulty.get()
        empty_cells = {
            "Dễ": 30 if N == 9 else 100,
            "Trung bình": 40 if N == 9 else 140,
            "Khó": 50 if N == 9 else 180
        }[difficulty]
        try:
            puzzle, solution = generate_puzzle(N, box_size, symbols, is_x, empty_cells)
            self.solution = solution
            self.start_time = time.perf_counter()
            self.timer_running = True
            self.empty_cells = sum(row.count('0') for row in puzzle)
            for r in range(N):
                for c in range(N):
                    entry = self.entries[r][c]
                    entry.config(state=tk.NORMAL)
                    entry.delete(0, tk.END)
                    if puzzle[r][c] != '0':
                        entry.insert(0, puzzle[r][c])
                        entry.config(fg="black", bg=self.colors["fixed_cell"], state=tk.DISABLED)
                    else:
                        entry.config(fg="blue", bg=self.colors["user_cell"], state=tk.NORMAL)
        except ValueError as e:
            messagebox.showerror("Lỗi", f"{str(e)} Hãy thử lại hoặc chọn độ khó thấp hơn.")
            self.clear_board()

    def check_result(self):
        if not self.solution:
            messagebox.showwarning("Chưa có đề", "Hãy tạo đề trước khi kiểm tra.")
            return
        N = self.N.get()
        correct = True
        for r in range(N):
            for c in range(N):
                cell = self.entries[r][c]
                if cell['state'] == tk.NORMAL:
                    val = cell.get().strip().upper()
                    if val == self.solution[r][c]:
                        cell.config(bg=self.colors["user_cell"])
                    else:
                        cell.config(bg=self.colors["error_cell"])
                        correct = False
        if correct:
            messagebox.showinfo("✅ Chính xác", f"Bạn đã giải đúng! Số ô trống còn lại: {self.empty_cells}")
        else:
            messagebox.showwarning("⚠️ Sai", f"Có ô sai. Số ô trống còn lại: {self.empty_cells}")

    def give_hint(self):
        if not self.solution:
            messagebox.showwarning("Chưa có đề", "Hãy tạo đề trước khi xin gợi ý.")
            return
        N = self.N.get()
        empty_cells = [(r, c) for r in range(N) for c in range(N)
                       if self.entries[r][c]['state'] == tk.NORMAL and not self.entries[r][c].get()]
        if not empty_cells:
            messagebox.showinfo("🎉", "Không còn ô nào để gợi ý.")
            return
        r, c = random.choice(empty_cells)
        self.entries[r][c].delete(0, tk.END)
        self.entries[r][c].insert(0, self.solution[r][c])
        self.entries[r][c].config(fg="green", bg=self.colors["hint_cell"])
        self.empty_cells -= 1

    def reveal_solution(self):
        if not self.solution:
            messagebox.showwarning("Chưa có đề", "Không có lời giải để hiện.")
            return
        N = self.N.get()
        for r in range(N):
            for c in range(N):
                self.entries[r][c].config(state=tk.NORMAL)
                self.entries[r][c].delete(0, tk.END)
                self.entries[r][c].insert(0, self.solution[r][c])
                self.entries[r][c].config(fg="black", bg=self.colors["solution_cell"])
        self.empty_cells = 0

    def finish_and_save(self):
        if not self.solution:
            messagebox.showwarning("Chưa có đề", "Bạn chưa tạo đề để chơi.")
            return
        elapsed = time.perf_counter() - self.start_time if self.start_time else 0
        minutes = int(elapsed // 60)
        seconds = int(elapsed % 60)
        milliseconds = round((elapsed % 1) * 1000)
        time_str = f"{minutes:02d}:{seconds:02d}:{milliseconds:03d}"
        correct = True
        N = self.N.get()
        for r in range(N):
            for c in range(N):
                val = self.entries[r][c].get().strip().upper()
                if val != self.solution[r][c]:
                    correct = False
                    break
        now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        result = f"[{now}] - Kích thước: {N}x{N} | Độ khó: {self.difficulty.get()} | Đúng: {'Có' if correct else 'Không'} | Thời gian: {time_str} | Số lần thử: {trial_count[0]} | Ô trống còn lại: {self.empty_cells}\n"
        with open("ket_qua_sudoku.txt", "a", encoding="utf-8") as f:
            f.write(result)
        if correct:
            messagebox.showinfo("Hoàn thành", f"Chúc mừng! Đúng hết. Thời gian: {time_str} | Số lần thử: {trial_count[0]}")
        else:
            messagebox.showwarning("Sai", f"Có lỗi trong lời giải. Đã lưu kết quả. Thời gian: {time_str} | Số lần thử: {trial_count[0]}")
        self.timer_running = False

    def input_and_solve(self):
        N = self.N.get()
        box_size = int(N ** 0.5)
        symbols = get_symbols(N)
        is_x = self.is_sudoku_x.get()
        user_board = [['0' for _ in range(N)] for _ in range(N)]
        valid = True
        for r in range(N):
            for c in range(N):
                val = self.entries[r][c].get().strip().upper()
                if val == '':
                    user_board[r][c] = '0'
                elif val in symbols:
                    user_board[r][c] = val
                else:
                    valid = False
                    self.entries[r][c].config(bg=self.colors["error_cell"])
        if not valid:
            messagebox.showerror("Lỗi", "Có ký tự không hợp lệ! Chỉ nhập các ký hiệu: " + ", ".join(symbols) + " hoặc để trống.")
            return
        if not is_initial_board_valid(user_board, N, box_size, is_x):
            messagebox.showerror("Lỗi", "Đề nhập không hợp lệ! Vui lòng kiểm tra lại các ô cố định.")
            return
        board_to_solve = copy.deepcopy(user_board)
        self.start_time = time.perf_counter()
        trial_count[0] = 0
        if solve_sudoku(board_to_solve, N, box_size, is_x, symbols, trial_count):
            elapsed = time.perf_counter() - self.start_time
            minutes = int(elapsed // 60)
            seconds = int(elapsed % 60)
            milliseconds = round((elapsed % 1) * 1000)
            time_str = f"{minutes:02d}:{seconds:02d}:{milliseconds:03d}"
            self.solution = board_to_solve
            self.empty_cells = sum(row.count('0') for row in board_to_solve)
            for r in range(N):
                for c in range(N):
                    self.entries[r][c].config(state=tk.NORMAL)
                    self.entries[r][c].delete(0, tk.END)
                    self.entries[r][c].insert(0, self.solution[r][c])
                    self.entries[r][c].config(fg="black", bg=self.colors["solution_cell"])
            messagebox.showinfo("Thành công",
                                f"Lời giải được tìm thấy! Thời gian: {time_str} | Số lần thử: {trial_count[0]}")
        else:
            elapsed = time.perf_counter() - self.start_time
            minutes = int(elapsed // 60)
            seconds = int(elapsed % 60)
            milliseconds = round((elapsed % 1) * 1000)
            time_str = f"{minutes:02d}:{seconds:02d}:{milliseconds:03d}"
            messagebox.showwarning("Không có lời giải",
                                   f"Đề không có lời giải! Thời gian: {time_str} | Số lần thử: {trial_count[0]}")
        self.timer_running = False

    def save_puzzle(self):
        if not self.solution:
            messagebox.showwarning("Chưa có đề", "Hãy tạo đề trước khi lưu.")
            return
        N = self.N.get()
        puzzle = [['0' for _ in range(N)] for _ in range(N)]
        for r in range(N):
            for c in range(N):
                val = self.entries[r][c].get().strip().upper()
                puzzle[r][c] = val if val else '0'
        file_path = filedialog.asksaveasfilename(defaultextension=".txt", filetypes=[("Text files", "*.txt")])
        if file_path:
            with open(file_path, "w", encoding="utf-8") as f:
                f.write(f"{N}\n")
                f.write(f"{1 if self.is_sudoku_x.get() else 0}\n")
                for row in puzzle:
                    f.write(" ".join(row) + "\n")
            messagebox.showinfo("Thành công", "Đã lưu đề thành công!")

    def load_puzzle(self):
        file_path = filedialog.askopenfilename(filetypes=[("Text files", "*.txt")])
        if not file_path:
            return
        try:
            with open(file_path, "r", encoding="utf-8") as f:
                lines = f.readlines()
                N = int(lines[0].strip())
                is_sudoku_x = bool(int(lines[1].strip()))
                puzzle = [line.strip().split() for line in lines[2:2+N]]
            if len(puzzle) != N or any(len(row) != N for row in puzzle):
                raise ValueError("Định dạng file không hợp lệ.")
            self.N.set(N)
            self.is_sudoku_x.set(is_sudoku_x)
            self.reset_board()
            symbols = get_symbols(N)
            valid = True
            for r in range(N):
                for c in range(N):
                    val = puzzle[r][c]
                    if val != '0' and val not in symbols:
                        valid = False
                        self.entries[r][c].config(bg=self.colors["error_cell"])
                    self.entries[r][c].delete(0, tk.END)
                    if val != '0':
                        self.entries[r][c].insert(0, val)
                        self.entries[r][c].config(fg="black", bg=self.colors["fixed_cell"], state=tk.DISABLED)
                    else:
                        self.entries[r][c].config(fg="blue", bg=self.colors["user_cell"], state=tk.NORMAL)
            if not valid:
                messagebox.showerror("Lỗi", "File chứa ký tự không hợp lệ! Chỉ dùng: " + ", ".join(symbols))
                return
            box_size = int(N ** 0.5)
            if not is_initial_board_valid(puzzle, N, box_size, is_sudoku_x):
                messagebox.showerror("Lỗi", "Đề trong file không hợp lệ!")
                return
            trial_count[0] = 0
            self.solution = copy.deepcopy(puzzle)
            if not solve_sudoku(self.solution, N, box_size, is_sudoku_x, symbols, trial_count):
                self.solution = None
                messagebox.showwarning("Không có lời giải", "Đề trong file không có lời giải!")
            self.start_time = time.perf_counter()
            self.timer_running = True
            self.empty_cells = sum(row.count('0') for row in puzzle)
            messagebox.showinfo("Thành công", "Đã tải đề thành công!")
        except Exception as e:
            messagebox.showerror("Lỗi", f"Không thể tải file: {str(e)}")

    def show_help(self):
        help_text = """
        Hướng dẫn sử dụng Sudoku GUI:
        1. Chọn kích thước (9x9 hoặc 16x16) và độ khó (Dễ, Trung bình, Khó).
        2. Bật "Sudoku X" để thêm luật đường chéo (chỉ áp dụng cho 9x9).
        3. Nhấn "Tạo đề" để tạo đề mới.
        4. Nhập số/chữ (1-9 hoặc A-F cho 16x16) vào các ô trắng.
        5. Sử dụng các nút:
           - Kiểm tra: Kiểm tra lời giải của bạn.
           - Gợi ý: Điền một ô trống với giá trị đúng.
           - Lời giải: Hiện toàn bộ lời giải.
           - Hoàn thành: Kiểm tra và lưu kết quả.
           - Nhập và giải: Nhập đề tùy chỉnh và giải.
           - Xóa bảng: Làm mới bảng.
           - Lưu đề: Lưu đề hiện tại vào file .txt.
           - Tải đề: Tải đề từ file .txt.
        6. Đồng hồ thời gian hiển thị thời gian chơi.
        """
        messagebox.showinfo("Hướng dẫn", help_text)

# ======= CHẠY CHƯƠNG TRÌNH =======
if __name__ == "__main__":
    root = tk.Tk()
    app = SudokuGUI(root)
    root.mainloop()