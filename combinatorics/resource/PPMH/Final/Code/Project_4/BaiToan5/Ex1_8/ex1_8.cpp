#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct TreeNode {
    int id;
    vector<TreeNode*> children;

    TreeNode(int id) : id(id) {}
};

TreeNode* generateRandomTree(int n) {
    if (n <= 0) return nullptr;

    vector<TreeNode*> nodes;
    nodes.push_back(new TreeNode(1));  

    for (int i = 2; i <= n; ++i) {
        TreeNode* newNode = new TreeNode(i);
        TreeNode* parent = nodes[rand() % nodes.size()];
        parent->children.push_back(newNode);
        nodes.push_back(newNode);
    }

    return nodes[0]; 
}

void printTree(TreeNode* node, int level = 0) {
    if (!node) return;
    for (int i = 0; i < level; ++i) cout << "  ";
    cout << "Node " << node->id << endl;
    for (auto child : node->children)
        printTree(child, level + 1);
}

int main() {
    srand(time(0));
    int n;
    cout << "Nhập số nút n: ";
    cin >> n;

    TreeNode* root = generateRandomTree(n);
    cout << "\nCây ngẫu nhiên được sinh:\n";
    printTree(root);
    return 0;
}