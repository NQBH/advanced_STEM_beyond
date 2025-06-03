#include<bits/stdc++.h>
using namespace std;

vector<long long>mul(const vector<vector<long long>>&matrix, const vector<long long>&vec) {
    int m = matrix.size(); //=#matrix_rows
    int n = vec.size(); //=#vector_rows =#matrix_cols
    vector<long long>res(m, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[i] += matrix[i][j] * vec[j];
        }
    }
    return res;
}

vector<vector<long long>> stirling2(int s, int t) {
    vector<vector<long long>> dp(s + 1, vector<long long>(t + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= t; j++) {
            dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
    return dp;
}

vector<long long>findB(int s) {
    auto dp = stirling2(s, s);
    vector<vector<long long>>stirMat(s, vector<long long>(s));
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= s; j++) stirMat[i - 1][j - 1] = dp[i][j];
    }
    vector<long long>A(s, 1);
    return mul(stirMat, A);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int s;
    cin >> s;
    vector<long long>B = findB(s);
    for (long long b : B) cout << b << "\n";
}