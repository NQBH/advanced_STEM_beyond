#include <iostream>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	string A, B;
	cin >> A >> B;
	if (A[0] != B[0]) ++ans;
	for (int i = 1; i < n; ++i)
		if (A[i - 1] == B[i - 1] && A[i] != B[i]) ++ans;
	cout << ans << '\n';
}