def generate_pascals_triangle(n):
    triangle = []
    for i in range(n):
        row = [1] * (i + 1)
        for j in range(1, i):
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]
        triangle.append(row)
    return triangle

def print_triangle(triangle):
    n = len(triangle)
    
    # Hình tam giác "vuông cân"
    print("Tam giác Pascal 'vuông cân':")
    for i in range(n):
        print(' ' * (n - i - 1), end='')  # Căn giữa
        for num in triangle[i]:
            print(num, end=' ')
        print()
    
    # Hình tam giác "đều"
    print("\nTam giác Pascal 'đều':")
    for i in range(n):
        print(' ' * (n - i - 1), end='')  # Căn giữa
        for num in triangle[i]:
            print(num, end=' ')
        print()

n = int(input("Nhập vào giá trị n: "))
pascals_triangle = generate_pascals_triangle(n)
print_triangle(pascals_triangle)

def factorial(n):
    result = 1
    for i in range(2, n + 1):
        result *= i
    return result
def C(n, k):
    return factorial(n) // (factorial(k) * factorial(n - k))
def pascal_triangle_vuong(n):
    print("\nTam giác Pascal dạng vuông cân:")
    for i in range(n + 1):
        for j in range(i + 1):
            print(C(i, j), end=' ')
        print()
def pascal_triangle_deu(n):
    print("\nTam giác Pascal dạng đều:")
    for i in range(n + 1):
        print(" " * (n - i), end='')  
        for j in range(i + 1):
            print(C(i, j), end=' ')
        print()
n = int(input("Nhập số dòng của tam giác Pascal: "))
pascal_triangle_vuong(n)
pascal_triangle_deu(n)

n = int(input("Nhập số dòng của tam giác Pascal: "))

print("\nTam giác Pascal kiểu vuông cân:")
for i in range(n + 1):
    c = 1
    for j in range(i + 1):
        print(c, end=" ")
        c = c * (i - j) // (j + 1)
    print()

print("\nTam giác Pascal kiểu đều:")
for i in range(n + 1):
    print(" " * (n - i), end="")  # canh lề
    c = 1
    for j in range(i + 1):
        print(c, end=" ")
        c = c * (i - j) // (j + 1)
    print()

#bài 24 
def generate_and_print_pascals_triangle(n):
    """Generates and prints Pascal's triangle up to n rows."""
    triangle = [[1] * (i + 1) for i in range(n)]
    for i in range(2, n):
        for j in range(1, i):
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j]

    print("Tam giác Pascal 'vuông cân':")
    for row in triangle:
        print(*row)

    print("\nTam giác Pascal 'đều':")
    max_width = len(' '.join(map(str, triangle[-1])))
    for row in triangle:
        print(' '.join(map(str, row)).center(max_width))

# Get input from the user
n = int(input("Nhập vào giá trị n: "))
generate_and_print_pascals_triangle(n + 1)

def pascal_triangle(n):
    triangle = []
    for i in range(n):
        row = [1]
        if triangle:
            last_row = triangle[-1]
            for j in range(1, i):
                row.append(last_row[j-1] + last_row[j])
            row.append(1)
        triangle.append(row)
    return triangle
def print_pyramid(triangle):
    n = len(triangle)
    for i, row in enumerate(triangle):
        print(" " * (n - i), end="")
        print(" ".join(map(str, row)))
def print_rectangle(triangle):
    for row in triangle:
        print(" ".join(map(str, row)))
n = int(input("Nhập số hàng tam giác Pascal: "))
triangle = pascal_triangle(n)
print("\nTam giác Pascal đều:")
print_pyramid(triangle)
print("\nTam giác Pascal vuông:")
print_rectangle(triangle)

def pascal_triangle(n):
    triangle = []
    for i in range(n + 1):
        row = [1]
        for j in range(1, i + 1):
            val = row[-1] * (i - j + 1) // j
            row.append(val)
        triangle.append(row)
    return triangle

# Nhập n từ bàn phím
n = int(input("Nhập n (số nguyên dương): "))
triangle = pascal_triangle(n)

# In tam giác Pascal "vuông cân"
print("\nTam giác Pascal (vuông cân):")
for row in triangle:
    print(' '.join(map(str, row)))

# In tam giác Pascal "đều"
print("\nTam giác Pascal (đều):")
width = len(' '.join(map(str, triangle[-1])))
for row in triangle:
    line = ' '.join(map(str, row))
    print(line.center(width))

#bai 24
import matplotlib.pyplot as plt
import math

n = int(input("Nhập số hàng của tam giác Pascal: "))

scale = 0.1
for i in range(n):
    for j in range(i + 1):
        x = (j - i / 2) * scale
        y = -i * scale 
        c = math.comb(i, j)
        plt.text(x, y, str(c), ha='center', fontsize=15)

plt.axis('off')
plt.title("Tam giác Pascal")
# plt.show()

#bài 24
def C(n, k):
    from math import comb  # Python 3.8+ có sẵn comb
    return comb(n, k)

n = int(input("Nhập số dòng: "))

print("\nTam giác Pascal dạng vuông:")
for i in range(n + 1):
    for j in range(i + 1):
        print(C(i, j), end=' ')
    print()

print("\nTam giác Pascal dạng đều:")
for i in range(n + 1):
    print(" " * (n - i), end='')
    for j in range(i + 1):
        print(C(i, j), end=' ')
    print()