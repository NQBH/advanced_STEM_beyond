// PPP_candy_lottery.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
using ld = long double;

int n, k;


int main() 
{
    cin >> n >> k;
    ld ans = 0.0;
    // Duyệt từng loại kẹo i = 1..k theo hướng từ k trở về 1
    for (int i = k; 1 <= i; --i)
    {
        ld add = (ld)i / k;
        ld substract = (ld)(i - 1) / k;
        ld exp_add = pow(add, n);
        ld exp_substract = pow(substract, n);
        ans += (exp_add - exp_substract) * i;
    }
    // Làm tròn đến 6 chữ số thập phân
    ld lam_tron = round(ans * 1e6) / 1e6;

    // Kiểm tra xem lam_tron có gần với ans không (tránh trường hợp làm tròn sai)
    if (abs(lam_tron - ans) < 1e-9) 
        ans = lam_tron;

    cout << fixed << setprecision(6) << ans << '\n';
    return 0;
}