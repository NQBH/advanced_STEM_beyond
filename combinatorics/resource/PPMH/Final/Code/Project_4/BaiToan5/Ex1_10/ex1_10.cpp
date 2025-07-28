#include <iostream>
#include <vector>
using namespace std;

class ExtendedTree {
private:
    int n;
    vector<int> first_child;
    vector<int> next_sibling;
    vector<int> parent;
    vector<int> num_children;
    vector<vector<int>> children_list;
    int root;

public:
    ExtendedTree(int n) {
        this->n = n;
        first_child.assign(n, -1);
        next_sibling.assign(n, -1);
        parent.assign(n, -1);
        num_children.assign(n, 0);
        children_list.resize(n);
        root = -1;
    }

    void set_root(int v) {
        root = v;
    }

    int get_root() {
        return root;
    }

    void add_child(int par, int child) {
        parent[child] = par;
        next_sibling[child] = first_child[par];
        first_child[par] = child;
        num_children[par]++;
        children_list[par].insert(children_list[par].begin(), child);
    }

    int number_of_children(int v) {
        return num_children[v];
    }

    const vector<int>& children(int v) {
        return children_list[v];
    }

    void print_tree() {
        for (int i = 0; i < n; ++i) {
            cout << "Node " << i << " has children: ";
            for (int c : children_list[i]) {
                cout << c << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n = 7;
    ExtendedTree tree(n);

    tree.set_root(0);
    tree.add_child(0, 1);
    tree.add_child(0, 2);
    tree.add_child(1, 3);
    tree.add_child(1, 4);
    tree.add_child(2, 5);
    tree.add_child(2, 6);

    cout << "Root: " << tree.get_root() << endl;
    cout << "Number of children of node 1: " << tree.number_of_children(1) << endl;

    vector<int> children_of_0 = tree.children(0);
    cout << "Children of node 0: ";
    for (int c : children_of_0) {
        cout << c << " ";
    }
    cout << endl;

    tree.print_tree();
    return 0;
}