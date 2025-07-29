#include <bits/stdc++.h>
using namespace std;

// Xay dung cay tu mang cha
pair<unordered_map<int, vector<int>>, int> build_tree_from_parents(const vector<int>& parents) {
    unordered_map<int, vector<int>> tree;
    int root = -1;
    for (int child = 0; child < (int)parents.size(); child++) {
        int parent = parents[child];
        if (parent == -1) {
            root = child;
        } else {
            tree[parent].push_back(child);
        }
    }
    return {tree, root};
}

// Duyet tien thu tu (preorder)
void preorder(unordered_map<int, vector<int>>& tree, int node) {
    cout << node << " "; // Xu ly nut hien tai truoc
    for (int child : tree[node]) {
        preorder(tree, child);
    }
}

// Duyet hau thu tu (postorder)
void postorder(unordered_map<int, vector<int>>& tree, int node) {
    for (int child : tree[node]) {
        postorder(tree, child);
    }
    cout << node << " "; // Xu ly nut hien tai sau
}

// Duyet top-down (BFS)
void top_down(unordered_map<int, vector<int>>& tree, int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int child : tree[node]) {
            q.push(child);
        }
    }
}

// Duyet bottom-up
void bottom_up(unordered_map<int, vector<int>>& tree, int root) {
    unordered_map<int, vector<int>> levels;
    queue<pair<int, int>> q;
    q.push({root, 0});
    int max_level = 0;

    // BFS de xac dinh cac muc (level)
    while (!q.empty()) {
        auto [node, level] = q.front();
        q.pop();
        levels[level].push_back(node);
        max_level = max(max_level, level);
        for (int child : tree[node]) {
            q.push({child, level + 1});
        }
    }

    // Duyet tu muc thap nhat len muc cao nhat
    for (int level = max_level; level >= 0; level--) {
        for (int node : levels[level]) {
            cout << node << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Nhap mang cha (-1 cho root):\n";
    vector<int> parents;
    int x;
    while (cin.peek() != '\n' && cin >> x) {
        parents.push_back(x);
    }

    auto [tree, root] = build_tree_from_parents(parents);

    cout << "Duyet preorder:\n";
    preorder(tree, root);

    cout << "\nDuyet postorder:\n";
    postorder(tree, root);

    cout << "\nDuyet top-down:\n";
    top_down(tree, root);

    cout << "\nDuyet bottom-up:\n";
    bottom_up(tree, root);

    return 0;
}