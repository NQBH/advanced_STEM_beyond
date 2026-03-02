#include <iostream>
using namespace std;

int main() {
	float a;
	float b;
	float x;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	// a*x + b == 0;
	if (a != 0) {
		x = -b / a;
		cout << "x = " << x << endl;
	}
	else if (a == 0 && b != 0) {
		cout << "error" << endl;
	}
	else if (a == 0 && b == 0)
	{
		cout << "vo so nghiem" << endl;
	}

	return 0;
}


