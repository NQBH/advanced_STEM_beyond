#include <iostream>
using namespace std;

int main() {
	int n, k; // n: length of original sequence, k: length of a subsequence
	cin >> n >> k;
	int a[n], b[k]; // a: original sequence of length n, b: a subsequence of length k
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < k; ++i) cin >> b[i];
	cout << "Original sequence a:";
	for (int i = 0; i < n; ++i) cout << " " << a[i];
	cout << '\n';
	cout << "Index sequence b:";
	for (int i = 0; i < k; ++i) cout << " " << b[i];
	cout << '\n';
	cout << "Subsequence a[b[i]]:";
	for (int i = 0; i < k; ++i) cout << " " << a[b[i]];
}