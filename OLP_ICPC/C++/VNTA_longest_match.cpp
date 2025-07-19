#include <bits/stdc++.h>
using namespace std;

string preproc(const string s) {
    string res;
    for (char c : s) {
        if (isalpha(c)) res += c;
        else res += ' ';
    }
    return res;
}

vector<string> split(const string s) {
    vector<string> w;
    istringstream iss(s);
    string word;
    while (iss >> word) w.push_back(word);
    return w;
}

int lcs(const vector<string>& a, const vector<string>& b) {
    int m = a.size(), n = b.size(), ans = 0;
    vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
    // dp[i][j]: chuoi con lien tiep dai nhat ket thuc tai a[i - 1] & b[j - 1]
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            } else dp[i][j] = 0;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s1, s2;
    int k = 1;
    while (getline(cin, s1)) {
        if (s1 == "0") break;
        getline(cin, s2);
        string l1 = preproc(s1);
        string l2 = preproc(s2);
        vector<string>w1 = split(l1);
        vector<string>w2 = split(l2);
        cout << setw(2) << k++ << ". ";
        if (w1.empty() || w2.empty()) cout << "Blank!\n";
        else cout << "Length of longest match: " << lcs(w1, w2) << "\n";
    }
}
/*
// Many thanks to ChatGPT, Grok3, Gemini, BlackBoxAI, Perplexity, Claude
This is a test.
test
Hello!

The document provides late-breaking
information late breaking
0
*/