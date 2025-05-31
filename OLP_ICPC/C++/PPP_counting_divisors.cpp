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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
