#include <iostream>
using namespace std;

struct TreeNode {
    int value;                 // gia tri cua nut
    TreeNode* first_child;     // con tro den con dau tien
    TreeNode* next_sibling;    // con tro den anh em ke tiep
    TreeNode* parent;          // con tro den cha
    int num_children;          // so con truc tiep

    TreeNode(int val)
      : value(val),
        first_child(nullptr),
        next_sibling(nullptr),
        parent(nullptr),
        num_children(0)
    {}
};

class Tree {
public:
    TreeNode* root_node;

    Tree() : root_node(nullptr) {}

    void set_root(int value) {
        // Thiet lap goc cua cay
        root_node = new TreeNode(value);
    }

    void add_child(TreeNode* parent, int value) {
        // Them con vao nut parent
        TreeNode* new_node = new TreeNode(value);
        new_node->parent = parent;
        if (!parent->first_child) {
            parent->first_child = new_node;
        } else {
            TreeNode* current = parent->first_child;
            while (current->next_sibling) {
                current = current->next_sibling;
            }
            current->next_sibling = new_node;
        }
        parent->num_children++;
    }

    TreeNode* parent(TreeNode* v) {
        // Tra ve cha cua nut v
        return v->parent;
    }

    TreeNode* first_child(TreeNode* v) {
        // Tra ve con dau tien cua nut v
        return v->first_child;
    }

    TreeNode* next_sibling(TreeNode* v) {
        // Tra ve anh em ke tiep cua nut v
        return v->next_sibling;
    }

    int number_of_children(TreeNode* v) {
        // Tra ve so con cua nut v
        return v->num_children;
    }
};

int main() {
    Tree t;
    t.set_root(0);
    t.add_child(t.root_node, 1);
    t.add_child(t.root_node, 2);
    cout << "Number of children of root: " << t.number_of_children(t.root_node) << endl; // 2
    cout << "First child of root: " << t.first_child(t.root_node)->value << endl;        // 1
    cout << "Next sibling of first child: " << t.next_sibling(t.first_child(t.root_node))->value << endl; // 2
    return 0;
}