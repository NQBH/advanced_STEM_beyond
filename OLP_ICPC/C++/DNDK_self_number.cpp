#include <iostream>
#include <vector>
using namespace std;

int sumnum(int x) {
	int sum = x;
	while (x > 0) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

int main() {
	vector<bool> created(10001, false);
	for (int i = 1; i < 10000; ++i) {
		int a = sumnum(i);
		if (a < 10000)
			created[a] = true;
	}
	for (int i = 1; i < 10000; ++i)
		if (!created[i])
			cout << i << "\n";
}