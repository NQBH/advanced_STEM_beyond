def phan_hoach(arr):
    if len(arr) == 0:
        return [[]]
    if len(arr) == 1:
        return [[arr]]
    
    first = arr[0]
    rest = arr[1:]
    rest_phanhoach = phan_hoach(rest)
    ket_qua = []
    
    for p in rest_phanhoach:
        ket_qua.append(p + [[first]])
        
        for i in range(len(p)):
            new_p = [subset.copy() for subset in p]
            new_p[i] = new_p[i] + [first]
            ket_qua.append(new_p)
            
    return ket_qua

n = int(input("Nhập số phần tử n: "))
arr = list(range(1, n+1))

cac_phanhoach = phan_hoach(arr)
for i, ph in enumerate(cac_phanhoach):
    print(f"Cách {i+1}: {ph}")