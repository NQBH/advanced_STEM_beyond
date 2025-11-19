#include <bits/stdc++.h>
using namespace std;
/*
(\_/)          (\___/)
( " ")		   ( ^ ^  )
 /  >> <3      he(#)(#)
/	??		   (") (")
bruth lmeo lmeo
*/
int n, m;
int a[100100];
long long f[100100];
long long fr[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	a[0] = 0;
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		cin >> a[i];
		if (a[i] < a[i - 1]) f[i] += a[i - 1] - a[i];
	}
	fr[n + 1] = 0;
	for (int i = n; i > 0; i--) {
		fr[i] = fr[i + 1];
		if (a[i] < a[i + 1]) fr[i] += a[i + 1] - a[i];
	}
	int s, t;
	for (int i = 1; i <= m; i++)
	{
		cin >> s >> t;
		if (s < t) cout << f[t] - f[s] << endl;
		else cout << fr[t] - fr[s] << endl;
	}
	return 0;
}
