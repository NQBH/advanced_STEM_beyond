#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Dinh nghia cau truc nut
struct TreeNode {
    string label;                         // Nhan cua nut
    vector<TreeNode*> children;          // Danh sach con
    TreeNode(string l) : label(l) {}
};

// Duyet bottom-up bang de quy
void bottomupTraversal(TreeNode* node) {
    if (!node) return;
    for (TreeNode* child : node->children)
        bottomupTraversal(child);        // Duyet con truoc
    cout << node->label << endl;         // In nut sau
}

// Nhap cay tu ban phim
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
    cout << "Duyet bottom-up:\n";
    bottomupTraversal(root);
    return 0;
}