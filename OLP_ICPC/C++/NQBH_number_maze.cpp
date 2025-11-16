#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string getKthPermutation(int n, int k) {
    vector<int> numbers;
    ll factorial[n + 1];
    string result = "";

    // Precompute factorials
    factorial[0] = 1;
    for (int i = 1; i <= n; ++i) {
        factorial[i] = factorial[i - 1] * i;
        numbers.push_back(i); // Populate numbers 1 to N
    }
    --k; // Adjust k to be 0-indexed
    for (int i = n; i > 0; --i) {
        ll index = k / factorial[i - 1]; // Find the index of the number to pick
        result += to_string(numbers[index]); // Add to result
        numbers.erase(numbers.begin() + index); // Remove from available numbers
        k %= factorial[i - 1]; // Update k for the next iteration
    }
    return result;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		string s;
		int j, k, A = 0;
		cin >> s >> j >> k;
		int n = (int)s.size();
		string a = getKthPermutation(n, j);
		string b = getKthPermutation(n, k);
		// cout << a << '\n' << b << '\n';
		vector<bool> done(n + 1, false);
		for (int i = 0; i < n; ++i)
			if (a[i] == b[i]) ++A;
		cout << A << 'A' << n - A << "B\n";
	}
}