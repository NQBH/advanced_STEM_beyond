#include <iostream>
#include <vector>
using namespace std;

vector<int> apply_permutation(vector<int> sequence, vector<int> permutation) {
	vector<int> new_sequence(sequence.size());
	for (int i = 0; i < sequence.size(); ++i) new_sequence[i] = sequence[permutation[i]];
		return new_sequence;
}

vector<int> permute(vector<int> sequence, vector<int> permutation, long long k) {
	while (k > 0) {
		if (k & 1) sequence = apply_permutation(sequence, permutation);
		permutation = apply_permutation(permutation, permutation);
		k >>= 1;
	}
	return sequence;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> sequence(n), permutation(n), res(n);
	for (int i = 0; i < n; ++i) cin >> sequence[i];
	for (int i = 0; i < n; ++i) cin >> permutation[i];
	res = permute(sequence, permutation, k);
	for (int i = 0; i < n; ++i) cout << res[i] << " ";
}