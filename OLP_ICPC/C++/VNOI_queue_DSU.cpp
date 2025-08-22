#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, Size, Max;

void make_set_size_max(int v) {
	parent[v] = v;
	Size[v] = 1;
	Max[v] = v;
}

int find_set(int v) {
    return v == parent[v] ? v : parent[v] = find_set(parent[v]);
}

void union_set_size_max(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (Size[a] < Size[b]) swap(a, b);
		parent[b] = a;
		Size[a] += Size[b];
		Max[a] = max(Max[a], Max[b]);
	}
}

void leave(int v) { // người thứ v rời khỏi hàng
	union_set_size_max(v, v + 1);
}

int find_next(int p) { // trả về thứ tự của người gần nhất bên phải vị trí p mà chưa rời khỏi hàng
	p = find_set(p);
	return Max[p];
}

int main() {
	int n, num_query, type_query, node; // query has 2 types: type 1: 1 i: remove person i from current queue & type 2: 2 p: find closest person from p to the right that is still in the queue
	cin >> n >> num_query;
	parent.resize(n);
	Size.resize(n);
	Max.resize(n);
	for (int i = 1; i <= n; ++i) make_set_size_max(i);
	for (int i = 0; i < num_query; ++i) {
		cin >> type_query >> node;
		if (type_query == 1) leave(node); // remove person i from current queue
		else cout << find_next(node) << '\n';
	}
}