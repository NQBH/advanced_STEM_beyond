#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// Dinh nghia mot nut cay
struct TreeNode {
    string label;                         // Nhan cua nut
    vector<TreeNode*> children;          // Danh sach cac nut con
    TreeNode(string l) : label(l) {}     // Ham tao
};

// Ham duyet top-down bang hang doi
void topdownTraversal(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);                        // Dua nut goc vao hang doi
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();     // Lay nut dau hang doi
        cout << node->label << endl;             // In ra nhan
        for (TreeNode* child : node->children)
            q.push(child);                       // Dua con vao hang doi
    }
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
    cout << "Duyet top-down:\n";
    topdownTraversal(root);
    return 0;
}