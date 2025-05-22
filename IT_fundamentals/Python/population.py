print("Bài 12")
P0, r, n = map(float, input("Nhập P0, r, n: ").split())
P = float(input("Nhập ngưỡng dân số P: "))
Pn = P0 * (1 + r)**n
print(f"Dân số sau {int(n)} năm {Pn:.2f}")
print("Dân số từng năm: ")
for year in range(int(n) + 1):
  current_pop = P0 * (1 + r)**year
  print(f"Năm {year}: {current_pop:.2f}")
year = 0
current = P0
while current < P:
  current *= (1 + r)
  year += 1
print(f"Số năm để đạt {P:.2f}: {year} năm" )

# Nhập dân số ban đầu P0, tỉ lệ tăng r, và số năm n
P0, r, n = map(float, input("Nhập dân số ban đầu, tỉ lệ tăng, và số năm (cách nhau bởi dấu cách): ").split())
P = float(input("Nhập ngưỡng dân số cần đạt: "))

# Tính dân số từng năm từ năm 0 đến năm n
print("Dân số từng năm:")
for i in range(0, int(n)+1):  # Duyệt từ năm 0 đến năm n
    Pn = P0 * (1 + r) ** i   # Công thức tính dân số năm thứ i
    print(f"Năm {i}: {Pn:.2f}")

# Tìm số năm ít nhất để dân số đạt hoặc vượt ngưỡng P
so_nam = 0
dan_so_hien_tai = P0

while dan_so_hien_tai < P:
    dan_so_hien_tai = dan_so_hien_tai * (1 + r)
    so_nam += 1

print(f"Số năm ít nhất để đạt hoặc vượt ngưỡng: {so_nam}")

P0, r, n = input("Nhập P0, r, n cách nhau bằng dấu cách: ").split()
P0 = float(P0)
r = float(r)
n = int(n)
P = float(input("Nhập ngưỡng dân số cần đạt: "))
population_list = []
for i in range(n + 1):
    Pi = P0 * ((1 + r) ** i)
    population_list.append(Pi)
Pn = population_list[-1]
years_to_reach_P = 0
current_population = P0
while current_population < P:
    current_population *= (1 + r)
    years_to_reach_P += 1
print(f"{Pn:.2f}")
print(" ".join(f"{p:.2f}" for p in population_list)) 
print(years_to_reach_P)

# Nhập dữ liệu
P0, r, n = map(float, input().split())
n = int(n)
P_target = float(input())

# 1. Dùng while True để tính Pn
count = 0
pop = P0
while True:
    if count == n:
        break
    pop *= (1 + r)
    count += 1
Pn = pop
print(f"{Pn:.2f}")

# 2. In dãy dân số từ P0 đến Pn
print(f"{P0:.2f}", end=" ")
pop = P0
count = 0
while True:
    if count == n:
        break
    pop *= (1 + r)
    print(f"{pop:.2f}", end=" ")
    count += 1
print()

# 3. Tìm số năm ít nhất để đạt P_target
year = 0
pop = P0
while True:
    if pop >= P_target:
        break
    pop *= (1 + r)
    year += 1
print(year)

# Nhập dữ liệu từ dòng 1
P0, r, n = map(float, input().split())

# Nhập dữ liệu từ dòng 2
P = float(input())

# Tính dân số từng năm (từ P0 đến Pn)
populations = [P0]
for i in range(int(n)):
    next_pop = populations[-1] * (1 + r)
    populations.append(next_pop)

# In dân số sau n năm
print(f"{populations[-1]:.2f}")

# In dãy dân số từ P0 -> Pn
print(" ".join(f"{pop:.2f}" for pop in populations))

# Tìm số năm ít nhất để đạt dân số P
years = 0
current = P0
while current < P:
    current *= (1 + r)
    years += 1

# In số năm cần để đạt P
print(years)

P0, r, n = map(float, input().split())
n = int(n)
target = float(input())

population_list = [P0]
for _ in range(n):
    population_list.append(population_list[-1] * (1 + r))

print(f"\nDân số sau {n} năm là: {population_list[-1]:.2f}")
print("Dân số qua từng năm:")
for p in population_list:
    print(f"{p:.2f}", end=' ')
print()

years_needed = 0
current_pop = P0
while current_pop < target:
    current_pop *= (1 + r)
    years_needed += 1

print(f"Số năm cần để đạt ít nhất {target}: {years_needed}")

