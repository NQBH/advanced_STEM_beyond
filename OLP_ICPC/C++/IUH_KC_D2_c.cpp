#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 1e18;
const int MOD = 1e9 + 7;
int n, m;
vector<int>a, k;
vector<vector<int>> node;

vector<int> mergeNode(vector<int> &l, vector<int> &r) {
    vector<int> temp;
    int i = 0, n = l.size();
    int j = 0, m = r.size();
    while (i < n && j < m) {
        if (l[i] < r[j]) {
            temp.push_back(l[i]);
            i++;
        }
        else {
            temp.push_back(r[j]);
            j++;
        }
    }
    while (i < n) temp.push_back(l[i++]);
    while (j < m) temp.push_back(r[j++]);
    return temp;
}

void build(int idx, int l, int r) {
    if (l == r) {
        node[idx].push_back(a[l]);
        return;
    }
    int mid = l + r >> 1;
    build(idx * 2, l, mid);
    build(2 * idx + 1, mid + 1, r);
    node[idx] = mergeNode(node[2 * idx], node[2 * idx + 1]);
}

int query(int idx, int l, int r, int u, int v, int x) {
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) {
        int index = -1;
        int ml = 0, mr = node[idx].size() -1;
        while (ml <= mr) {
            int mid = ml + mr >> 1;
            if (node[idx][mid] <= x) {
                index = mid;
                ml = mid + 1;
            }
            else {
                mr = mid - 1;
            }
        }
        return index + 1;
    }
    int mid = l + r >> 1;
    return query(2 * idx, l, mid, u, v, x) + query(2 * idx + 1, mid + 1, r,u, v, x);
}

int getK(int l, int r, int k) {
    int len = r - l + 1, need = len - k + 1;   
    int ml = -1e5, mr = 1e5;
    int ans = 0;
    while (ml <= mr) {
        int mid = ml + mr >> 1;
        int cnt = query(1, 1, n, l, r, mid);
        if (cnt >= need) {
            ans = mid;
            mr = mid - 1;
        }
        else {
            ml = mid + 1;
        }
    }
    return ans;
}

bool checkSubtask1() {
    return n <= 1e3;
}
bool checkSubtask2() {
    return true;
}

void doSubtask1() {
    // wtf sao giai nhanh z
}

void doSubtask2() {
    for (int i = 1; i <= n - m + 1; i++) {
        int ans = getK(i, i + m - 1, k[i]);
        cout << ans << " ";
    }
}

signed main() {
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    k.resize(n-m + 2);
    for (int i = 1; i <= n - m + 1;i++) {
        cin >> k[i];
    }
    node.resize(4 * n + 5);
    build(1,1,n);
    //if (checkSubtask1()) return doSubtask1(), 0;
    if (checkSubtask2()) return doSubtask2(), 0;
}