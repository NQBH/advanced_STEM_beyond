#include <iostream>
using namespace std;

int plus_operation = 0;

int fibonacci_numbers(long long n)
{
    if (n < 0)
        return -1;
    else if (n == 0 || n == 1)
        return n;
    else
    {
        ++plus_operation;
        return fibonacci_numbers(n - 1) + fibonacci_numbers(n - 2);  
    }
}

int main()
{
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    cout << "Day la " << n << " so dau tien cua day so Fibonacci: \n";
    cout << fibonacci_numbers(n) << " ";
    cout << "+: " << plus_operation;
    return 0;
}