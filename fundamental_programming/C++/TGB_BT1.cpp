#include <cmath>
# include <iostream>
using namespace std;
int main()
{
	float a;
	cout << "canh hinh vuong:";
	cin >> a;

	const float CHU_VI = 4 * a;
	const float DIEN_TICH = a * a;
	cout << "Chu vi: " << CHU_VI << '\n';
	cout << "dien tich: " << DIEN_TICH << '\n';
	return 1;
}
