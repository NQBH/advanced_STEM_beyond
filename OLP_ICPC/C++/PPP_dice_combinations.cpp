// Dice_combinations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
#define MAX 1e6

const int MOD = 1e9 + 7;

int main()
{
    int n;  // Tổng
    cin >> n;

    // Các số trên xí ngầu
    vector<int> dice_digits = { 1, 2, 3, 4, 5, 6  }; // Số trên xí ngầu 1 -> 6
    vector<long long> dp(MAX + 1, 0);  // dp[i] là số cách tạo nên tổng n 

    dp[0] = 1;  // 1 cách tạo 0 cent

    // Tính trước số cách tổ hợp với DP
    for (int i = 1; i <= n; ++i) 
    {
        for (int dice = 1; dice <= 6; ++dice) 
        {
            if (i - dice >= 0)
                dp[i] = (dp[i] + dp[i - dice]) % MOD;
        }
    }

    cout << dp[n] << endl;
    return 0;
}