// PPP_distributing_apples.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define l long

const l mod = 1e9 + 7;
const l max_val = 2e6;

vector<l> fact(max_val, 1);
vector<l> inv(max_val, 1);

l n;    // Number of children
l m;    // Number of apples

l bin_pow(l a, l n, l m)
{
	a %= m;
	l res = 1;
	while (n > 0)
	{
		if (n % 2 == 1)
			res = res * a % m;
		a = a * a % m;
		n /= 2;
	}
	return res;
}

l binom(l x, l y)
{
	return fact[x] * inv[y] % mod * inv[x - y] % mod;
}

int main()
{
	cin >> n >> m;

	for (l i = 2; i < max_val; i++)
		fact[i] = i * fact[i - 1] % mod;

	inv[max_val - 1] = bin_pow(fact[max_val - 1], mod - 2, mod);

	for (l i = max_val - 2; i > 0; i--)
		inv[i] = (i + 1) * inv[i + 1] % mod;

	cout << binom(n + m - 1, n - 1) << endl;
}