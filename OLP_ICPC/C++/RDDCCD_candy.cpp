#include <bits/stdc++.h>
using namespace std;
int a[100005];

void solve() {
	int n;
	scanf("%d", &n);
	if (n % 2 == 0) {
		puts("-1");
		return;
	}
	vector<int> v;
	int f = 0;
	for (int i = 29; i >= 1; --i)
		if ((n >> i) & 1) {
			f = 1;
			v.push_back(2);
		} else if (f) v.push_back(1);
	printf("%d\n",v.size());
    for(auto x : v) printf("%d ",x);
    printf("\n");
}

int main() {
	int t;
	scanf("%d",&t);
    while(t--) solve();
}