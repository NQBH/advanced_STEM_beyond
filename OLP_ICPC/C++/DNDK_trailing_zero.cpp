#include <iostream>
#define ll long long
using namespace std;

int main()
{
	ll n;
	cin >> n;
	ll count = 0;
	for (ll i = 5; n / i >= 1 ; i *= 5) {
		count += n / i;
	}
	cout << count;
}