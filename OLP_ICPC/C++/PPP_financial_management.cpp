#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double x;   // Khai báo số tiền hàng tháng

double bank_account(int i, double x)
{
    double money_sum = 0;
    for (int i = 1; i <= 12; i++)
    {
        cin >> x;
        money_sum += x;
    }
    return money_sum / 12;
}

int main()
{
    int i = 12;
    double hoa_don = bank_account(i, x); 
    cout << "$" << hoa_don << setprecision(2); 
    return 0;
}