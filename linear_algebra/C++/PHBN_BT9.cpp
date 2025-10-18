#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cout << "Nhap so nguyen duong n: ";
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (a[i][j] != 0) {
					cout << " không phai Ma tran duong cheo!!!" << endl;
					return 0;
				};
			}
		}
	}
	cout << "La ma tran duong cheo!!!" << endl;
	return 0;
}

ma trận tam giác  trên


#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cout << "Nhap so nguyen duong n: ";
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n ; j++) {
			if (i > j) {
				if (a[i][j] != 0) {
					cout << "Khong phai ma tran tam giac tren!!!" << endl;
					return 0;
				}
			}
		}

	}
	cout << "la ma tran tam giac tren!!!" << endl;
	return 0;
}


ma trận tam giác dưới
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cout << "Nhap so nguyen duong n: ";
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n ; j++) {
			if (j > i) {
				if (a[i][j] != 0) {
					cout << "Khong phai ma tran tam giac duoi!!!" << endl;
					return 0;
				}
			}

		}

	}
	cout << "la ma tran tam giac duoi!!!" << endl;
	return 0;
}



ma trận tam giác trên
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cout << "Nhap so nguyen duong n: ";
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n ; j++) {
			if (a[i][j] != a[j][i]) {
				cout << "khong phai ma tran doi xung!" << endl;
				return 0;
			}
		}
	}
	cout << "la ma tran doi xung!" << endl;
	return 0;

}