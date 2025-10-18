#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "nhap nhap n ";
	cin >> n;

	if (n <= 0 || n > 100)
	{
		cout << "khong hop le ";
		return 0;
	}
	int a[100][100];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	bool duongcheo = true;
	bool tamgiactren = true;
	bool tamgiacduoi = true;
	bool doixung = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (i != j && a[i][j] != 0)
				duongcheo = false;
			if (i > j && a[i][j] != 0)
				tamgiactren = false;
			if (i < j && a[i][j] != 0)
				tamgiacduoi = false;
			if (a[i][j] != a[j][i])
				doixung = false;
		}
	}
	cout << "Ket qua kiem tra:" << endl;
	if (duongcheo) cout << "- La ma tran duong cheo" << endl;
	else cout << "- Khong phai ma tran duong cheo" << endl;

	if (tamgiactren) cout << "- La ma tran tam giac tren" << endl;
	else cout << "- Khong phai ma tran tam giac tren" << endl;

	if (tamgiacduoi) cout << "- La ma tran tam giac duoi" << endl;
	else cout << "- Khong phai ma tran tam giac duoi" << endl;

	if (doixung) cout << "- La ma tran doi xung" << endl;
	else cout << "- Khong phai ma tran doi xung" << endl;

	return 0;
}