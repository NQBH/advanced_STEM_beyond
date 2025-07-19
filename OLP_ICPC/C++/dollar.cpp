#include <iomanip>
#include <iostream>
using namespace std;

int main(void) {
	// 5c coin is used as the unit for notes & coins for New Zealand currency
	int b[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
	long long a[6001] = {1}; // number of ways in which n 5c coins may be made up using notes & coins for New Zealand currecy is a[n]
	// offline method, DP
	for (int i = 0; i < 11; ++i)
		for (int j = b[i]; j < 6001; ++j) a[j] += a[j - b[i]];
	cout << fixed << showpoint << setprecision(2);
	for (float fIn; cin >> fIn && fIn != 0; cout << endl)
		cout << setw(6) << fIn << setw(17) << a[(int)(fIn * 20 + 0.5f)];
}