#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	float a;
	cout << "chieu dai:";
	cin >> a;
	float b;
	cout << "chieu rong:";
	cin >> b;

	const float CHU_VI = 2 * (a + b);
	const float DIEN_TICH = a * b;
	const float DO_DAI_DUONG_CHEO = sqrt(a * a + b * b);
	cout << "Chu vi: " << CHU_VI << '\n';
	cout << "Dien tich: " << DIEN_TICH << '\n';
	cout << "Do dai duong cheo: " << DO_DAI_DUONG_CHEO << '\n';
}
