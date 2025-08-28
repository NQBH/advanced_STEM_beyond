#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b <= c || d <= a) cout << b - a + d - c; // [a,b] & [c,d] are disjoint or has only 1 element
	else if (a < c) cout << max(b, d) - a; // when a < c < b < d or a < c < d < b
	else cout << max(b, d) - c; // when c < a < d < b or c < a < b < d
}