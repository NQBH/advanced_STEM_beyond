// backtracking_tree_edit.cpp
// Tree Edit Distance Problem using Backtracking


#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory>
#include <algorithm>
#include <fstream>

/**
 * @brief Represents a node in the tree.
 */
class TreeNode {
public:
    int id; ///< Unique identifier for the node
    std::string label; ///< Label of the node
    int depth; ///< Depth of the node in the tree
    int order; ///< Preorder number
    TreeNode* parent; ///< Pointer to parent node
    std::vector<TreeNode*> children; ///< List of child nodes

    TreeNode(int id_, const std::string& label_)
        : id(id_), label(label_), depth(0), order(0), parent(nullptr) {}
};

/**
 * @brief Represents an ordered tree.
 */
class Tree {
public:
    std::vector<std::unique_ptr<TreeNode>> nodes; ///< All nodes (ownership)
    TreeNode* root; ///< Root node
    TreeNode* dummy; ///< Dummy node for deletion/insertion

    Tree() : root(nullptr), dummy(nullptr) {}

    TreeNode* createNode(const std::string& label) {
        int id = static_cast<int>(nodes.size());
        nodes.push_back(std::make_unique<TreeNode>(id, label));
        return nodes.back().get();
    }

    void setRoot(TreeNode* node) {
        root = node;
    }

    void addChild(TreeNode* parent, TreeNode* child) {
        parent->children.push_back(child);
        child->parent = parent;
    }

    void assignPreorderAndDepth() {
        int orderCounter = 0;
        assignPreorderAndDepthRecursive(root, 0, orderCounter);
    }

    void assignPreorderAndDepthRecursive(TreeNode* node, int depth, int& orderCounter) {
        node->depth = depth;
        node->order = orderCounter++;
        for (TreeNode* child : node->children) {
            assignPreorderAndDepthRecursive(child, depth + 1, orderCounter);
        }
    }

    std::vector<TreeNode*> getNodesInPreorder() const {
        std::vector<TreeNode*> result;
        collectPreorder(root, result);
        return result;
    }

    void collectPreorder(TreeNode* node, std::vector<TreeNode*>& result) const {
        result.push_back(node);
        for (TreeNode* child : node->children) {
            collectPreorder(child, result);
        }
    }
};

/**
 * @brief Sets up candidate nodes for each node in T1.
 * @param t1 First tree
 * @param t2 Second tree
 * @return Map from T1 nodes to candidate nodes in T2 (including dummy)
 */
std::map<TreeNode*, std::vector<TreeNode*>> setUpCandidateNodes(const Tree& t1, Tree& t2) {
    std::map<TreeNode*, std::vector<TreeNode*>> candidates;
    // Create dummy node for T2 if not already
    if (!t2.dummy) {
        t2.dummy = t2.createNode("DUMMY");
    }
    for (const auto& nodePtr : t1.nodes) {
        TreeNode* v = nodePtr.get();
        std::vector<TreeNode*> cand;
        cand.push_back(t2.dummy); // Deletion (map to dummy)
        for (const auto& wPtr : t2.nodes) {
            TreeNode* w = wPtr.get();
            if (w != t2.dummy && v->depth == w->depth) {
                cand.push_back(w);
            }
        }
        candidates[v] = cand;
    }
    return candidates;
}

/**
 * @brief Refines candidate nodes for the next recursion step.
 * @param t1 First tree
 * @param t2 Second tree
 * @param candidates Current candidate map
 * @param v Current node in T1
 * @param w Node in T2 assigned to v
 * @return Refined candidate map
 */
