#include <iostream>
using namespace std;

int p_self_recursive(int n, int k) {
    if (n == 0 && k == 0) return 1;
    if (n < 0 || k <= 0) return 0;
    return p_self_recursive(n - (2 * k - 1), k - 1);
}

int main() {
    int n = 13, k = 3;
    cout << "p_" << k << "^{selfcjg}(" << n << ") = "
         << p_self_recursive(n, k) << endl;
    return 0;
}