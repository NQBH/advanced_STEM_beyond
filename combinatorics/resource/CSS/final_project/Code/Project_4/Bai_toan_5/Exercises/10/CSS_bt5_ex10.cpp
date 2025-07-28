#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int value;         // gia tri cua nut
    int first_child;   // chi so cua con dau tien
    int next_sibling;  // chi so cua anh em ke tiep
    int parent;        // chi so cua cha
    int num_children;  // so con truc tiep

    TreeNode(int val)
      : value(val), first_child(-1),
        next_sibling(-1), parent(-1),
        num_children(0) {}
};

class Tree {
public:
    int n;                  // so nut toi da
    vector<TreeNode*> nodes;// mang luu cac nut
    int root_node;          // chi so nut goc
    int next_idx;           // chi so tiep theo de cap phat

    Tree(int vertices)
      : n(vertices), root_node(-1), next_idx(0) {
        nodes.resize(n, nullptr);
    }

    void set_root(int value) {
        // thiet lap nut goc
        nodes[0] = new TreeNode(value);
        root_node = 0;
        next_idx = 1;
    }

    void add_child(int parent_idx, int value) {
        // them con vao nut parent_idx
        if (next_idx >= n) throw runtime_error("Tree is full");
        int new_node_idx = next_idx;
        nodes[new_node_idx] = new TreeNode(value);
        nodes[new_node_idx]->parent = parent_idx;
        if (nodes[parent_idx]->first_child == -1) {
            nodes[parent_idx]->first_child = new_node_idx;
        } else {
            int current = nodes[parent_idx]->first_child;
            while (nodes[current]->next_sibling != -1)
                current = nodes[current]->next_sibling;
            nodes[current]->next_sibling = new_node_idx;
        }
        nodes[parent_idx]->num_children++;
        next_idx++;
    }

    int parent(int v) { return nodes[v]->parent; }
    int first_child(int v) { return nodes[v]->first_child; }
    int next_sibling(int v){ return nodes[v]->next_sibling; }
    int number_of_children(int v){
        return nodes[v]->num_children;
    }
};

int main() {
    Tree t(5);
    t.set_root(0);
    t.add_child(0, 1);
    t.add_child(0, 2);
    t.add_child(0, 3);
    cout << "Number of children of root: "
         << t.number_of_children(0) << endl; // 3
    cout << "First child of root: "
         << t.first_child(0) << endl;         // 1
    cout << "Next sibling of first child: "
         << t.next_sibling(1) << endl;        // 2
    cout << "Parent of node 2: "
         << t.parent(2) << endl;             // 0
    return 0;
}