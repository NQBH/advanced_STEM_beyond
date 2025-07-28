#include <iostream>
#include <vector>
using namespace std;

class Tree {
public:
    int n; // so nut
    vector<int> parent; // mang cha
    vector<vector<int>> children; // danh sach con

    Tree(int vertices) : n(vertices) {
        parent.assign(n, -1);
        children.resize(n);
    }

    void add_edge(int u, int v) {
        // Them canh (u,v)
        parent[v] = u;
        children[u].push_back(v);
    }

    int previous_sibling(int v) {
        // Tim anh em truoc cua nut v
        if (parent[v] == -1) return -1;
        auto& siblings = children[parent[v]];
        for (int i = 0; i < siblings.size(); ++i) {
            if (siblings[i] == v) {
                return i > 0 ? siblings[i - 1] : -1;
            }
        }
        return -1;
    }
};

int main() {
    Tree t(5);
    t.add_edge(0, 1);
    t.add_edge(0, 2);
    t.add_edge(0, 3);
    cout << "Previous sibling of 2: " << t.previous_sibling(2) << endl; // 1
    cout << "Previous sibling of 1: " << t.previous_sibling(1) << endl; // -1
    return 0;
}