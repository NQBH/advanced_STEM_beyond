'''
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
'''

def tong_uoc(a):
    tong = 0
    for i in range(1, int(a ** 0.5) + 1):
        if a % i == 0:
            tong += i
            if i != a // i:
                tong += a // i
    return tong
n = int(input())
numbers = [int(input()) for _ in range(n)]

gan_hoan_hao = []

for a in numbers:
    tong = tong_uoc(a)
    if 2 * a <= tong:
        gan_hoan_hao.append(a)

# Output
print(len(gan_hoan_hao))
for num in gan_hoan_hao:
    print(num)
'''
#16
x=0
count = 0
n = int(input())
ketqua = []
for i in range(n):
  n = int(input())
  x = 0
  for i in range(1, n):
    if n % i == 0:
      x += i
  if x == n - 1:
    ketqua.append(n)
    count += 1
print(count)
for i in ketqua:
  print(i)
'''