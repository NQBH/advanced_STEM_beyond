#include <iostream>
#include <vector>
using namespace std;
#define ll long long

vector<ll> parent, sz, Max;

void make_set_size_max(ll v) {
	parent[v] = v;
	sz[v] = 1;
	Max[v] = v;
}

ll find_set(ll v) {
    return v == parent[v] ? v : parent[v] = find_set(parent[v]);
}

void union_set_size_max(ll a, ll b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (sz[a] < sz[b]) swap(a, b);
		parent[b] = a;
		sz[a] += sz[b];
		Max[a] = max(Max[a], Max[b]);
	}
}

void leave(ll v) { // người thứ v rời khỏi hàng
	union_set_size_max(v, v + 1);
}

ll find_next(ll p) { // trả về thứ tự của người gần nhất bên phải vị trí p mà chưa rời khỏi hàng
	p = find_set(p);
	return Max[p];
}

ll main() {
	ll n, num_query, type_query, node; // query has 2 types: type 1: 1 i: remove person i from current queue & type 2: 2 p: find closest person from p to the right that is still in the queue
	cin >> n >> num_query;
	parent.resize(n);
	sz.resize(n);
	Max.resize(n);
	for (ll i = 1; i <= n; ++i) make_set_size_max(i);
	for (ll i = 0; i < num_query; ++i) {
		cin >> type_query >> node;
		if (type_query == 1) leave(node); // remove person i from current queue
		else cout << find_next(node) << '\n';
	}
}