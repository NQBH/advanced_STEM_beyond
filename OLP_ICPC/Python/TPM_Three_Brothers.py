a1 = [1, 2, 3]
a = list(map(int, input().split()))
thieu = list(set(a1) ^ set(a))
print(thieu[0])
