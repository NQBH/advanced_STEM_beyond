#include <iostream>
using namespace std;

bool is_natural(int n) {
	if (n == 0) return true;
	else return is_natural(n - 1);
}

int main() {
	int n;
	cin >> n;
	cout << n << " is a natural number: " << is_natural(n) << '\n';
}