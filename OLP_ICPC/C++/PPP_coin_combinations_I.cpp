// PPP_coin_combinations_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7;

int main()
{
    int n, x;   // Tổng số đồng xu và tổng tiền mong muốn
    cin >> n >> x;

    vector<int> coin_sack(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> coin_sack[i];
    }

    vector<ll> dp(x + 1, 0);
    dp[0] = 1;  // 1 cách tạo 0 cent

    // Tính trước số cách tổ hợp với DP
    for (int i = 1; i <= x; ++i) 
    {
        for (int coin : coin_sack) 
        {
            if (i - coin >= 0) 
                dp[i] = (dp[i] + dp[i - coin]) % mod;
        }
    }

    cout << dp[x] << endl;
    return 0;
}