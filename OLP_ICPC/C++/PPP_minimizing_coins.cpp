// PPP_Minimizing_coins.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

const int coin_max = 1e2;
const int sum_max = 1e6 + 1;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> coin_sack(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> coin_sack[i];
    }

    vector<int> dp(x + 1, sum_max);
    dp[0] = 0;

    for (int i = 1; i <= x; ++i)
    {
        for (int c : coin_sack)
        {
            if (i - c >= 0 && dp[i - c] != sum_max)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    if (dp[x] == sum_max)
        cout << -1 << endl;
    else
        cout << dp[x] << endl;

    return 0;
}