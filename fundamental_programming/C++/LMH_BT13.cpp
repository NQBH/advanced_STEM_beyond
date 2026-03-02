#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    long long M;
    long long S = 0;
    cin >> n >> m >> M;
    for (int i = 1; i <= n; i++) {
        if (S + pow(i, m) > M) {
            break;
        }
        S += pow(i, m);
    }
    cout << S;
    return 0;
}
