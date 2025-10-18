#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "nhap nhap n ";
	cin >> n;
	if (n <= 0 || n > 100) {
		cout << "khong hop le ";
		return 0;
	}

	int matran0[100][100];
	int matrandonvi[100][100];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matran0[i][j] = 0;
			if (i == j)
			{
				matrandonvi[i][j] = 1;
			}
			else {
				matrandonvi[i][j] = 0;
			}
		}
	}
	cout << "in ra matran0 " <<  endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matran0[i][j] << " ";
		}
		cout << endl;
	}
	cout << "in ra ma tran don vi " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrandonvi[i][j] << " ";
		}
		cout << endl;
	}
}