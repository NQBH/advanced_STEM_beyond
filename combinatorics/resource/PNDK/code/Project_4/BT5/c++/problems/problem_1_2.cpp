#include <iostream>
using namespace std;

bool is_cycle_bipartite(int n) {
    return n % 2 == 0;
}

bool is_complete_bipartite(int n) {
    return n <= 2;
}

int main() {
    cout << "Cycle Graph Cn - Bipartite:" << endl;
    for (int n = 1; n <= 7; n++) {
        cout << "C" << n << ": " << (is_cycle_bipartite(n) ? "Yes" : "No") << endl;
    }
    
    cout << "\nComplete Graph Kn - Bipartite:" << endl;
    for (int n = 1; n <= 5; n++) {
        cout << "K" << n << ": " << (is_complete_bipartite(n) ? "Yes" : "No") << endl;
    }
    
    return 0;
}