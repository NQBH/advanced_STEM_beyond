// PPP_counting_divisors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
#define ll long long

const ll max_val = 1e6 + 1;

int n;  // Number of integers


int main()
{
    cin >> n;

    vector<ll> divisors(max_val, 0);

    // Precompute number of divisors for every number from 1 to max_val
    for (int i = 1; i < max_val; ++i)
    {
        for (int j = i; j < max_val; j += i)
            ++divisors[j];
    }

    // Read each number and print its number of divisors
    while (n--)
    {
        int x;
        cin >> x;
        cout << divisors[x] << "\n";
    }

    return 0;
}