#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

/** A data structure that can answer point update & range min queries. */
template <class T> class MinSegmentTree {
	private:
		const T DEFAULT = numeric_limits<T>().max();
		int len;
		vector<T> segtree; // index 0 is not in use
		T combine(const T &a, const T &b) return min(a, b);
		void build(const vector<T> &arr, int at, int at_left, int at_right) {
			if (at_left == at_right) {
				segtree[at] = arr[at_left];
				return;
			}
			int mid = (at_left + at_right) / 2;
			build(arr, 2 * at, at_left, mid);
			build(arr, 2 * at + 1, mid + 1, at_right);
			segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
		}
		void set(int ind, T val, int at, int at_left, int at_right) {
			if (at_left == at_right) {
				segtree[at] = val;
				return;
			}
			int mid = (at_left + at_right) / 2;
			if (ind <= mid) set(ind, val, 2 * at, at_left, mid);
			else set(ind, val, 2 * at + 1, mid + 1, at_right);
			segtree[at] = 
		}
}