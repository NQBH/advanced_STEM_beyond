#include <iostream>;
using namespace std;

int main() {
	float a;
	float C;
	float S;
	cout << "a = ";
	cin >> a;
	if (a < 0 )
		cout << "vô lí " << '\n';
	if (a <= 0) {
		cout << "không có dien tich và Chu vi  ";
	}
	else {
		C = 4 * a;
		cout << "C = :" << C << '\n';
		S = a * a;
		cout << "S = :" << S << '\n';
	}

	return 0;
}
