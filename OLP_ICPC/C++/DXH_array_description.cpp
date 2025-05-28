#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
//Thuật toán Dynamic Programming
// dp[i][j]: number of satisfying array s.t. a[i] = j
ll get_answer(vector<ll>& arr, ll N, ll M, vector<vector<ll>> & dp) {
    if (arr[0] == 0) {
        for (int v = 1; v <= M; v++) {
            dp[0][v] = 1;
        }
    } else {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < N; i++) {
        for (int v = 1; v <= M; v++) {
            if (arr[i] == 0 || arr[i] == v) {
                ll val = dp[i - 1][v];
                if (v - 1 >= 1) val = (val + dp[i - 1][v - 1]) % mod;
                if (v + 1 <= M) val = (val + dp[i - 1][v + 1]) % mod;
                dp[i][v] = val;
                // summary of 3 lines above: d[i][v] = (dp[i - 1][v] + dp[i - 1][v - 1] + dp[i - 1][v + 1]) % mod
            }
        }
    }

    ll result = 0;
    if (arr[N - 1] == 0) {
        for (int v = 1; v <= M; v++) {
            result = (result + dp[N - 1][v]) % mod;
        }
    } else {
        result = dp[N - 1][arr[N - 1]];
    }

    return result;
}

int main() {
    ll N, M; //Kích thước của mảng, Giá trị lớn nhất
    cin >> N >> M;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<vector<ll>> dp(N, vector<ll>(M + 2, 0)); // dp[i][v], v từ 1 đến M
    cout << get_answer(arr, N, M, dp) << endl;
    return 0;
}