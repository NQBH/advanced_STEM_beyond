#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct NodeInfo {
    int u;      // đỉnh
    int depth;  // độ sâu
    int height; // chiều cao
    NodeInfo(int u, int depth, int height) : u(u), depth(depth), height(height) {}
};

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

// Tính chiều cao và độ sâu cho từng đỉnh
void dfs_height(int u, const vector<vector<int>> &tree, int depth, vector<int> &depths, vector<int> &heights) {
    depths[u] = depth;
    int max_child_height = -1;
    for (int v : tree[u]) {
        dfs_height(v, tree, depth + 1, depths, heights);
        max_child_height = max(max_child_height, heights[v]);
    }
    heights[u] = max_child_height + 1;
}

// Duyệt bottom-up: in các đỉnh theo thứ tự không giảm của chiều cao,
// cùng chiều cao thì theo thứ tự không giảm của độ sâu, cùng chiều cao và độ sâu thì trái sang phải
void bottom_up(const vector<vector<int>> &tree, int root, int n) {
    vector<int> depths(n + 1), heights(n + 1);
    dfs_height(root, tree, 0, depths, heights);
    vector<NodeInfo> nodes;
    for (int u = 1; u <= n; ++u) {
        nodes.emplace_back(u, depths[u], heights[u]);
    }
    // Sắp xếp theo height tăng dần, depth tăng dần, u tăng dần
    sort(nodes.begin(), nodes.end(), [](const NodeInfo &a, const NodeInfo &b) {
        if (a.height != b.height) return a.height < b.height;
        if (a.depth != b.depth) return a.depth < b.depth;
        return a.u < b.u;
    });
    cout << "Duyet bottom-up (cac dinh theo thu tu khong giam cua chieu cao, cung chieu cao thi theo do sau, trai sang phai):\n";
    int last_height = -1;
    for (const auto &info : nodes) {
        if (info.height != last_height) {
            if (last_height != -1) cout << '\n';
            cout << "Chieu cao " << info.height << ": ";
            last_height = info.height;
        }
        cout << info.u << ' ';
    }
    cout << '\n';
}

int main() {
    int n, root;
    vector<vector<int>> tree;
    read_tree(n, tree, root);
    bottom_up(tree, root, n);
    return 0;
}
