print("Bài toán 16")
def is_nearly_perfect(n):
    if n <= 0:
        return False
    
    total = 1 + n
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            total += i
            if i != n // i:
                total += n // i
    return 2 * n <= total
n = int(input("Số lượng số cần kiểm tra: "))
numbers = [int(input(f"Nhập số thứ {i+1}: ")) for i in range(n)]
result = [num for num in numbers if is_nearly_perfect(num)]
print("Kết quả:")
print(len(result))
for num in result:
    print(num)