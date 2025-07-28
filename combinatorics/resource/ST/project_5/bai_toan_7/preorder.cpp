#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Dinh nghia mot nut cay
struct TreeNode {
    string label;                       // Nhan cua nut
    vector<TreeNode*> children;        // Danh sach con
    TreeNode(string l) : label(l) {}   // Ham tao
};

// Ham duyet tien tu
void preorderTraversal(TreeNode* node) {
    if (!node) return;
    cout << node->label << endl;       // B1: Xuat nhan cua nut
    for (TreeNode* child : node->children)
        preorderTraversal(child);      // B2: De quy duyet cac nut con
}

// Ham nhap cay tu ban phim
TreeNode* inputTree() {
    string label;
    cout << "Nhap nhan nut: ";
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

// Ham main
int main() {
    cout << "Nhap cay:\n";
    TreeNode* root = inputTree();
    cout << "Duyet tien tu:\n";
    preorderTraversal(root);
    return 0;
}