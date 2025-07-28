#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int n;
    vector<vector<bool>> adj_matrix;

public:
    Graph(int size) {
        n = size;
        adj_matrix = vector<vector<bool>>(n, vector<bool>(n, false));
    }

    void add_edge(int v, int w) {
        adj_matrix[v][w] = true;
    }

    void del_edge(int v, int w) {
        adj_matrix[v][w] = false;
    }

    vector<pair<int, int>> edges() {
        vector<pair<int, int>> result;
        for (int v = 0; v < n; ++v)
            for (int w = 0; w < n; ++w)
                if (adj_matrix[v][w])
                    result.push_back({v, w});
        return result;
    }

    vector<int> incoming(int v) {
        vector<int> result;
        for (int u = 0; u < n; ++u)
            if (adj_matrix[u][v])
                result.push_back(u);
        return result;
    }

    vector<int> outgoing(int v) {
        vector<int> result;
        for (int w = 0; w < n; ++w)
            if (adj_matrix[v][w])
                result.push_back(w);
        return result;
    }

    int source(int v, int w) {
        return adj_matrix[v][w] ? v : -1;
    }

    int target(int v, int w) {
        return adj_matrix[v][w] ? w : -1;
    }
};

int main() {
    int n, m;
    cout << "Nhập số lượng đỉnh: ";
    cin >> n;
    Graph g(n);

    cout << "Nhập số lượng cạnh: ";
    cin >> m;
    cout << "Nhập các cạnh (u v):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v);
    }

    while (true) {
        cout << "\nChọn thao tác:\n";
        cout << "1. Thêm cạnh\n2. Xóa cạnh\n3. In danh sách cạnh\n";
        cout << "4. Incoming(v)\n5. Outgoing(v)\n6. Source(v,w)\n7. Target(v,w)\n0. Thoát\n";
        cout << "Lựa chọn: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            int u, v;
            cout << "Nhập cạnh (u v): ";
            cin >> u >> v;
            g.add_edge(u, v);
        } else if (choice == 2) {
            int u, v;
            cout << "Nhập cạnh cần xóa (u v): ";
            cin >> u >> v;
            g.del_edge(u, v);
        } else if (choice == 3) {
            auto es = g.edges();
            cout << "Danh sách cạnh:\n";
            for (auto [u, v] : es)
                cout << u << " -> " << v << '\n';
        } else if (choice == 4) {
            int v;
            cout << "Nhập đỉnh v: ";
            cin >> v;
            auto inc = g.incoming(v);
            cout << "Incoming to " << v << ": ";
            for (int u : inc) cout << u << " ";
            cout << '\n';
        } else if (choice == 5) {
            int v;
            cout << "Nhập đỉnh v: ";
            cin >> v;
            auto out = g.outgoing(v);
            cout << "Outgoing from " << v << ": ";
            for (int w : out) cout << w << " ";
            cout << '\n';
        } else if (choice == 6) {
            int v, w;
            cout << "Nhập v w: ";
            cin >> v >> w;
            int s = g.source(v, w);
            if (s == -1) cout << "Không tồn tại cạnh\n";
            else cout << "Source: " << s << '\n';
        } else if (choice == 7) {
            int v, w;
            cout << "Nhập v w: ";
            cin >> v >> w;
            int t = g.target(v, w);
            if (t == -1) cout << "Không tồn tại cạnh\n";
            else cout << "Target: " << t << '\n';
        } else if (choice == 0) break;
        else cout << "Lựa chọn không hợp lệ!\n";
    }

    return 0;
}