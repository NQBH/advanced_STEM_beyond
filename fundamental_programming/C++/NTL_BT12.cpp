#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long long m, n;
    cin >> m >> n;
    long long S = 0;
    for (int i = 0; i <= n; i++) {
        S += pow(i, m);
    }
    cout << "Sm= " << " " << S;
}
