# sudoku_gui.py
import tkinter as tk
from tkinter import messagebox
import random
from sudoku_solver import is_valid, solve_sudoku, generate_full_board, remove_cells

# Tạo giao diện GUI
def create_gui():
    window = tk.Tk()
    window.title("Sudoku Solver")

    entries = [[None for _ in range(9)] for _ in range(9)]

    def solve_and_display():
        board = []
        for row in range(9):
            board_row = []
            for col in range(9):
                try:
                    num = int(entries[row][col].get())
                    board_row.append(num)
                except ValueError:
                    board_row.append(0)
            board.append(board_row)

        if solve_sudoku(board):
            for row in range(9):
                for col in range(9):
                    entries[row][col].delete(0, tk.END)
                    entries[row][col].insert(0, str(board[row][col]))

                    if board[row][col] != 0:
                        entries[row][col].config(bg='lightgreen')
                    else:
                        entries[row][col].config(bg='white')
        else:
            messagebox.showinfo("Error", "No solution exists")

    def generate_new_sudoku():
        full_board = generate_full_board()
        puzzle_board = remove_cells(full_board, 40)

        for row in range(9):
            for col in range(9):
                entries[row][col].delete(0, tk.END)
                if puzzle_board[row][col] != 0:
                    entries[row][col].insert(0, str(puzzle_board[row][col]))

    def reset_board():
        for row in range(9):
            for col in range(9):
                entries[row][col].delete(0, tk.END)
                entries[row][col].config(bg='white')

    for i in range(9):
        for j in range(9):
            entries[i][j] = tk.Entry(window, width=2, font=("Arial", 18), justify='center')
            entries[i][j].grid(row=i, column=j)

    solve_button = tk.Button(window, text="Solve", command=solve_and_display)
    solve_button.grid(row=9, column=0, columnspan=9)

    generate_button = tk.Button(window, text="Generate New Sudoku", command=generate_new_sudoku)
    generate_button.grid(row=10, column=0, columnspan=9)

    reset_button = tk.Button(window, text="Reset", command=reset_board)
    reset_button.grid(row=11, column=0, columnspan=9)

    window.mainloop()

create_gui()
