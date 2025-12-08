#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, l, r;
    if (!(cin >> n >> l >> r)) return;
    
    // We maintain the current prefix XOR value (P_i) and the previous one (P_{i-1})
    // to compute a_i = P_i ^ P_{i-1}.
    // P_0 is initially 0.
    int prev_P = 0;
    
    for (int i = 1; i <= n; ++i) {
        int curr_P;
        // Construct P such that P[i] = i for all i != r, and P[r] = l-1.
        if (i == r) {
            curr_P = l - 1;
        } else {
            curr_P = i;
        }
        
        // Calculate the element a[i]
        int val = prev_P ^ curr_P;
        
        // Print the element
        cout << val << (i == n ? "" : " ");
        
        // Update prev_P for the next iteration
        prev_P = curr_P;
    }
    cout << "\n";
}

int main() {
    // Optimization for faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}