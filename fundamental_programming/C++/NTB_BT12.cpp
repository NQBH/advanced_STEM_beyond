#include <iostream>
#include <cmath>

using namespace std;
int main() {
    long long m, n, sm = 0;
    cin >> m >> n;
    for (int i = 1; i <= n; ++i ) {
        sm += pow(i, m);
    }
    cout << sm << endl;
    return 0;
}
