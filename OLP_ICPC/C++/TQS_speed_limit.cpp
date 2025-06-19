#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, n;
    bool stop = false;
    while (!stop) {
        cin >> n;
        if (n == -1)
            stop = true;
        else {
            long long kq = 0;
            int c = 0;
            while (n--) {
                cin >> a >> b;
                kq += a * (b - c);
                c = b;
            }
            cout << kq << " miles" << "\n";
        }
    }
}