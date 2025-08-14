import tkinter as tk
from tkinter import messagebox, filedialog
import random
import copy
import time
from datetime import datetime
import uuid

# Hàm trả về danh sách các ký hiệu hợp lệ cho bảng Sudoku (1-9 cho 9x9, thêm A-F cho 16x16)
def get_symbols(N):
    if N <= 9:
        return [str(i) for i in range(1, N + 1)]  # Trả về danh sách số từ 1 đến N
    return [str(i) for i in range(1, 10)] + [chr(ord('A') + i) for i in range(N - 9)]  # Thêm chữ cái cho N > 9

# Kiểm tra xem giá trị val có thể đặt vào ô (row, col) trên bảng hay không
def is_valid(board, row, col, val, N, box_size, is_sudoku_x):
    # Kiểm tra hàng và cột
    for i in range(N):
        if board[row][i] == val or board[i][col] == val:
            return False
    # Kiểm tra khối box_size x box_size
    br, bc = (row // box_size) * box_size, (col // box_size) * box_size
    for i in range(box_size):
        for j in range(box_size):
            if board[br + i][bc + j] == val:
                return False
    # Kiểm tra hai đường chéo nếu là Sudoku X và N=9
    if is_sudoku_x and N == 9:
        if row == col and any(board[i][i] == val for i in range(N)):
            return False
        if row + col == N - 1 and any(board[i][N - 1 - i] == val for i in range(N)):
            return False
    return True

# Tìm ô có số giá trị khả thi ít nhất (Minimum Remaining Values - MRV)
def find_mrv_cell(board, N, box_size, is_sudoku_x, symbols):
    min_options = N + 1
    best_cell = None
    for row in range(N):
        for col in range(N):
            if board[row][col] == '0':  # Nếu ô trống
                options = [val for val in symbols if is_valid(board, row, col, val, N, box_size, is_sudoku_x)]
                if not options:  # Nếu không có giá trị hợp lệ, trả về None
                    return None
                if len(options) < min_options:  # Cập nhật ô có ít giá trị hợp lệ nhất
                    min_options = len(options)
                    best_cell = (row, col, options)
                    if min_options == 1:  # Nếu chỉ có 1 giá trị, dừng ngay
                        return best_cell
    return best_cell

# Giải bảng Sudoku bằng thuật toán backtracking, trả về số lần thử và kết quả
def solve_sudoku(board, N, box_size, is_sudoku_x, symbols, trial_count=0):
    cell = find_mrv_cell(board, N, box_size, is_sudoku_x, symbols)
    if cell is None:  # Nếu không còn ô trống nào
        return trial_count, all(all(cell != '0' for cell in row) for row in board)
    row, col, options = cell
    for val in options:  # Thử từng giá trị hợp lệ
        trial_count += 1
        board[row][col] = val
        new_count, result = solve_sudoku(board, N, box_size, is_sudoku_x, symbols, trial_count)
        if result:  # Nếu tìm được lời giải
            return new_count, True
        board[row][col] = '0'  # Quay lui nếu không thành công
    return trial_count, False

# Kiểm tra xem bảng ban đầu có hợp lệ (không vi phạm luật Sudoku)
def is_initial_board_valid(board, N, box_size, is_sudoku_x):
    temp_board = copy.deepcopy(board)
    for r in range(N):
        for c in range(N):
            val = temp_board[r][c]
            if val != '0':
                temp_board[r][c] = '0'  # Xóa giá trị để kiểm tra
                if not is_valid(temp_board, r, c, val, N, box_size, is_sudoku_x):
                    return False
                temp_board[r][c] = val  # Khôi phục giá trị
    return True

# Tạo một bảng Sudoku hoàn chỉnh (đã điền đầy)
def generate_full_solution(N, box_size, symbols, is_sudoku_x):
    board = [['0' for _ in range(N)] for _ in range(N)]
    def fill():
        cell = find_mrv_cell(board, N, box_size, is_sudoku_x, symbols)
        if cell is None:
            return True
        row, col, options = cell
        random.shuffle(options)  # Xáo trộn để tạo giải pháp ngẫu nhiên
        for val in options:
            board[row][col] = val
            if fill():
                return True
            board[row][col] = '0'
        return False
    return board if fill() else None

# Đếm số lời giải của bảng, tối đa limit (thường là 2 để kiểm tra tính duy nhất)
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

# Tạo đề Sudoku với số ô trống được chỉ định, đảm bảo chỉ có một lời giải
def generate_puzzle(N, box_size, symbols, is_sudoku_x, empty_cells, max_attempts=10):
    for _ in range(max_attempts):
        solution = generate_full_solution(N, box_size, symbols, is_sudoku_x)
        if not solution:
            continue
        puzzle = [['0' for _ in range(N)] for _ in range(N)]
        positions = [(r, c) for r in range(N) for c in range(N)]
        random.shuffle(positions)
        fixed_positions = positions[:N * N - empty_cells]  # Giữ lại các ô cố định
        for r, c in fixed_positions:
            puzzle[r][c] = solution[r][c]
        if count_solutions(puzzle, N, box_size, is_sudoku_x, symbols) == 1:  # Đảm bảo chỉ có 1 lời giải
            return puzzle, solution
    raise ValueError("Không thể tạo đề hợp lệ.")

# Đánh giá độ khó dựa trên số ô trống
def analyze_difficulty(board, N):
    empty = sum(cell == '0' for row in board for cell in row)
    if empty <= N:
        return "Dễ"
    elif empty <= N * 2:
        return "Trung bình"
    return "Khó"

# Lớp chính để tạo giao diện và xử lý logic Sudoku
class SudokuGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Sudoku")  # Tiêu đề cửa sổ
        self.root.geometry("600x700")  # Kích thước cửa sổ
        self.entries = []  # Lưu các ô nhập liệu
        self.solution = None  # Lưu lời giải
        self.start_time = None  # Thời gian bắt đầu
        self.timer_running = False  # Trạng thái bộ đếm thời gian
        self.empty_cells = 0  # Số ô trống
        self.N = tk.IntVar(value=9)  # Kích thước bảng (mặc định 9x9)
        self.difficulty = tk.StringVar(value="Trung bình")  # Độ khó mặc định
        self.is_sudoku_x = tk.BooleanVar()  # Chế độ Sudoku X
        self.root.configure(bg="#ffffff")  # Màu nền
        self.cell_font = ("Arial", 18)  # Font cho ô nhập liệu
        self.button_font = ("Arial", 12)  # Font cho nút
        self.label_font = ("Arial", 12, "bold")  # Font cho nhãn
        self.colors = {  # Các màu sắc sử dụng trong giao diện
            "bg": "#ffffff",
            "fixed_cell": "#e0e0e0",
            "user_cell": "#ffffff",
            "hint_cell": "#d0f0c0",
            "button_bg": "#4CAF50",
            "button_fg": "#ffffff",
            "button_hover": "#45a049"
        }
        self.undo_stack = []  # Ngăn xếp lưu trạng thái Undo
        self.redo_stack = []  # Ngăn xếp lưu trạng thái Redo
        self.setup_menu()  # Tạo menu
        self.setup_board()  # Tạo bảng Sudoku
        self.setup_timer()  # Tạo bộ đếm thời gian

    # Tạo menu với các tùy chọn và nút chức năng
    def setup_menu(self):
        top = tk.Frame(self.root, bg=self.colors["bg"])
        top.pack(pady=10)
        tk.Label(top, text="Kích thước:", font=self.label_font, bg=self.colors["bg"]).pack(side=tk.LEFT, padx=10)
        tk.OptionMenu(top, self.N, 9, 16, command=self.reset_board).pack(side=tk.LEFT, padx=10)
        tk.Checkbutton(top, text="Sudoku X", variable=self.is_sudoku_x, font=self.label_font, bg=self.colors["bg"]).pack(side=tk.LEFT, padx=10)
        tk.Label(top, text="Độ khó:", font=self.label_font, bg=self.colors["bg"]).pack(side=tk.LEFT, padx=10)
        tk.OptionMenu(top, self.difficulty, "Dễ", "Trung bình", "Khó").pack(side=tk.LEFT, padx=10)
        buttons = [  # Danh sách các nút chức năng
            ("Tạo đề", self.generate_puzzle),
            ("Kiểm tra", self.check_result),
            ("Gợi ý", self.give_hint),
            ("Lời giải", self.reveal_solution),
            ("Lưu đề", self.save_puzzle),
            ("Tải đề", self.load_puzzle),
            ("Undo", self.undo),
            ("Redo", self.redo),
        ]
        for text, command in buttons:
            btn = tk.Button(top, text=text, command=command, font=self.button_font, bg=self.colors["button_bg"],
                            fg=self.colors["button_fg"], activebackground=self.colors["button_hover"],
                            relief=tk.FLAT, padx=10, pady=5)
            btn.pack(side=tk.LEFT, padx=5)
            btn.bind("<Enter>", lambda e, b=btn: b.config(bg=self.colors["button_hover"]))  # Hiệu ứng hover
            btn.bind("<Leave>", lambda e, b=btn: b.config(bg=self.colors["button_bg"]))

    # Tạo khung chứa bảng Sudoku
    def setup_board(self):
        self.grid_frame = tk.Frame(self.root, bg=self.colors["bg"])
        self.grid_frame.pack(pady=20)
        self.create_board(self.N.get())

    # Tạo bộ đếm thời gian
    def setup_timer(self):
        self.timer_label = tk.Label(self.root, text="Thời gian: 00:00:000", font=self.label_font, bg=self.colors["bg"])
        self.timer_label.pack(pady=10)
        self.update_timer()

    # Cập nhật thời gian hiển thị
    def update_timer(self):
        if self.timer_running and self.start_time:
            elapsed = time.perf_counter() - self.start_time
            minutes = int(elapsed // 60)
            seconds = int(elapsed % 60)
            milliseconds = round((elapsed % 1) * 1000)
            self.timer_label.config(text=f"Thời gian: {minutes:02d}:{seconds:02d}:{milliseconds:03d}")
            self.root.after(100, self.update_timer)

    # Tạo lưới các ô nhập liệu cho bảng Sudoku
    def create_board(self, N):
        self.entries = []
        cell_size = 50 if N == 9 else 40  # Kích thước ô nhỏ hơn cho bảng 16x16
        for r in range(N):
            row_entries = []
            for c in range(N):
                frame = tk.Frame(self.grid_frame, width=cell_size, height=cell_size, bg=self.colors["bg"])
                frame.grid(row=r, column=c, padx=1, pady=1)
                e = tk.Entry(frame, width=2, justify="center", font=self.cell_font, bd=1, relief=tk.SOLID)
                e.pack(fill=tk.BOTH, expand=True)
                e.bind("<KeyRelease>", lambda event, row=r, col=c: self.save_undo_state(row, col))  # Lưu trạng thái khi nhập
                row_entries.append(e)
            self.entries.append(row_entries)

    # Đặt lại bảng về trạng thái ban đầu
    def reset_board(self, *_):
        for widget in self.grid_frame.winfo_children():
            widget.destroy()
        self.create_board(self.N.get())
        self.solution = None
        self.start_time = None
        self.timer_running = False
        self.timer_label.config(text="Thời gian: 00:00:000")
        self.empty_cells = 0
        self.undo_stack.clear()
        self.redo_stack.clear()

    # Xóa toàn bộ bảng
    def clear_board(self):
        for row in self.entries:
            for e in row:
                e.delete(0, tk.END)
                e.config(bg=self.colors["user_cell"])
        self.solution = None
        self.start_time = None
        self.timer_running = False
        self.timer_label.config(text="Thời gian: 00:00:000")
        self.undo_stack.clear()
        self.redo_stack.clear()

    # Tạo đề Sudoku mới
    def generate_puzzle(self):
        N = self.N.get()
        box_size = int(N ** 0.5)
        symbols = get_symbols(N)
        is_sudoku_x = self.is_sudoku_x.get()
        difficulty = self.difficulty.get()
        empty_cells = N * N // 3 if difficulty == "Dễ" else N * N // 2 if difficulty == "Trung bình" else int(N * N / 1.5)
        try:
            puzzle, solution = generate_puzzle(N, box_size, symbols, is_sudoku_x, empty_cells)
            self.solution = solution
            self.empty_cells = empty_cells
            self.start_time = time.perf_counter()
            self.timer_running = True
            self.update_timer()
            self.display_board(puzzle)
            messagebox.showinfo("Thành công", f"Đã tạo đề Sudoku {N}x{N} với {empty_cells} ô trống.")
        except ValueError as e:
            messagebox.showerror("Lỗi", str(e))

    # Kiểm tra xem bảng đã hoàn thành đúng chưa
    def check_result(self):
        N = self.N.get()
        box_size = int(N ** 0.5)
        is_sudoku_x = self.is_sudoku_x.get()
        board = self.get_board_from_entries()
        if not is_initial_board_valid(board, N, box_size, is_sudoku_x):
            messagebox.showerror("Lỗi", "Bảng Sudoku không hợp lệ.")
            return
        if self.solution is None:
            messagebox.showwarning("Cảnh báo", "Vui lòng tạo đề Sudoku trước.")
            return
        trial_count, solved = solve_sudoku(board, N, box_size, is_sudoku_x, get_symbols(N))
        if solved:
            messagebox.showinfo("Kết quả", f"Bạn đã hoàn thành bảng Sudoku với {trial_count} lần thử.")
            with open("lich_su_sudoku.txt", "a", encoding="utf-8") as f:
                now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
                f.write(f"{now} | Kích thước: {N}x{N} | Độ khó: {self.difficulty.get()} | Số lần thử: {trial_count}\n")
        else:
            messagebox.showwarning("Cảnh báo", "Bạn chưa hoàn thành bảng Sudoku.")

    # Cung cấp một gợi ý bằng cách điền một ô từ lời giải
    def give_hint(self):
        N = self.N.get()
        box_size = int(N ** 0.5)
        is_sudoku_x = self.is_sudoku_x.get()
        board = self.get_board_from_entries()
        if not is_initial_board_valid(board, N, box_size, is_sudoku_x):
            messagebox.showerror("Lỗi", "Bảng Sudoku không hợp lệ.")
            return
        if self.solution is None:
            messagebox.showwarning("Cảnh báo", "Vui lòng tạo đề Sudoku trước.")
            return
        for r in range(N):
            for c in range(N):
                if board[r][c] == '0':
                    board[r][c] = self.solution[r][c]
                    self.display_board(board)
                    messagebox.showinfo("Gợi ý", f"Điền {board[r][c]} vào ô ({r+1}, {c+1})")
                    return
        messagebox.showinfo("Gợi ý", "Không có gợi ý nào có thể được đưa ra.")

    # Hiển thị toàn bộ lời giải
    def reveal_solution(self):
        N = self.N.get()
        box_size = int(N ** 0.5)
        is_sudoku_x = self.is_sudoku_x.get()
        board = self.get_board_from_entries()
        if not is_initial_board_valid(board, N, box_size, is_sudoku_x):
            messagebox.showerror("Lỗi", "Bảng Sudoku không hợp lệ.")
            return
        if self.solution is None:
            messagebox.showwarning("Cảnh báo", "Vui lòng tạo đề Sudoku trước.")
            return
        self.display_board(self.solution)
        messagebox.showinfo("Lời giải", "Đã hiển thị lời giải.")

    # Lưu bảng Sudoku vào file
    def save_puzzle(self):
        N = self.N.get()
        box_size = int(N ** 0.5)
        is_sudoku_x = self.is_sudoku_x.get()
        board = self.get_board_from_entries()
        if not is_initial_board_valid(board, N, box_size, is_sudoku_x):
            messagebox.showerror("Lỗi", "Bảng Sudoku không hợp lệ.")
            return
        filename = filedialog.asksaveasfilename(defaultextension=".txt", filetypes=[("Text files", "*.txt")])
        if filename:
            try:
                with open(filename, "w") as f:
                    f.write(f"Sudoku {N}x{N} (Sudoku X: {is_sudoku_x})\n")
                    for r in range(N):
                        f.write(" ".join(board[r]) + "\n")
                messagebox.showinfo("Lưu thành công", f"Đã lưu bảng Sudoku vào {filename}")
            except IOError:
                messagebox.showerror("Lỗi lưu", f"Không thể lưu file {filename}")

    # Tải bảng Sudoku từ file
    def load_puzzle(self):
        filename = filedialog.askopenfilename(filetypes=[("Text files", "*.txt")])
        if filename:
            try:
                with open(filename, "r") as f:
                    lines = f.readlines()
                    parts = lines[0].strip().split()
                    N = int(parts[1].split('x')[0])
                    is_sudoku_x = "Sudoku X: True" in lines[0]
                    board = [line.strip().split() for line in lines[1:N+1]]
                    self.N.set(N)
                    self.is_sudoku_x.set(is_sudoku_x)
                    self.reset_board()
                    self.display_board(board)
                    messagebox.showinfo("Tải thành công", f"Đã tải bảng Sudoku từ {filename}")
            except (IOError, ValueError):
                messagebox.showerror("Lỗi tải", "Không thể đọc hoặc định dạng file không hợp lệ.")

    # Lấy trạng thái bảng từ các ô nhập liệu
    def get_board_from_entries(self):
        N = self.N.get()
        symbols = get_symbols(N)
        board = []
        for row in self.entries:
            current_row = []
            for e in row:
                val = e.get().strip().upper()
                if val == "":
                    val = '0'
                elif val not in symbols:  # Thay thế giá trị không hợp lệ bằng '0'
                    val = '0'
                current_row.append(val)
            board.append(current_row)
        return board

    # Hiển thị bảng lên giao diện
    def display_board(self, board):
        for r in range(len(board)):
            for c in range(len(board[r])):
                e = self.entries[r][c]
                val = board[r][c]
                e.delete(0, tk.END)
                if val != '0':
                    e.insert(0, val)
                    e.config(bg=self.colors["fixed_cell" if val == self.solution[r][c] else "hint_cell"])
                else:
                    e.config(bg=self.colors["user_cell"])

    # Lưu trạng thái bảng cho Undo
    def save_undo_state(self, row, col):
        board = self.get_board_from_entries()
        self.undo_stack.append(copy.deepcopy(board))
        self.redo_stack.clear()  # Xóa redo stack khi có thay đổi mới

    # Hoàn tác (Undo)
    def undo(self):
        if self.undo_stack:
            current = self.get_board_from_entries()
            self.redo_stack.append(copy.deepcopy(current))
            board = self.undo_stack.pop()
            self.display_board(board)

    # Làm lại (Redo)
    def redo(self):
        if self.redo_stack:
            current = self.get_board_from_entries()
            self.undo_stack.append(copy.deepcopy(current))
            board = self.redo_stack.pop()
            self.display_board(board)

# Chạy chương trình
if __name__ == "__main__":
    root = tk.Tk()
    app = SudokuGUI(root)
    root.mainloop()