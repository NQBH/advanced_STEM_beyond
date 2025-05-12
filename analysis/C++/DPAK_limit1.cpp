#include <bits/stdc++.h>

using namespace std;

int main(){
    double e;
    cin >> e;
    int n = 2; // d = 1/3
    double d = 1 / (double)(n + 1); // 0.333333
                            // 0.3
    while (d >= e) {
        n++;
        d = 1 / (double)(n + 1);
    }
    cout << n;
}