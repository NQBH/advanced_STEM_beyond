import random

# Kiểm tra tính hợp lệ của số được điền vào ô
def is_valid(board, row, col, num):
    # Kiểm tra hàng
    for i in range(9):
        if board[row][i] == num:
            return False

    # Kiểm tra cột
    for i in range(9):
        if board[i][col] == num:
            return False

    # Kiểm tra vùng 3x3
    start_row = row - row % 3
    start_col = col - col % 3
    for i in range(3):
        for j in range(3):
            if board[i + start_row][j + start_col] == num:
                return False

    return True

# Heuristic: Tìm ô trống có ít khả năng điền nhất (MRV)
def find_mrv(board):
    min_possible_values = 10  # Giá trị khả thi tối đa là 9
    mrv = (-1, -1)

    for row in range(9):
        for col in range(9):
            if board[row][col] == 0:  # Nếu ô trống
                possible_values = 0
                for num in range(1, 10):  # Kiểm tra các số từ 1 đến 9
                    if is_valid(board, row, col, num):
                        possible_values += 1
                if possible_values < min_possible_values:
                    min_possible_values = possible_values
                    mrv = (row, col)

    return mrv

# Giải Sudoku bằng thuật toán backtracking kết hợp heuristic MRV
def solve_sudoku(board):
    row, col = find_mrv(board)

    if row == -1 and col == -1:  # Nếu không còn ô trống
        return True

    for num in range(1, 10):
        if is_valid(board, row, col, num):
            board[row][col] = num
            if solve_sudoku(board):
                return True
            board[row][col] = 0  # Quay lại nếu không giải được

    return False  # Nếu không tìm thấy lời giải

# Sinh bảng Sudoku đầy đủ
def generate_full_board():
    board = [[0 for _ in range(9)] for _ in range(9)]
    solve_sudoku(board)
    return board

# Xóa ô để tạo bài toán Sudoku
def remove_cells(board, num_remove=40):
    count = num_remove
    while count > 0:
        row = random.randint(0, 8)
        col = random.randint(0, 8)
        if board[row][col] != 0:
            board[row][col] = 0
            count -= 1
    return board
