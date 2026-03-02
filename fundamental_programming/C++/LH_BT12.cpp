#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n, m;
    long long sm = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) { sm += pow(i, m); }
    cout << "Sm= " << sm;
    return 0;
}