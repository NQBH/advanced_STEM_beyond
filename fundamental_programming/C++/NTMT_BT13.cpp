#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n, m;
    long long M, S = 0;
    cin >> n >> m >> M;
    int i = 1;
    while (i <= n && (S + pow(i, m) <= M)) {
        S += pow(i, m);
        i++;
    }
    cout << S << endl;
}