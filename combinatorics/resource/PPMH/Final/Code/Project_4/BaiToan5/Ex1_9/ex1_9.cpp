#include <iostream>
#include <vector>
using namespace std;

int previous_sibling(const vector<int>& parent, int v) {
    int p = parent[v];
    int result = -1;
    for (int u = 1; u < v; ++u) {
        if (parent[u] == p) {
            result = u;
        }
    }
    return result;
}

int main() {
    vector<int> parent = {-1, -1, 1, 1, 2, 2, 3};

    for (int v = 1; v <= 6; ++v) {
        cout << "previous_sibling(" << v << ") = " 
             << previous_sibling(parent, v) << endl;
    }

    return 0;
}