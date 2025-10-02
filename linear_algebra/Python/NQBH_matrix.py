# input a matrix using nested lists with user input
def input_matrix():
	num_row, num_col = map(int, input().split())
	matrix = []
	for i in range(num_row):
		row_str = input()
		row_elements = [int(x) for x in row_str.split()]
		matrix.append(row_elements)
	return matrix

# output a matrix for nested lists
def print_matrix(matrix):
	for row in matrix:
		print(row)

a = input_matrix()
print_matrix(a)

# input a matrix using NumPy arrays
import numpy as np
def input_numpy_matrix():
	num_row, num_col = map(int, input().split())
	elements = []
	print("Enter matrix elements row by row, separated by spaces:")
	for i in range(num_row):
		row_str = input(f"Enter elements for row {i+1}: ")
		elements.extend([int(x) for x in row_str.split()])
	matrix = np.array(elements).reshape(num_row, num_col)
	return matrix

a = input_numpy_matrix()
print(a)