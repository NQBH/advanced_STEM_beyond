#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll difference_array[400005]; // difference_array[i] = the difference of the values between special intervals i - 1 & i
int widths[400005]; // width[i] = the length of special interval i
ll interval_value[400005]; // interval_value[i] = the value of special interval i
// the sum of a special interval is interval_value[i] * width[i]
ll prefix_sums[400005]; // prefix_sums[i] = prefix sum of the sums of special intervals up to i
vector<int> indices; // sorted list of special indices
pair<int, int> queries[100005]; // queries given in the input <l, r>
pair<pair<int, int>, int> updates[100005]; // updates is given in the input <<l, r>, v>

// EndCodeSnip
/** @return the compressed index of a special index (it), aka its index in the
 * compressed list */
int get_compressed_index(int a) {
	return lower_bound(indices.begin(), indices.end(), a) - indices.begin();
}

int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		int l, r, v;
		cin >> l >> r >> v;
		indices.push_back(l);
		indices.push_back(r);
		updates[i] = {{l, r}, v};
	}
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		indices.push_back(l);
		indices.push_back(r);
		queries[i] = {l, r};
	}
	// perform coordinate compression by sorting & removing duplicates
	sort(indices.begin(), indices.end());
	indices.erase(unique(indices.begin(), indices.end()), indices.end());
	// we create the difference array, using coordinate compression & binary search to get the compressed index of each special index Note the 1-based indexing for convenience
	for (int i = 0; i < n; ++i) {
		auto a = updates[i];
		difference_array[get_compressed_index(a.first.first) + 1] += a.second;
		difference_array[get_compressed_index(a.first.second) + 1] -= a.second;
	}
	// by keeping track of the original values of the special indices, we can also figure out the lengths of each special interval
	for (int i = 0; i < indices.size() - 1; ++i) widths[i + 1] = indices[i + 1] - indices[i];
	// we use prefix sums of the difference array to get the values of the intervals
	for (int i = 1; i < indices.size(); ++i) interval_value[i] = interval_value[i - 1] + difference_array[i];
	// we use prefix sums over the sums of the special intervals to be able to answer queries quickly
	for (int i = 1; i < indices.size(); ++i) prefix_sums[i] = prefix_sums[i - 1] + interval_value[i] * widths[i];
	// classic use of prefix sum array to answer range sum queries
	for (int i = 0; i < q; ++i)
		cout << prefix_sums[get_compressed_index(queries[i].second)] - prefix_sums[get_compressed_index(queries[i].first)] << '\n';
}