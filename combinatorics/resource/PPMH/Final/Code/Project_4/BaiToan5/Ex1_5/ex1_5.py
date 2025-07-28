class Graph:
    def __init__(self, n):
        self.n = n
        self.adj_matrix = [[False] * n for _ in range(n)]

    def add_edge(self, v, w):
        self.adj_matrix[v][w] = True

    def del_edge(self, v, w):
        self.adj_matrix[v][w] = False

    def edges(self):
        return [(v, w) for v in range(self.n) for w in range(self.n) if self.adj_matrix[v][w]]

    def incoming(self, v):
        return [u for u in range(self.n) if self.adj_matrix[u][v]]

    def outgoing(self, v):
        return [w for w in range(self.n) if self.adj_matrix[v][w]]

    def source(self, v, w):
        return v if self.adj_matrix[v][w] else None

    def target(self, v, w):
        return w if self.adj_matrix[v][w] else None


def main():
    n = int(input("Nhập số lượng đỉnh: "))
    g = Graph(n)

    m = int(input("Nhập số lượng cạnh: "))
    print("Nhập các cạnh theo định dạng: u v (đỉnh nguồn → đỉnh đích)")
    for _ in range(m):
        u, v = map(int, input().split())
        g.add_edge(u, v)

    while True:
        print("\nChọn thao tác:")
        print("1. Thêm cạnh")
        print("2. Xóa cạnh")
        print("3. In danh sách cạnh")
        print("4. Incoming(v)")
        print("5. Outgoing(v)")
        print("6. Source(v, w)")
        print("7. Target(v, w)")
        print("0. Thoát")
        choice = input("Lựa chọn: ")

        if choice == "1":
            u, v = map(int, input("Nhập cạnh u v: ").split())
            g.add_edge(u, v)
        elif choice == "2":
            u, v = map(int, input("Nhập cạnh cần xóa u v: ").split())
            g.del_edge(u, v)
        elif choice == "3":
            print("Các cạnh hiện có:", g.edges())
        elif choice == "4":
            v = int(input("Nhập đỉnh v: "))
            print("Incoming to", v, ":", g.incoming(v))
        elif choice == "5":
            v = int(input("Nhập đỉnh v: "))
            print("Outgoing from", v, ":", g.outgoing(v))
        elif choice == "6":
            v, w = map(int, input("Nhập v w: ").split())
            s = g.source(v, w)
            print("Source:", s if s is not None else "Không tồn tại cạnh")
        elif choice == "7":
            v, w = map(int, input("Nhập v w: ").split())
            t = g.target(v, w)
            print("Target:", t if t is not None else "Không tồn tại cạnh")
        elif choice == "0":
            break
        else:
            print("Lựa chọn không hợp lệ!")

if __name__ == "__main__":
    main()