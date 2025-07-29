#include <bits/stdc++.h>
using namespace std;

// Ham xay dung danh sach children tu mang cha
pair<int, vector<vector<int>>> build_children_list(const vector<int>& parents) {
    int n = parents.size();
    vector<vector<int>> children(n);
    int root = -1;
    for (int i = 0; i < n; i++) {
        if (parents[i] == -1) {
            root = i; // dinh goc
        } else {
            children[parents[i]].push_back(i);
        }
    }
    return {root, children};
}

// Chuyen sang bieu dien First-Child Next-Sibling
pair<vector<int>, vector<int>> fcns_representation(int root,
                                                   const vector<vector<int>>& children,
                                                   int n) {
    vector<int> first_child(n, -1);    // first_child[v]: con dau tien cua v, -1 neu khong co
    vector<int> next_sibling(n, -1);   // next_sibling[v]: anh em ke tiep cua v, -1 neu khong co

    // DFS de xay dung 2 mang
    function<void(int)> dfs = [&](int node) {
        if (children[node].empty()) return;

        // Con dau tien cua node
        first_child[node] = children[node][0];

        // Lien ket anh em ke tiep giua cac con
        for (int i = 0; i + 1 < (int)children[node].size(); i++) {
            int u = children[node][i];
            int v = children[node][i + 1];
            next_sibling[u] = v;
        }

        // De quy cho tung con
        for (int child : children[node]) {
            dfs(child);
        }
    };

    dfs(root);
    return {first_child, next_sibling};
}

// Tao danh sach canh tu 2 mang first_child va next_sibling
vector<pair<int,int>> edge_list(const vector<int>& first_child, const vector<int>& next_sibling) {
    vector<pair<int,int>> edges;
    int n = first_child.size();
    for (int i = 0; i < n; i++) {
        if (first_child[i] != -1)
            edges.push_back({i, first_child[i]});
        if (next_sibling[i] != -1)
            edges.push_back({i, next_sibling[i]});
    }
    return edges;
}

int main() {
    // Mang cha: -1 la goc
    vector<int> parents = {-1, 0, 0, 1, 1, 1, 3, 3};
    // Cay tuong ung:
    //        0
    //      /   \
    //     1     2
    //   / | \
    //  3  4  5
    // / \
    // 6 7

    int n = parents.size();

    // Buoc 1: xay dung danh sach children va tim goc
    auto [root, children] = build_children_list(parents);

    // Buoc 2: tao bieu dien First-Child Next-Sibling
    auto [first_child, next_sibling] = fcns_representation(root, children, n);

    // Buoc 3: tao danh sach canh tu hai mang
    auto edges = edge_list(first_child, next_sibling);

    // In ket qua
    cout << "First-Child array: ";
    for (int x : first_child) cout << x << " ";
    cout << "\nNext-Sibling array: ";
    for (int x : next_sibling) cout << x << " ";
    cout << "\nEdge list:\n";
    for (auto [u, v] : edges) {
        cout << u << " -> " << v << "\n";
    }

    return 0;
}