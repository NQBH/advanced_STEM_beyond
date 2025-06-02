// PPP_common_divisors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

const int max_val = 1e6 + 1;  // +1 to include 1e6

int main()
{
    int n;
    cin >> n;

    vector<int> frequency(max_val, 0);  // Frequency of numbers up to 1e6

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        frequency[x]++;
    }

    // Check for the largest d with at least 2 multiples in the array
    for (int d = max_val - 1; d >= 1; --d)
    {
        int count = 0;
        for (int j = d; j < max_val; j += d)
        {
            count += frequency[j];
            if (count >= 2) break;
        }
        if (count >= 2)
        {
            cout << d << endl;
            return 0;
        }
    }

    return 0;
}