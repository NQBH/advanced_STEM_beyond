#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
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

int tree_edit_distance_bb(TreeNode* t1, TreeNode* t2, int cost_so_far, int& best_cost) {
    if (cost_so_far >= best_cost) return INT_MAX;

    if (!t1 && !t2) {
        best_cost = std::min(best_cost, cost_so_far);
        return 0;
    }

    if (!t1) {
        int extra = count_nodes(t2);
        if (cost_so_far + extra >= best_cost) return INT_MAX;
        return extra;
    }

    if (!t2) {
        int extra = count_nodes(t1);
        if (cost_so_far + extra >= best_cost) return INT_MAX;
        return extra;
    }

    int cost = (t1->label == t2->label) ? 0 : 1;
    int total_cost = cost_so_far + cost;

    int remaining = std::abs(count_nodes(t1->left) + count_nodes(t1->right) -
                             count_nodes(t2->left) + count_nodes(t2->right));
    if (total_cost + remaining >= best_cost) return INT_MAX;

    int opt1_left = tree_edit_distance_bb(t1->left, t2->left, total_cost, best_cost);
    int opt1_right = tree_edit_distance_bb(t1->right, t2->right, total_cost, best_cost);
    int opt2_left = tree_edit_distance_bb(t1->left, t2->right, total_cost, best_cost);
    int opt2_right = tree_edit_distance_bb(t1->right, t2->left, total_cost, best_cost);

    int sum1 = (opt1_left == INT_MAX || opt1_right == INT_MAX) ? INT_MAX : opt1_left + opt1_right;
    int sum2 = (opt2_left == INT_MAX || opt2_right == INT_MAX) ? INT_MAX : opt2_left + opt2_right;

    int min_sum = std::min(sum1, sum2);
    int best_local = (cost == INT_MAX || min_sum == INT_MAX) ? INT_MAX : cost + min_sum;

    if (best_local != INT_MAX)
        best_cost = std::min(best_cost, cost_so_far + best_local);

    return best_local;
}

int compute_tree_edit_distance(TreeNode* t1, TreeNode* t2) {
    int best_cost = INT_MAX;
    tree_edit_distance_bb(t1, t2, 0, best_cost);
    return best_cost;
}

int main() {
    TreeNode* t1 = new TreeNode("A", new TreeNode("B"), new TreeNode("C"));
    TreeNode* t2 = new TreeNode("A", new TreeNode("B"), new TreeNode("D"));

    std::cout << "TED = " << compute_tree_edit_distance(t1, t2) << std::endl;  

    delete t1->left; delete t1->right; delete t1;
    delete t2->left; delete t2->right; delete t2;
}