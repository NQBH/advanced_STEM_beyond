#include<bits/stdc++.h>
using namespace std;
void nhapmt(vector< vector<int> > &a, int hang, int cot) {
	for (int i = 0; i < hang; ++i) {
		for (int j = 0; j < cot; ++j) {
			cout << "nhap [" << i << "] [" << j << "]";
			cin >> a[i][j];
		}
	}
}
void xuatmt(const vector< vector<int> > &a, int hang, int cot) {
	for (int i = 0; i < hang; ++i) {
		for (int j = 0; j < cot; ++j) {
			cout << "\t" << a[i][j];
		}
		cout << "\n";
	}
}
void nhapvec( vector<int>&a, int n) {
	for (int i = 0; i < n; ++i) {
		cout << "nhap a[" << i << "]";
		cin >> a[i];
	}
}
void hoanvi2dong(vector< vector<int> > &a, int i, int j) {
	swap(a[i], a[j]);
}
void nhanhangso(vector<vector<int> > &a, int n, int k) {
	for (int j = 0; j < a[n].size(); ++j)
		a[n][j] *= k;
}
void congboi(vector< vector<int> > &a, int cot, int i, int j, int k) {
	for (int n = 0; n < cot; ++n) {
		a[j][n] += k * a[i][n];
	}
}
int main() {
	int hang, cot;
	cout << "nhap so hang: ";
	cin >> hang;
	cout << "nhap so cot: ";
	cin >> cot;
	vector<vector<int> > a(hang, vector<int>(cot));
	nhapmt(a, hang, cot);
	xuatmt(a, hang, cot);
	int c;
	cout << "nhap so ptu cua vec b: ";
	cin >> c;
	vector<int> b(c);
	vector<vector<int> > A = a;
	if (c != hang) {
		cout << "IMPOSSIBLE";
	}
	else {
		for (int i = 0; i < hang; i++) {
			cout << "nhap b[" << i << "]";
			cin >> b[i];
		}
		for (int i = 0; i < hang; ++i) {
			for (int j = 0; j < cot; ++j) {
				A[i].push_back(b[i]);
			}
		}
		cout << "\nMa tran bo sung [A|b]:\n";
		xuatmt(A, hang, cot + 1);
	}
	int m, n;
	cout << "nhap so hang muon hoan vi: ";
	cin >> m;
	cout << "nhap so hang muon hoan vi: ";
	cin >> n;
	hoanvi2dong(a, m, n);
	xuatmt(a, hang, cot);
	int l, k;
	cout << "nhap boi so: ";
	cin >> k;
	cout << "nhan vao hang: ";
	cin >> l;
	nhanhangso(a, l, k);
	xuatmt(a, hang, cot);
	int x, y, z;
	cout << "nhap dong muon cong vao: ";
	cin >> x;
	cout << "dong cong: ";
	cin >> y;
	cout << "nhap boi so: ";
	cin >> z;
	congboi(a, cot, y, x, z);
	xuatmt(a, hang, cot);
}