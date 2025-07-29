#include <bits/stdc++.h>
using namespace std;

// Ham chuyen tu danh sach canh sang array-of-parents va FCNS
tuple<vector<int>, vector<int>, vector<int>> edge_list_to_parents_and_fcns(
    const vector<pair<int,int>>& edges, int n, int root) {

    // 1. Xay dung danh sach children cho moi nut
    vector<vector<int>> children(n);
    vector<int> parents(n, -1); // Khoi tao tat ca cha = -1

    for (auto [u, v] : edges) {
        children[u].push_back(v);
        parents[v] = u; // Gan cha cua v la u
    }

    parents[root] = -1; // Nut goc khong co cha

    // 2. Khoi tao 2 mang FCNS
    vector<int> first_child(n, -1);
    vector<int> next_sibling(n, -1);

    // 3. Xay dung mang first_child va next_sibling
    for (int u = 0; u < n; u++) {
        if (!children[u].empty()) {
            // Con dau tien cua u
            first_child[u] = children[u][0];
            // Lien ket cac anh em
            for (int i = 0; i + 1 < (int)children[u].size(); i++) {
                int curr = children[u][i];
                int nxt = children[u][i + 1];
                next_sibling[curr] = nxt;
            }
        }
    }

    return {parents, first_child, next_sibling};
}

int main() {
    // Danh sach canh (edge list)
    vector<pair<int,int>> edges = {
        {0, 1},
        {1, 3},
        {3, 6},
        {3, 7},
        {1, 4},
        {1, 5},
        {0, 2}
    };
    int n = 8;
    int root = 0;

    // Goi ham chuyen doi
    auto [parents, first_child, next_sibling] = edge_list_to_parents_and_fcns(edges, n, root);

    // In ket qua
    cout << "Parents array:\n";
    for (int x : parents) cout << x << " ";
    cout << "\n\nFirst-Child array:\n";
    for (int x : first_child) cout << x << " ";
    cout << "\n\nNext-Sibling array:\n";
    for (int x : next_sibling) cout << x << " ";
    cout << "\n";

    return 0;
}