#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* first_child;
    TreeNode* next_sibling;
    TreeNode* parent;
    TreeNode* last_child;      // con cuối cùng
    int child_count;           // số con
    
    TreeNode(int value) : val(value) {
        first_child = nullptr;
        next_sibling = nullptr;
        parent = nullptr;
        last_child = nullptr;
        child_count = 0;
    }
};

class Tree {
private:
    TreeNode* root_node;

public:
    Tree() : root_node(nullptr) {}
    
    TreeNode* root() {
        /*** O(1) ***/
        return root_node;
    }
    
    int number_of_children(TreeNode* v) {
        /*** O(1) ***/
        if (v == nullptr) {
            return 0;
        }
        return v->child_count;
    }
    
    vector<TreeNode*> children(TreeNode* v) {
        /*** O(số con) ***/
        vector<TreeNode*> result;
        if (v == nullptr) {
            return result;
        }
        TreeNode* child = v->first_child;
        while (child != nullptr) {
            result.push_back(child);
            child = child->next_sibling;
        }
        return result;
    }
    
    TreeNode* add_child(TreeNode* parent, int child_val) {
        /*** Thêm con với thời gian O(1) ***/
        TreeNode* child_node = new TreeNode(child_val);
        child_node->parent = parent;
        
        if (parent->first_child == nullptr) {
            // Nút đầu tiên
            parent->first_child = child_node;
            parent->last_child = child_node;
        } else {
            // Thêm vào cuối
            parent->last_child->next_sibling = child_node;
            parent->last_child = child_node;
        }
        
        parent->child_count++;
        return child_node;
    }
    
    void set_root(int val) {
        root_node = new TreeNode(val);
    }
};

int main() {
    // Tạo cây ví dụ
    Tree tree;
    tree.set_root(1);
    TreeNode* root = tree.root();
    
    // Thêm con
    TreeNode* child2 = tree.add_child(root, 2);
    TreeNode* child3 = tree.add_child(root, 3);
    tree.add_child(child2, 4);
    tree.add_child(child2, 5);
    
    cout << "Tree structure:" << endl;
    cout << "Root: " << tree.root()->val << endl;
    cout << "Number of children of root: " << tree.number_of_children(root) << endl;
    
    vector<TreeNode*> children = tree.children(root);
    cout << "Children of root:" << endl;
    for (TreeNode* child : children) {
        cout << "  Child: " << child->val << ", Number of its children: " 
             << tree.number_of_children(child) << endl;
    }
    
    return 0;
}