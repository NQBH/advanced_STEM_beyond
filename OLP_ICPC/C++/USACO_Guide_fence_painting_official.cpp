#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int total = (b - a) + (d - c); // the sum of the 2 intervals
	int intersection = max(min(b, d) - max(a, c), 0); // subtract the intersection
	int ans = total - intersection;
	cout << ans << '\n';
}