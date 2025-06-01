#include<bits/stdc++.h>
using namespace std;

void validParentheses(int open, int close, string cur, vector<string>& res) {
    if (open == 0 && close == 0) {
        res.push_back(cur);
        return;
    }
    if (open > 0) validParentheses(open - 1, close, cur + '(', res);
    if (close > open) validParentheses(open, close - 1, cur + ')', res);
}

long long catalan(int n) {
    long long res = 1;
    for (int i = 0; i < n; i++) {
        res *= 2 * (2 * i + 1);
        res /= (i + 2);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<string> valid;
    validParentheses(n, n, "", valid);
    cout << "So chuoi dau ngoac dung dan: " << valid.size() << '\n';
    for (const string& s : valid) cout << s << '\n';
    cout << "\nSo catalan thu n: " << catalan(n);
}