#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 1e16;

struct node {
    int x0 = 0;
    int x1 = 0;
    bool flip = false;
};

vector<node> tree;
string s;
vector<int> a;

node merge(node &left, node &right) {
    node res;
    res.x0 = left.x0 ^ right.x0;
    res.x1 = left.x1 ^ right.x1;
    return res;
}

void apply(int idx) {
    swap(tree[idx].x0, tree[idx].x1);
    tree[idx].flip = !tree[idx].flip;
}

void push(int idx) {
    if (tree[idx].flip == true) {
        apply(2 * idx);
        apply(2 * idx + 1);
        tree[idx].flip = false;
    }
}

void build(int idx, int l, int r) {
    if (l == r) {
        if (s[l] == '0') tree[idx].x0 = a[l];
        else tree[idx].x1 = a[l]; 
        return;
    }
    int mid = l + r >> 1;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
}

void flip_range(int idx, int l, int r, int u, int v) {
    if (u > r || v < l) return;
    if (l >= u && r <= v) {
        apply(idx);
        return;
    }
    push(idx);
    int mid = l + r >> 1;
    flip_range(2 * idx, l, mid, u, v);
    flip_range(2 * idx + 1, mid + 1, r, u, v);
    tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
}

signed main() {
    int t; cin >> t;
 
    while (t--) {
        tree.clear();
        s.clear();
        a.clear();
        int n; cin >> n;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        cin >> s;
        s = " " + s;
        tree.resize(4 * n + 5);
        build(1,1,n);

        int q; cin >> q;
        while (q--) {
            int type; cin >> type;
            if (type == 1) {
                int l, r; cin >> l >> r;
                flip_range(1,1,n,l,r);
            }
            else {
                int g; cin >> g;
                cout << (g == 1 ? tree[1].x1 : tree[1].x0) << " ";
            }
        }
        cout << endl;
    }
}