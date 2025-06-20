/*
Source: ACM Mid-Central United States 2004.
IDs for online judges: POJ 2013, ZOJ 2172.
Status:
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int n, cnt = 1;

int main() {
    while (cin >> n && n != 0) {
        vector<pair<string, string>> a(n / 2 + 2, {"", ""});
        for (int i = 1; i <= n / 2;  cin >> a[i].first >> a[i].second, ++i);
        if (n % 2 == 1) cin >> a[n / 2 + 1].first;

        vector<string> ans;

        for (int i = 1; i <= n / 2; ans.push_back(a[++i - 1].first));
        if (n % 2 == 1) ans.push_back(a[n / 2 + 1].first);
        for (int i = n / 2; i >= 1; ans.push_back(a[--i + 1].second));

        cout << "SET " << cnt++ << '\n';
        for (string i : ans) cout << i << '\n';
    }
}