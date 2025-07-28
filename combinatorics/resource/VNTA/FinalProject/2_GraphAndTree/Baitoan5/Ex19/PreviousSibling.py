def previous_sibling(v, parent):
    p = parent[v]
    if p is None:
        #v là root, không có previous sibling
        return None

    #tìm danh sách con của p
    children = [u for u in range(len(parent)) if parent[u] == p]

    #tìm vị trí của v trong danh sách con
    idx = children.index(v)

    #nếu v là con đầu tiên thì không có previous sibling
    if idx == 0:
        return None

    #trả về previous sibling của v
    return children[idx - 1]


#ví dụ
if __name__ == "__main__":
    parent = [None, 0, 0, 1, 1, 2, 2]

    test_nodes = [4, 1, 6, 0]
    for v in test_nodes:
        prev = previous_sibling(v, parent)
        print(f"Previous sibling of node {v}: {prev}")
