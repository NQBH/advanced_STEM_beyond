#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Đọc cây từ input dạng danh sách cha-con
void read_tree(int &n, vector<vector<int>> &tree, int &root) {
    cout << "Nhap so dinh n: ";
    cin >> n;
    tree.assign(n + 1, vector<int>());
    vector<bool> is_child(n + 1, false);
    cout << "Nhap " << n << " dong, moi dong: u k v1 v2 ... vk (dinh u co k con):\n";
    for (int i = 1; i <= n; ++i) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; ++j) {
            int v; cin >> v;
            tree[u].push_back(v);
            is_child[v] = true;
        }
    }
    // Tìm gốc (đỉnh không là con của ai)
    root = 1;
    for (int i = 1; i <= n; ++i) if (!is_child[i]) root = i;
}

// Duyệt top-down thực sự: in các đỉnh theo từng mức (level-order/BFS)
void top_down(const vector<vector<int>> &tree, int root) {
    queue<pair<int, int>> q; // (đỉnh, độ sâu)
    q.push({root, 0});
    int current_depth = 0;
    vector<int> level_nodes;
    cout << "Duyet top-down (cac dinh theo thu tu khong giam cua do sau, trai sang phai):\n";
    while (!q.empty()) {
        int sz = q.size();
        level_nodes.clear();
        for (int i = 0; i < sz; ++i) {
            auto [u, depth] = q.front(); q.pop();
            level_nodes.push_back(u);
            for (int v : tree[u]) q.push({v, depth + 1});
        }
        cout << "Do sau " << current_depth << ": ";
        for (int u : level_nodes) cout << u << ' ';
        cout << '\n';
        current_depth++;
    }
}

int main() {
    int n, root;
    vector<vector<int>> tree;
    read_tree(n, tree, root);
    top_down(tree, root);
    return 0;
}
