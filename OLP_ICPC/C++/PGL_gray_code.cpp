#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n; cin >> n;
    vector<string> gray;
    gray.push_back("0");
    gray.push_back("1");
    for (int i = 2; i <= n; i++) {
        vector<string> res;
        for (auto s : gray) res.push_back("0" + s);
        vector<string> rev;
        rev = gray;
        reverse(rev.begin(), rev.end());
        for (auto s : rev) res.push_back("1" + s);
        gray = res;
    }
    for (auto it : gray) cout << it << endl;
    return 0;
}