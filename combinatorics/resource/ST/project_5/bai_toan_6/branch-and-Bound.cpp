#include <iostream>              // Thu vien nhap xuat
#include <vector>                // Thu vien vector
#include <string>                // Thu vien chuoi
#include <climits>              // Dung INT_MAX
#include <functional>           // Su dung std::function
using namespace std;

// Dinh nghia mot nut cay
struct TreeNode {
    string label;                     // Nhan cua nut
    vector<TreeNode*> children;      // Danh sach con
    TreeNode(string l) : label(l) {} // Ham khoi tao
};

int best_cost = INT_MAX;             // Bien toan cuc luu ket qua tot nhat

// Ham de quy tinh khoang cach giua hai cay
int treeEditDistanceBnB(TreeNode* t1, TreeNode* t2, int acc) {
    if (acc >= best_cost) return INT_MAX;  // Cat nhanh neu khong toi uu

    if (!t1 && !t2) {
        best_cost = min(best_cost, acc);   // Cap nhat ket qua tot nhat
        return 0;
    }
    if (!t1) {
        int cost = 1;
        for (auto c : t2->children)
            cost += treeEditDistanceBnB(nullptr, c, acc + 1);
        best_cost = min(best_cost, acc + cost);
        return cost;
    }
    if (!t2) {
        int cost = 1;
        for (auto c : t1->children)
            cost += treeEditDistanceBnB(c, nullptr, acc + 1);
        best_cost = min(best_cost, acc + cost);
        return cost;
    }

    int cost = (t1->label == t2->label) ? 0 : 1;
    int m = t1->children.size(), n = t2->children.size();
    int min_sub = INT_MAX;

    function<void(int, int, int)> dfs = [&](int i, int j, int sub_cost) {
        if (sub_cost >= min_sub) return;
        if (i == m && j == n) {
            min_sub = min(min_sub, sub_cost);
            return;
        }
        if (i < m && j < n)
            dfs(i + 1, j + 1, sub_cost + treeEditDistanceBnB(t1->children[i], t2->children[j], acc + cost + sub_cost));
        if (i < m)
            dfs(i + 1, j, sub_cost + treeEditDistanceBnB(t1->children[i], nullptr, acc + cost + sub_cost));
        if (j < n)
            dfs(i, j + 1, sub_cost + treeEditDistanceBnB(nullptr, t2->children[j], acc + cost + sub_cost));
    };

    dfs(0, 0, 0);
    int total = cost + min_sub;
    best_cost = min(best_cost, acc + total);
    return total;
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
        cout << "-- Con thu " << i + 1 << " cua " << label << ":\n";
        node->children.push_back(inputTree());
    }
    return node;
}

int main() {
    cout << "Nhap cay 1:\n";
    TreeNode* t1 = inputTree();
    cout << "Nhap cay 2:\n";
    TreeNode* t2 = inputTree();
    cout << "Edit distance (BnB): " << treeEditDistanceBnB(t1, t2, 0) << endl;
    return 0;
}