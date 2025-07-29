#include <bits/stdc++.h>
using namespace std;

// Hàm chuyển từ biểu diễn First-Child Next-Sibling (FCNS)
// sang mảng cha (parents array) và danh sách cạnh (tree_edges)
pair<vector<int>, vector<pair<int,int>>>
fcns_to_parents_and_tree_edges(int root,
                               const vector<int>& first_child,
                               const vector<int>& next_sibling) {
    int n = first_child.size();
    vector<int> parents(n, -1);                 // Mảng cha, mặc định -1
    vector<pair<int,int>> tree_edges;           // Danh sách cạnh (u, v)

    // Hàm đệ quy duyệt cây từ nút root
    function<void(int)> traverse = [&](int node) {
        int child = first_child[node];          // Lấy con đầu tiên của node
        while (child != -1) {                   // Duyệt lần lượt các con và anh em
            parents[child] = node;              // Gán cha của node con
            tree_edges.push_back({node, child}); // Lưu cạnh (node -> child)
            traverse(child);                    // Gọi đệ quy cho node con
            child = next_sibling[child];        // Sang anh em tiếp theo của child
        }
    };

    traverse(root); // Bắt đầu từ gốc
    return {parents, tree_edges};
}

int main() {
    // Dữ liệu ví dụ
    vector<int> first_child = {1, 3, -1, 6, -1, -1, -1, -1};
    vector<int> next_sibling = {-1, 2, -1, 4, 5, -1, 7, -1};
    int root = 0;

    // Gọi hàm để chuyển đổi từ FCNS sang parents + edge list
    auto [parents, edge_list] = fcns_to_parents_and_tree_edges(root, first_child, next_sibling);

    // In kết quả
    cout << "\nArray of parents:\n";
    for (int p : parents) cout << p << " ";
    cout << "\n\nEdge List:\n";
    for (auto [u, v] : edge_list) {
        cout << u << " -> " << v << "\n";
    }

    return 0;
}
