#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("paint.in", "r", stdin); // use standard input to read from "paint.in"
	freopen("paint.out", "w", stdout); // use standard output to write to "paint.out"
	vector<bool> cover(100);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for (int i = a; i < b; ++i) cover[i] = true;
	for (int i = c; i < d; ++i) cover[i] = true;
	int ans = 0;
	for (int i = 0; i < cover.size(); ++i) ans += cover[i];
	cout << ans << '\n';
}