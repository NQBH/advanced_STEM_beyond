#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n;
vector<ll> weights;

ll recurse_apples(int index, ll sum1, ll sum2) {
	if (index == n) return abs(sum1 - sum2); // we have added all apples: return the absolute difference
	// try adding the current apple to either the 1st or 2nd set
	return min(recurse_apples(index + 1, sum1 + weights[index], sum2),
	           recurse_apples(index + 1, sum1, sum2 + weights[index]));
}

int main() {
	cin >> n;
	weights.resize(n);
	for (ll &i : weights) cin >> i;
	cout << recurse_apples(0, 0, 0); // solve the problem starting at apple 0 with both sets being empty
}