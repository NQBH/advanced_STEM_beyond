#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main() {
    ll s, e;

    while (cin >> s >> e) {
        ll maxLen = 0, maxNum;
        // Thuật toán chính
        for (ll i = s; i <= e; i++) {
            vector <ll> cur;

            ll n = i; // số bắt đầu
            // cout << n << " ";
            // Tìm chuỗi số Collatz
            while (n != 1) {
                if (n % 2 == 0) {
                    n = n / 2;
                } else n = (3 * n) + 1;
                // cout << n << " "; // biết cụ thể
                cur.push_back(n); // để so sánh sau
            }

            if (cur.size() > maxLen) {
                maxLen = cur.size();
                maxNum = i;
            }
            // cout << '\n';
        }
        cout << s << " " << e << " " << maxLen + 1;
        cout << '\n';
    }

    return 0;
}