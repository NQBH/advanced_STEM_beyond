def perfect_matchings(p, q):
    # p, q: kich thuoc hai tap dinh
    # used: danh dau dinh trong V2 da ghep
    # current: danh sach cac cap trong ghep cap
    if p != q:
        return []
    result = []
    
    def backtrack(used, current):
        if len(current) == p:
            result.append(current[:])
            return
        for i in range(q):
            if not used[i]:
                used[i] = True
                current.append((len(current), i))
                backtrack(used, current)
                current.pop()
                used[i] = False
    
    backtrack([False] * q, [])
    return result

# Vi du su dung
if __name__ == "__main__":
    matchings = perfect_matchings(2, 2)
    print("Perfect matchings in K_2,2:", matchings)