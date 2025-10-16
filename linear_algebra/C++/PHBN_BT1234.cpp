#include <bits/stdc++.h>
using namespace std;

void nhap(int a[][10], int hang, int cot) {
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < cot; j++) {
			cout << "nhap [" << i << "]" "[" << j << "] =";
			cin >> a[i][j];
		}
	}
}
void xuat(int a[][10], int hang, int cot) {
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < cot; j++) {
			cout << "\t" << a[i][j];
		}
		cout << "\n";
	}
}
void cong(int a[][10], int b[][10], int hang, int cot) {
	int tong[hang][cot];
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < cot; j++) {
			tong[i][j] = a[i][j] + b[i][j];
			cout << "\t" << tong[i][j];
		}
		cout << "\n";
	}
}
void hieu(int a[][10], int b[][10], int hang, int cot) {
	int hieu[hang][cot];
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < cot; j++) {
			hieu[i][j] = a[i][j] - b[i][j];
			cout << "\t" << hieu[i][j];
		}
		cout << "\n";
	}
}
void nhanvh(int a[][10], int n, int hang, int cot) {
	int tichvh[hang][cot];
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < cot; j++) {
			tichvh[i][j] = n * a[i][j];
			cout << "\t" << tichvh[i][j];
		}
		cout << "\n";
	}
}
void nhanmt(int a[][10], int b[][10], int m, int n, int p) {
	int tich[10][10];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			tich[i][j] = 0;
			for (int k = 0; k < n; k++) {
				tich[i][j] += a[i][k] * b[k][j];
			}
			cout << "\t" << tich[i][j];
		}
		cout << "\n";
	}
}
void chuyenvi(int a[][10], int hang, int cot) {
	for (int i = 0; i < cot; i++) {
		for (int j = 0; j < hang; j++) {
			cout << "\t" << a[j][i];
		}
		cout << "\n";
	}
}
int main() {
	int a[10][10], hang, cot;
	int b[10][10], cotb;
	cout << "nhap so hang: ";
	cin >> hang;
	cout << "nhap so cot: ";
	cin >> cot;
	nhap(a, hang, cot);
	xuat(a, hang, cot);
	nhap(b, hang, cot);
	xuat(b, hang, cot);
	chuyenvi(a, hang, cot);
}