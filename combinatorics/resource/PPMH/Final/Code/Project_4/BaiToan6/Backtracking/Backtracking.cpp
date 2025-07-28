#include <iostream>
#include <string>
#include <algorithm>

struct TreeNode {
    std::string label;
    TreeNode* left;
    TreeNode* right;

    TreeNode(std::string lbl, TreeNode* l = nullptr, TreeNode* r = nullptr)
        : label(lbl), left(l), right(r) {}
};

int tree_edit_distance_bt(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return 0;
    if (!t1) return 1 + tree_edit_distance_bt(nullptr, t2->left) + tree_edit_distance_bt(nullptr, t2->right);
    if (!t2) return 1 + tree_edit_distance_bt(t1->left, nullptr) + tree_edit_distance_bt(t1->right, nullptr);

    int cost = (t1->label == t2->label) ? 0 : 1;

    int opt1 = tree_edit_distance_bt(t1->left, t2->left) + tree_edit_distance_bt(t1->right, t2->right);
    int opt2 = tree_edit_distance_bt(t1->left, t2->right) + tree_edit_distance_bt(t1->right, t2->left);

    return cost + std::min(opt1, opt2);
}

int main() {
    TreeNode* t1 = new TreeNode("A", new TreeNode("B"), new TreeNode("C"));
    TreeNode* t2 = new TreeNode("A", new TreeNode("B"), new TreeNode("D"));

    std::cout << "TED = " << tree_edit_distance_bt(t1, t2) << std::endl;

    delete t1->left; delete t1->right; delete t1;
    delete t2->left; delete t2->right; delete t2;
}
