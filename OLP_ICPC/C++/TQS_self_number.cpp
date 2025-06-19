#include <bits/stdc++.h>
using namespace std;

int sum_digit(int n) {
    if (n / 10 == 0) return n;
    return n % 10 + sum_digit(n / 10);
}

int main() {
    vector<bool> a(10001, true);
    for (int i = 1; (i + sum_digit(i)) <= 10000; ++i)
        a[i + sum_digit(i)] = false;
    for (int i = 1; i <= 10000; ++i)
        if (a[i]) cout << i << "\n";
}