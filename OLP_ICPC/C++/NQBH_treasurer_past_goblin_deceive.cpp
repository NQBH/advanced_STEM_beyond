#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int eye = 0; 
		for (int i = 0; i < n; ++i)
			if (s[i] == '-') ++eye;
		int mouth = n - eye;
		if (eye < 2 || mouth == 0) {
			cout << "0\n";
			continue;
		}
		cout << 1ll * eye / 2 * mouth * (eye - eye / 2) << '\n';
	}
}