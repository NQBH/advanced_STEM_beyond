#include <bits/stdc++.h>
using namespace std;

int main() {
    long long m, n, M, temp; cin >> m >> n >> M;
    long long Sm = 0, i = 1;
    while (i <= n) {
        temp = 1;
        long long mu = m;
        while (mu--) {temp *= i;}
        if (Sm + temp <= M) {
            Sm += temp;
        }
        else {break;}
        i++;
    }
    cout << Sm;
}