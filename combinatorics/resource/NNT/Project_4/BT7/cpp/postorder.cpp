#include <iostream>
#include <vector>
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

// Duyệt postorder
void postorder(int u, const vector<vector<int>> &tree) {
    // Duyệt tất cả các con trước
    for (int v : tree[u]) postorder(v, tree);
    // Sau khi duyệt xong các con, thăm u
    cout << u << ' ';
}

int main() {
    int n, root;
    vector<vector<int>> tree;
    read_tree(n, tree, root);
    cout << "Thu tu duyet postorder: ";
    postorder(root, tree);
    cout << '\n';
    return 0;
}
