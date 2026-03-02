#include <iostream>
using namespace std;
int main() {

	int N;
	cin >> N;
	int a, chan = 0, le = 0;
	for (int i = 0; i < N; ++i) {
		cin >> a;
		if (a % 2 == 0) chan++;
		else le++;
	}
	cout << " so chan trong N bien = " << chan << endl;
	cout << " so le trong N bien = " << le << endl;


	return 0;
}
