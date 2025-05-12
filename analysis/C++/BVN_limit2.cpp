#include <bits/stdc++.h>
using namespace std;

int main() {
    double a;
    cin >> a;
    int n = 1;
    double d = sqrt(n + 2);
    while (d <= a) {
        n++;
        d = sqrt(n + 2);
    }
    cout << n;
    
    return 0;
}