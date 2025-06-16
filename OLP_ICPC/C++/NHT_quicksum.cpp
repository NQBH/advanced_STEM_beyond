#include <bits/stdc++.h>
#define ll long long
using namespace std;

string str;
int table[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 'A', k = 1; i <= 'Z'; ++i, ++k)
		table[i] = k;

	while (getline(cin, str) && str[0] != '#') {
		int sum = 0;
		for (int j = 0; j < str.size(); ++j)
			if (str[j] >= 'A' && str[j] <= 'Z')
				sum += (j + 1) * table[str[j]];
		cout << sum << endl;
	}

	return 0;
}