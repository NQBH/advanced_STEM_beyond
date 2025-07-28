#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    string label;
    vector<TreeNode*> children;
    TreeNode(string val) : label(val) {}
};

void bottom_up(TreeNode* node) {
    if (!node) return;
    for (TreeNode* child : node->children)
        bottom_up(child);
    cout << node->label << " ";
}

int main() {
    TreeNode* root = new TreeNode("A");
    TreeNode* B = new TreeNode("B");
    TreeNode* C = new TreeNode("C");
    TreeNode* D = new TreeNode("D");
    TreeNode* E = new TreeNode("E");
    TreeNode* F = new TreeNode("F");
    TreeNode* G = new TreeNode("G");
    TreeNode* H = new TreeNode("H");

    root->children = {B, C, D};
    B->children = {E, F};
    C->children = {H};
    D->children = {G};

    bottom_up(root);
}