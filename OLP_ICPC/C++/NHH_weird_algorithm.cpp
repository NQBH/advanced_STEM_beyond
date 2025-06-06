#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n; cin >> n;
    vector<long long> res;

    cout << n << " ";
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            res.push_back(n);
        } else {
            n = n * 3 + 1;
            res.push_back(n);
        }
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}