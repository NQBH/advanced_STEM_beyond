#include <iostream>
using namespace std;

int complete_graph_edges(int n) {
    if (n <= 1) return 0;
    return n * (n - 1) / 2;
}

int complete_bipartite_edges(int p, int q) {
    return p * q;
}

int main() {
    cout << "Complete Graph Kn:" << endl;
    for (int n = 1; n <= 5; n++) {
        cout << "K" << n << ": " << complete_graph_edges(n) << " edges" << endl;
    }
    
    cout << "\nComplete Bipartite Graph Kp,q:" << endl;
    int test_cases[][2] = {{1,1}, {2,2}, {2,3}, {3,4}};
    for (int i = 0; i < 4; i++) {
        int p = test_cases[i][0];
        int q = test_cases[i][1];
        cout << "K" << p << "," << q << ": " << complete_bipartite_edges(p, q) << " edges" << endl;
    }
    
    return 0;
}