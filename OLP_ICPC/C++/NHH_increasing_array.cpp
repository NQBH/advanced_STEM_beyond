#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll count = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            count += a[i - 1] - a[i];
            a[i] = a[i - 1]; // để so sánh với giá trị mới, không phải giá trị trước khi tăng
        }
    }
    cout << count << "\n";

    return 0;
}