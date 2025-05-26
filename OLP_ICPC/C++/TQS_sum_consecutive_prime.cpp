#include <iostream>
using namespace std;
bool prime(int a)
{
    for (int i=2; i<= a/2; i++)
        if (a % i == 0)
            return false;
    return true;
}

int main()
{
    int a[100], total = 0, b = 2;
    while (total < 100)
    {
        if (prime(b))
        {
            a[total] = b;
            b++;
            total++;
        }
        else
            b++;
    }
    int m;
    cin >> m;
    while (m != 0)
    {
        int kq = 0;
        for (int i = 0; a[i] <= m; i++)
        {
            int s=0;
            for (int j=i; j<100 and s < m; j++)
                s += a[j];
            if (s == m)
                ++kq;
        }
        cout << kq << "\n";
        cin >> m;
    }
}