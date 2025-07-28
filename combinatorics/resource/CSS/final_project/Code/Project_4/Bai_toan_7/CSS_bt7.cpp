#include <iostream>
#include <vector>
using namespace std;

class Tree {
public:
    vector<vector<int>> adj;
    int n;

    Tree(int vertices) : n(vertices) {
        adj.resize(n);
    }

    void add_edge(int parent, int child) {
        adj[parent].push_back(child);
    }

    void preorder(int v) {
        cout << v << " ";
        for (int child : adj[v]) {
            preorder(child);
        }
    }

    void postorder(int v) {
        for (int child : adj[v]) {
            postorder(child);
        }
        cout << v << " ";
    }

    void top_down(int v) {
        preorder(v); // Top-down is equivalent to preorder
    }

    void bottom_up(int v) {
        postorder(v); // Bottom-up is equivalent to postorder
    }
};

int main() {
    Tree t(5);
    t.add_edge(0, 1);
    t.add_edge(0, 2);
    t.add_edge(1, 3);
    t.add_edge(1, 4);
    cout << "Preorder: ";
    t.preorder(0);
    cout << endl;
    cout << "Postorder: ";
    t.postorder(0);
    cout << endl;
    cout << "Top-down: ";
    t.top_down(0);
    cout << endl;
    cout << "Bottom-up: ";
    t.bottom_up(0);
    cout << endl;
    return 0;
}