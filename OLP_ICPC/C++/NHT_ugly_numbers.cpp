#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int ans[1509];

int main() {
	int a_2 = 1, a_3 = 1, a_5 = 1;
	ans[1] = 1;
	for (int i = 2; i <= 1501; ++i) {
		ans[i] = min({ans[a_2] * 2, ans[a_3] * 3, ans[a_5] * 5});
		if (ans[i] == ans[a_2] * 2)
			++a_2;
		if (ans[i] == ans[a_3] * 3)
			++a_3;
		if (ans[i] == ans[a_5] * 5)
			++a_5;
	}
	while (cin >> n && n != 0)
		cout << ans[n] << '\n';
	return 0;
}