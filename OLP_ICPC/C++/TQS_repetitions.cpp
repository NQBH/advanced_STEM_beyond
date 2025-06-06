#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    cin >> n;
    int j = 0, i = 0, k = 0;
    int Max = 0;
    while (j < size(n))
    {
        if (n[i] == n[j])
        {
            j++;
            k++;
        }
        else
        {
            i++;
            k--;
        }
        if (k > Max)
            Max = k;
    }
    cout << Max;
}