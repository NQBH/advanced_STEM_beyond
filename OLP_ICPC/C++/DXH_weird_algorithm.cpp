#include <bits/stdc++.h>
using namespace std;

void printCollatz(long long n) {
    cout << n;
    while (n != 1) {
        if (n % 2 == 0) // chan thi chia cho 2
            n = n / 2;
        else
            n = 3 * n + 1;  // le thi * 3 + 1
        cout << " " << n;
    }
    cout << "\n";
}

int main() {
    long long n; // n -> so nguyen duong
    cin >> n;
    printCollatz(n);
}