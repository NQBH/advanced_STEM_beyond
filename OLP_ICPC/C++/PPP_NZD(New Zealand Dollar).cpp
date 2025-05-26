// PPP_NZD(New Zealand Dollar).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
#define MAX 5000 // 50.00 đô = 5000 cent

int main()
{
    double nzd_amount;
    
    // Các mệnh giá (tính bằng cent)
    vector<int> nzd_notes_coins = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000 }; // từ 5 cent đến 50 dollar
    vector<long long> dp(MAX + 1, 0);  // dp[i] là số cách tạo nên i cent

    dp[0] = 1;  // 1 cách tạo 0 cent

    // Tính trước số cách tổ hợp với DP
    for (int coin : nzd_notes_coins) 
    {
        for (int i = coin; i <= MAX; ++i) 
            dp[i] += dp[i - coin];
    }

    
    while (cin >> nzd_amount && nzd_amount != 0.00) 
    {
        int cents = static_cast<int>(nzd_amount * 100 + 0.5);  // làm tròn
        cout << setw(6) << fixed << setprecision(2) << nzd_amount;
        cout << setw(17) << dp[cents] << endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
