#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

struct TreeNode {
    std::string label;
    TreeNode* left;
    TreeNode* right;

    TreeNode(std::string lbl, TreeNode* l = nullptr, TreeNode* r = nullptr)
        : label(lbl), left(l), right(r) {}
};

int count_nodes(TreeNode* t) {
    if (!t) return 0;
    return 1 + count_nodes(t->left) + count_nodes(t->right);
}

int tree_edit_distance_dc(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return 0;
    if (!t1) return count_nodes(t2);
    if (!t2) return count_nodes(t1);

    int cost = (t1->label == t2->label) ? 0 : 1;

    int cost1 = tree_edit_distance_dc(t1->left, t2->left) +
                tree_edit_distance_dc(t1->right, t2->right);
    int cost2 = tree_edit_distance_dc(t1->left, t2->right) +
                tree_edit_distance_dc(t1->right, t2->left);

    return cost + std::min(cost1, cost2);
}

int main() {
    TreeNode* t1 = new TreeNode("A", new TreeNode("B"), new TreeNode("C"));
    TreeNode* t2 = new TreeNode("A", new TreeNode("B"), new TreeNode("D"));

    std::cout << "TED = " << tree_edit_distance_dc(t1, t2) << std::endl; 

    delete t1->left; delete t1->right; delete t1;
    delete t2->left; delete t2->right; delete t2;
}
