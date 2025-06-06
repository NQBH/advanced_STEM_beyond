#include <iostream>
using namespace std;

bool isPrime(long x) {
    if (x < 2) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;

    // check divisors of form 6k - 1 and 6k + 1
    for (long i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int t; cin >> t;
    while (t--) {
        long n; cin >> n;

        long num = n + 1;

        if (num <= 2) {
            num = 2;
        } else if ((num % 2) == 0) {
            num++;
        }

        while (!isPrime(num)) {
            num += 2;
        }

        cout << num << "\n";
    }

    return 0;
}