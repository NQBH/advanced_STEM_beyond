#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        cout << n << " ";
        int b = n;
        int total = 0;
        int a = 1;
        while (b > 0) {
            total += a * a;
            b -= a;
            ++a;
        }
        --a;
        if (b < 0) {
            total = total - a * a + a * (b + a);
        }
        cout << total << "\n";
        cin >> n;
    }
}