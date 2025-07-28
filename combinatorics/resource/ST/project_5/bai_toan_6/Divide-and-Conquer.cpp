#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Dinh nghia mot nut cay
struct TreeNode {
    string label;
    vector<TreeNode*> children;
    TreeNode(string l) : label(l) {}
};

// Ham chia de tri
int treeEditDistanceDNC(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return 0;
    if (!t1) {
        int cost = 1;
        for (auto c : t2->children)
            cost += treeEditDistanceDNC(nullptr, c);
        return cost;
    }
    if (!t2) {
        int cost = 1;
        for (auto c : t1->children)
            cost += treeEditDistanceDNC(c, nullptr);
        return cost;
    }

    int cost = (t1->label == t2->label) ? 0 : 1;
    int m = t1->children.size();
    int n = t2->children.size();

    // De quy ghep con
    function<int(int,int)> dfs = [&](int i, int j) -> int {
        if (i == m && j == n) return 0;
        int res = INT_MAX;
        if (i < m && j < n)
            res = min(res, treeEditDistanceDNC(t1->children[i], t2->children[j]) + dfs(i+1, j+1));
        if (i < m)
            res = min(res, treeEditDistanceDNC(t1->children[i], nullptr) + dfs(i+1, j));
        if (j < n)
            res = min(res, treeEditDistanceDNC(nullptr, t2->children[j]) + dfs(i, j+1));
        return res;
    };

    return cost + dfs(0, 0);
}

// Ham nhap cay tu ban phim
TreeNode* inputTree() {
    string label;
    cout << "Nhap nhan goc: ";
    cin >> label;
    TreeNode* node = new TreeNode(label);
    int n;
    cout << "So con cua " << label << ": ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "-- Con thu " << i+1 << " cua " << label << ":\n";
        node->children.push_back(inputTree());
    }
    return node;
}

int main() {
    cout << "Nhap cay 1:\n";
    TreeNode* t1 = inputTree();
    cout << "Nhap cay 2:\n";
    TreeNode* t2 = inputTree();
    cout << "Edit distance (D&C): " << treeEditDistanceDNC(t1, t2) << endl;
    return 0;
}