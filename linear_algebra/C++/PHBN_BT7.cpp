#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int m;
	cout << "nhap so hang, cot: ";
	cin >> n >> m;

	vector<vector<int>> A(m, vector<int>(n, 0));

	//-----------------------------------------

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	//------------------------------------------
	while (true) {

		cout << "\n=== MENU ===\n";
		cout << "1) Hoan doi 2 hang: R_i <-> R_j\n";
		cout << "2) Nhan 1 hang voi k != 0: R_i <- k * R_i\n";
		cout << "3) Cong boi hang khac: R_i <- R_i + k * R_j (i != j)\n";
		cout << "0) Thoat\n";
		cout << "Chon: ";
		int choice;
		if (!(cin >> choice)) break;
		if (choice == 0) break;
		//============================================
		if (choice == 1) {
			int i, j;
			cout << "nhap hang can doi: ";
			cin >> i >> j;
			swap(A[i - 1], A[j - 1]);
			cout << "chay lai ma tran: " << endl;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cout << A[i][j] << " ";
				}
				cout << endl;
			}
			break;
		}
		else if (choice == 2) {
			int num;
			cout << "so k can nhan voi hang: ";
			cin >> num;
			cout << "hang can nhan voi k: ";
			int hang;
			cin >> hang;
			int s = 0;

			for (int i = 0; i < n; i++)
			{
				A[hang - 1][i] = A[hang - 1][i] * num;
			}

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cout << A[i][j] << " ";
				}
				cout << endl;
			}


			break;
		}
		else if (choice == 3) {
			cout << "nhap < he so > va < so hang > can co de thuc hien phep tinh: ";
			int heSo; int soHang;
			cin >> heSo >> soHang;
			cout << "nhap <stt hang > can thao tac: ";
			int stt;
			cin >> stt;

			if (heSo = soHang) {
				cout << "sai ";
			}
			else {
				for (int j = 0; j < n; j++)
				{
					A[stt][j] = A[soHang] * (heSo + A[stt][j]);
				}
			}

		}
		//=============================================
	}
}