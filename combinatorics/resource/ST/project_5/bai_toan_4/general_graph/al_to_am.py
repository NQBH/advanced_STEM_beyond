def al_to_am(adj_list):
    n = len(adj_list)
    matrix = [[0]*n for _ in range(n)]  # Khoi tao ma tran toan 0

    for u in range(n):
        for v in adj_list[u]:
            matrix[u][v] = 1  # Danh dau canh u -> v

    return matrix

# Nhap tu ban phim
n = int(input("Nhap so dinh: "))
adj_list = []
print("Nhap danh sach ke (AL):")
for i in range(n):
    row = list(map(int, input(f"{i}: ").split()))
    adj_list.append(row)

am = al_to_am(adj_list)

print("Ma tran ke (AM):")
for row in am:
    print(' '.join(map(str, row)))