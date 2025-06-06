#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<ll> createPermutation(const vector<ll>& a) {
    ll n = a.size();

    vector<ll> res(n);
    vector<ll> even, odd;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            even.push_back(a[i]);
        } else {
            odd.push_back(a[i]);
        }
    }

    // Update res size
    res.resize(even.size() + odd.size());
    // append the even elements
    for (int i = 0; i < even.size(); i++) {
        res[i] = even[i];
    }
    for (int i = 0; i < res.size() - even.size(); i++) {
        res[i + even.size()] = odd[i];
    }

    return res;
}

int main() {
    ll n; cin >> n;
    vector<ll> a(n);
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    vector<ll> result = createPermutation(a);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}