# Nhập từ bàn phím
P0, r, n = map(float, input("Nhập P0, r, n (cách nhau bằng dấu cách): ").split())
n = int(n)  # Đảm bảo n là số nguyên
P = float(input("Nhập dân số cần đạt P: "))

# Tính dân số sau n năm
populations = [P0]
for i in range(n):
    next_year = populations[-1] * (1 + r)
    populations.append(next_year)

# In dân số sau n năm
print(f"\nDân số sau {n} năm (Pn): {populations[-1]:.2f}")

# In dãy dân số từ P0 đến Pn
print("Dãy dân số từng năm:")
print(" ".join(f"{p:.2f}" for p in populations))

# Tính số năm ít nhất để đạt dân số ≥ P
count = 0
current = P0
while current < P:
    current *= (1 + r)
    count += 1

print(f"Số năm ít nhất để dân số đạt hoặc vượt {P}: {count}")

P0, r, n = map(float, input("Nhập dân số ban đầu, tỷ lệ tăng r và số năm n (cách nhau bằng dấu cách): ").split())
n = int(n)
target = float(input("Nhập dân số cần đạt tới: "))
population_list = [P0]
for _ in range(n):
    population_list.append(population_list[-1] * (1 + r))
print(f"\n Dân số sau {n} năm là: {population_list[-1]:.2f}")
print("\n Dân số qua từng năm:")
for year, p in enumerate(population_list):
    print(f"Năm {year}: {p:.2f}")
current_pop = P0
years_needed = 0
while current_pop < target:
    current_pop *= (1 + r)
    years_needed += 1
print(f"\n Số năm ít nhất để dân số đạt tới {target:.0f}: {years_needed}")

P0, r, n = map(float, input(" P0, r, n: ").split())
P = float(input("Nhap nguong dan so: "))
Pn = P0 * (1 + r)**n
print(f"Dan so sau {int(n)} năm {Pn:.2f}")
print("Dan so tung nam: ")
for year in range(int(n) + 1):
  current_pop = P0 * (1 + r)**year
  print(f"nam {year}: {current_pop:.2f}")
year = 0
current = P0
while current < P:
  current *= (1 + r)
  year += 1
print(f"so nam de dat {P:.2f}: {year} nam" )

# Nhap du lieu
P0, r, n = map(float, input().split())
n = int(n)
P_target = float(input())

# 1. Dung while True de tinh Pn
count = 0
pop = P0
while True:
    if count == n:
        break
    pop *= (1 + r)
    count += 1
Pn = pop
print(f"{Pn:.2f}")

# 2. In day so tu  P0 đến Pn
print(f"{P0:.2f}", end=" ")
pop = P0
count = 0
while True:
    if count == n:
        break
    pop *= (1 + r)
    print(f"{pop:.2f}", end=" ")
    count += 1
print()

# 3. tim so nam it nhat de dat P_target
year = 0
pop = P0
while True:
    if pop >= P_target:
        break
    pop *= (1 + r)
    year += 1
print(year)

# bài 12:
p0, r, n = input("Nhập dân số ban đầu, tỷ lệ tăng trưởng và số năm : ").split()
p0 = float(p0)
r = float(r)
n = int(n)
nguong = float(input("Nhập ngưỡng dân số cần đạt: "))
print("Dân số từng năm:")
dan_so = p0
for i in range(int(n) + 1):
    print(f"Năm {i}: {dan_so:.2f}")
    dan_so = dan_so * (1 + r)
dan_so = p0
so_nam = 0
while dan_so < nguong:
    dan_so *= (1 + r)
    so_nam += 1
print(f"Số năm cần để dân số vượt {nguong}: {so_nam} năm")

import math
Po,r,n= map(float,input().split())
P=float(input())
Pn=Po*(1+r)**n
ds_tang=[Po*(1+r)**i for i in range(int(n)+1)]
print(f"{Pn:.2f}")
print(f"{ds_tang}")
print(math.ceil(math.log(P/Po)/math.log(1+r)))

P0,r,n = map(float, input().split())
r = float(r)
n=int(n)
P = int(input())
count=0
while P0<P:
    P0 = P0 * (1 + r)
    print(int(P0))
    count+=1  
print(count)

#Ex 12:
P0, r, n = map(float, input().split())
P = float(input())

pop = P0
for _ in range(int(n)):
    pop *= (1 + r)
print(f"{pop:.2f}")

pop = P0
for _ in range(int(n) + 1):
    print(f"{pop:.2f}", end=" ")
    pop *= (1 + r)
print()

pop, year = P0, 0
while pop < P:
    pop *= (1 + r)
    year += 1
print(year)