std::map<TreeNode*, std::vector<TreeNode*>> refineCandidateNodes(const Tree& t1, const Tree& t2,
    const std::map<TreeNode*, std::vector<TreeNode*>>& candidates, TreeNode* v, TreeNode* w,
    const std::map<TreeNode*, TreeNode*>& mapping) {
    std::map<TreeNode*, std::vector<TreeNode*>> refined = candidates;
    // Remove w from all other candidate lists if w is not dummy
    if (w != t2.dummy) {
        for (const auto& nodePtr : t1.nodes) {
            TreeNode* vprime = nodePtr.get();
            if (vprime != v) {
                auto& cand = refined[vprime];
                cand.erase(std::remove(cand.begin(), cand.end(), w), cand.end());
            }
        }
    }
    // Enforce parent mapping constraint
    for (const auto& nodePtr : t1.nodes) {
        TreeNode* vprime = nodePtr.get();
        if (mapping.count(vprime->parent) && vprime->parent && vprime != v) {
            TreeNode* parentMapped = mapping.at(vprime->parent);
            auto& cand = refined[vprime];
            cand.erase(std::remove_if(cand.begin(), cand.end(), [parentMapped](TreeNode* wprime) {
                return wprime->parent != parentMapped && wprime->parent != nullptr;
            }), cand.end());
        }
    }
    // Enforce sibling order constraint
    // (Optional: can be added for stricter mapping)
    return refined;
}

/**
 * @brief Recursive backtracking to find all valid mappings.
 * @param t1 First tree
 * @param t2 Second tree
 * @param mapping Current mapping from T1 to T2
 * @param solutions List of all valid mappings
 * @param candidates Candidate nodes for each node in T1
 * @param preorderT1 List of T1 nodes in preorder
 * @param idx Current index in preorderT1
 */
void extendTreeEdit(const Tree& t1, const Tree& t2,
    std::map<TreeNode*, TreeNode*>& mapping,
    std::vector<std::map<TreeNode*, TreeNode*>>& solutions,
    const std::map<TreeNode*, std::vector<TreeNode*>>& candidates,
    const std::vector<TreeNode*>& preorderT1,
    int idx) {
    TreeNode* v = preorderT1[idx];
    for (TreeNode* w : candidates.at(v)) {
        mapping[v] = w;
        if (idx == static_cast<int>(preorderT1.size()) - 1) {
            solutions.push_back(mapping);
        } else {
            auto refined = refineCandidateNodes(t1, t2, candidates, v, w, mapping);
            extendTreeEdit(t1, t2, mapping, solutions, refined, preorderT1, idx + 1);
        }
        mapping.erase(v);
    }
}

/**
 * @brief Reads a tree from input stream.
 * @param in Input stream
 * @return Constructed Tree
 */
Tree readTree(std::istream& in) {
    int n;
    in >> n;
    Tree tree;
    std::vector<TreeNode*> nodePtrs;
    for (int i = 0; i < n; ++i) {
        std::string label;
        int parentIdx;
        in >> label >> parentIdx;
        TreeNode* node = tree.createNode(label);
        nodePtrs.push_back(node);
        if (parentIdx == -1) {
            tree.setRoot(node);
        } else {
            // parentIdx is 0-based
            tree.addChild(nodePtrs[parentIdx], node);
        }
    }
    tree.assignPreorderAndDepth();
    return tree;
}

/**
 * @brief Prints a mapping solution.
 */
void printMapping(const std::map<TreeNode*, TreeNode*>& mapping, const Tree& t1, const Tree& t2) {
    for (const auto& pair : mapping) {
        TreeNode* v = pair.first;
        TreeNode* w = pair.second;
        std::cout << v->label << " -> ";
        if (w == t2.dummy) {
            std::cout << "lambda";
        } else {
            std::cout << w->label;
        }
        std::cout << ", ";
    }
    std::cout << std::endl;
}

int main() {
    // Input format:
    // n1
    // label0 parentIdx0
    // ...
    // label(n1-1) parentIdx(n1-1)
    // n2
    // label0 parentIdx0
    // ...
    // label(n2-1) parentIdx(n2-1)
    // parentIdx = -1 means root
    std::ifstream fin("input.txt");
    if (!fin) {
        std::cerr << "Error: Cannot open input.txt" << std::endl;
        return 1;
    }
    Tree t1 = readTree(fin);
    Tree t2 = readTree(fin);
    auto candidates = setUpCandidateNodes(t1, t2);
    std::vector<TreeNode*> preorderT1 = t1.getNodesInPreorder();
    std::map<TreeNode*, TreeNode*> mapping;
    std::vector<std::map<TreeNode*, TreeNode*>> solutions;
    extendTreeEdit(t1, t2, mapping, solutions, candidates, preorderT1, 0);
    std::cout << "Number of valid mappings: " << solutions.size() << std::endl;
    for (const auto& sol : solutions) {
        printMapping(sol, t1, t2);
    }
    return 0;
} 