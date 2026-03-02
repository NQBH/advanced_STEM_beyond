#include <iostream>
#include <cmath>

using namespace std;
int main() {
    long long m, n, sm = 1, M, s = 1;
    cin >> m >> n >> M;
    while (sm >= M) {
        if (sm <= M) {
            sm += pow(s, m);
        } else break;
        if (s <= n) {
            sm += pow(s, m);
            s++;
        } else break;
    }      cout << sm;
    return 0;
}