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
			
		}
}