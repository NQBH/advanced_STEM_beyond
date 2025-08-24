#include <iostream>
#include <vector>
using namespace std;

void make_set_size(int i) {
	parent[i] = i;
	sz[i] = 1;
}

pair<int, int> find_set(int v) {
	if (v == parent[v]) return {v, 0};
	parent<int, int> val = find_set(parent[v]);
	parent[v] = val.first;
	dist[v] = (dist[v] + val.second) % 2;
		// độ dài từ đỉnh v đến cha mới
		// = độ dài từ đỉnh v đến đỉnh cha cũ
		// + độ dài từ cha cũ tới cha mới (gốc của cây)
	return {parent[a], dist[a]};
}

void union_set(int a, int b) {
	pair<int, int> val_a = find_set(a), val_b = find_set(b);
	a = val_a.first;
	b = val_b.first;
	if (a == b) {
		if (val_a.second != val_b.second) {
			// đồ thị không còn là đồ thị 2 phía. Why?
		}
	}
	else {
		if (sz[a] < sz[b]) swap(a, b);
		parent[b] = a;
		sz[a] += sz[b];
		dist[b] = (val_a.second + val_b.second + 1) % 2;
			// độ dài từ đỉnh b tới gốc cây
			// = độ dài từ đỉnh a tới gốc cây ban đầu chứa a
			// + độ dài từ đỉnh b tới gốc cây ban đầu chứa b
			// + 1 (khoảng cách giữa 2 đỉnh a & b)
	}
}

int main() {

}