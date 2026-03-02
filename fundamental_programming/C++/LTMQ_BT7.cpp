#include <iostream>
#include <cmath>
using namespace std;
int main() {
	{
		double a = 1, b = 4, c = 3;
		if (a < b && a < c)
			cout << "a = min";
		else if (b < a && b < c)
		{cout << "b = min";}
		else {cout << "c = min";}
		if (a > b && a > c)
			cout << "a = max";
		else if (b > a && b > c)
		{cout << "b = max";}
		else {cout << "c = max";}

	}
	{	double a, b, c;
		cout << "nhap a =";
		cin >> a;
		cout << "nhap b =";
		cin >> b;
		cout << "nhap c =";
		cin >> c;
		if (a < b && a < c)
			cout << "a = min";
		else if (b < a && b < c)
		{cout << "b = min";}
		else {cout << "c = min";}

	}
	return 0;


}
