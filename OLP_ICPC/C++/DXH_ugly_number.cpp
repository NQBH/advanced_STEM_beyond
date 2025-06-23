#include <bits/stdc++.h>
using namespace std;
#define ll long long
//Ap dung Dynamic Programming
ll uglyNumber(int n) {
    vector<ll> ugly(n); //Dung de luu cac so ugly
    ugly[0] = 1; // So ugly dau tien la 1

    int index2 = 0, index3 = 0, index5 = 0;
    ll next2 = 2, next3 = 3, next5 = 5;

    for (int i = 1; i < n; ++i) {
        ugly[i] = min({next2, next3, next5});

        if (ugly[i] == next2) {
            ++index2;
            next2 = ugly[index2] * 2;
        }
        if (ugly[i] == next3) {
            ++index3;
            next3 = ugly[index3] * 3;
        }
        if (ugly[i] == next5) {
            ++index5;
            next5 = ugly[index5] * 5;
        }
    }

    return ugly[n - 1];
}

int main() {
    vector<int> inputs;
    int n; //input de nhap vao
    while (cin >> n && n != 0) {
        inputs.push_back(n);
    }

    for (int x : inputs) {
        cout << uglyNumber(x) << '\n';
    }

    return 0;
}