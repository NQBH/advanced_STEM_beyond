#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
int cnt[MAX], f[MAX], m[MAX];
bool prime[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	//f[i]: so phan tu trong a chia het cho i
	for (int i = 1; i < MAX; i++)
		for (int j = i; j < MAX; j += i) f[i] += cnt[j];

	fill(m, m + MAX, 1);
	for (int i = 2; i < MAX; i++) {
		if (!prime[i]) {
			for (int j = i; j < MAX; j += i) {
				m[j] *= -1;
				prime[j] = true;
			}
			for (long long j = 1LL * i * i; j < MAX; j += i * i) m[j] = 0;
		}
	}

	long long res = 0;
	for (int i = 1; i < MAX; i++) {
		long long c = f[i];
		res += 1LL * m[i] * c * (c - 1) / 2;
	}
	cout << res;
}