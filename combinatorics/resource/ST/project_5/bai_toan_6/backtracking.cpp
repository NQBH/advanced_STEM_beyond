Tree Edit Distance bang Backtracking (C++)}]
#include <iostream>               // Thu vien nhap xuat
#include <vector>                 // Dung vector de luu cac con cua cay
#include <string>                 // Xu ly chuoi
#include <algorithm>              // Dung ham min
using namespace std;

// Dinh nghia mot nut cay
struct TreeNode {
    string label;                 // Nhan cua nut
    vector<TreeNode*> children;  // Danh sach con
    TreeNode(string l) : label(l) {}  // Ham tao khoi tao nhan
};

// Ham tinh khoang cach giua hai cay
int treeEditDistance(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return 0;     // Ca hai cay rong -> khoang cach = 0
    if (!t1) {                    // Neu t1 rong -> chen tat ca nut cua t2
        int cost = 1;            // Chen nut goc
        for (auto c : t2->children)
            cost += treeEditDistance(nullptr, c); // De quy chen con
        return cost;
    }
    if (!t2) {                    // Neu t2 rong -> xoa tat ca nut cua t1
        int cost = 1;            // Xoa nut goc
        for (auto c : t1->children)
            cost += treeEditDistance(c, nullptr); // De quy xoa con
        return cost;
    }

    // Chi phi doi nhan (neu khac nhau)
    int cost = (t1->label == t2->label) ? 0 : 1;

    int m = t1->children.size(), n = t2->children.size(); // So con
    int min_cost = INT32_MAX;     // Dat chi phi ban dau vo cung

    // De quy ghep cac nut con
    function<void(int,int,int)> dfs = [&](int i, int j, int acc) {
        if (i == m && j == n) {   // Neu da ghep het ca hai danh sach con
            min_cost = min(min_cost, acc); // Cap nhat ket qua nho nhat
            return;
        }
        if (i < m && j < n)
            // Ghep con thu i cua t1 voi con thu j cua t2
            dfs(i+1, j+1, acc + treeEditDistance(t1->children[i], t2->children[j]));
        if (i < m)
            // Xoa con thu i cua t1
            dfs(i+1, j, acc + treeEditDistance(t1->children[i], nullptr));
        if (j < n)
            // Chen con thu j cua t2
            dfs(i, j+1, acc + treeEditDistance(nullptr, t2->children[j]));
    };
    dfs(0, 0, 0); // Bat dau ghep tu dau danh sach con

    return cost + min_cost; // Tong chi phi = chi phi doi nhan + ghep con
}

// Ham nhap mot cay tu ban phim
TreeNode* inputTree() {
    string label;
    cout << "Nhap nhan goc: ";
    cin >> label;
    TreeNode* node = new TreeNode(label);   // Tao nut moi
    int n;
    cout << "So con cua " << label << ": ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "-- Con thu " << i+1 << " cua " << label << ":\n";
        node->children.push_back(inputTree()); // Nhap de quy con
    }
    return node;
}

// Ham main
int main() {
    cout << "Nhap cay 1:\n";
    TreeNode* t1 = inputTree();  // Nhap cay thu nhat
    cout << "Nhap cay 2:\n";
    TreeNode* t2 = inputTree();  // Nhap cay thu hai
    cout << "Edit distance: " << treeEditDistance(t1, t2) << endl; // In ket qua
    return 0;
}