#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <list>
#include <queue>
#include <utility>
#include <limits>
#include <cmath>
#include <map>
#include <set>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct TED_Node {
    std::string label;
    std::vector<TED_Node*> children;
    
    int postorder_id = -1;
    int leftmost_leaf_id = -1;

    TED_Node(std::string lbl) : label(lbl) {}
    TED_Node(std::string lbl, std::vector<TED_Node*> ch) : label(lbl), children(ch) {}
};

std::vector<int> get_transpose(const std::vector<int>& p);
void print_diagram(const std::vector<int>& p, const std::string& title);

#endif