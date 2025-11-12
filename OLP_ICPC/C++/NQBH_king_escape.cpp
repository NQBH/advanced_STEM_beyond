#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, ax, ay, bx, by, cx, cy;
	cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
	if ((bx < ax) == (cx < ax) && (by < ay) == (cy < ay)) cout << "YES";
	else cout << "NO";
}