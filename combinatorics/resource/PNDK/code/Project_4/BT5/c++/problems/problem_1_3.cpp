#include <iostream>
#include <cmath>
using namespace std;

long long count_spanning_trees_complete(int n) {
    if (n <= 1) return 1;
    long long result = 1;
    for (int i = 0; i < n - 2; i++) {
        result *= n;
    }
    return result;
}

void manual_spanning_trees_example() {
    cout << "Graph: Triangle (3 vertices, 3 edges)" << endl;
    cout << "Spanning trees:" << endl;
    cout << "1. Edges: (0,1) and (0,2)" << endl;
    cout << "2. Edges: (0,1) and (1,2)" << endl;
    cout << "3. Edges: (0,2) and (1,2)" << endl;
    cout << "Total: 3 spanning trees" << endl;
}

int main() {
    manual_spanning_trees_example();
    
    cout << "\nComplete Graphs - Number of Spanning Trees:" << endl;
    for (int n = 1; n <= 5; n++) {
        long long count = count_spanning_trees_complete(n);
        cout << "K" << n << ": " << count << " spanning trees" << endl;
    }
    
    return 0;
}