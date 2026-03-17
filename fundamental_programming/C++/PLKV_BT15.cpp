#include <iostream>
#include <cmath>
using namespace std;

//BT1:hinhvuong
void hinh_vuong(double a) {
	double chuvi = 4 * a;
	cout << "Chu vi hinh vuong = " << chuvi << endl;
	double dientich = a * a;
	cout << "Dien tich hinh vuong = " << dientich << endl;
}
//BT2:hinhchunhat
void hinh_chu_nhat(double a, double b) {
	double chuvi = 2 * ( a + b );
	cout << "Chu vi = " << chuvi << endl;
	double dientich = a * b;
	cout << "Dien tich  = " << dientich << endl;
	double duongcheo = sqrt( a * a + b * b );
	cout << "Duong cheo = " << duongcheo << endl;
}
//BT3:hinhhopchunhat
void hinh_hop_chu_nhat(double a, double b, double c) {
	if (a <= 0 || b <= 0 || c <= 0) cout << "-1\n";
	else {
		if (a > 0 && a == b && b == c) {
			cout << "HLP\n";
			double Sxq = 4 * a * a, Stp = 6 * a * a, V = a * a * a, d = sqrt(3) * a;
			cout << "Dien tich xung quanh Sxq = " << Sxq << '\n';
			cout << "Dien tich toan phan Stp = " << Stp << '\n';
			cout << "The tich V = " << V << '\n';
			cout << "Duong cheo d = " << d << '\n';
		} else {
			cout << "HHCN\n";
			double Sxq = 2 * (a + b) * c, Stp = 2 * (a * b + b * c + c * a), V = a * b * c, d = sqrt(a * a + b * b + c * c);
			cout << "Dien tich xung quanh Sxq = " << Sxq << '\n';
			cout << "Dien tich toan phan Stp = " << Stp << '\n';
			cout << "The tich V = " << V << '\n';
			cout << "Duong cheo d = " << d << '\n';
		}
	}
}
//BT4:chayham
void ch(double x, double y) {
	cin >> x;
	if (x >= 0) cout << sqrt(x) << '\n';
	else cout << "Error.\n";

	cin >> y;
	if (x > 0) cout << pow(x, y) << '\n';
	else cout << "Error.\n";

	cout << log(x) << '\n';
	cout << log10(x) << '\n';

	int A;
	cin >> A;
	cout << abs(A) << '\n';
	long long B;
	cin >> B;
	cout << fabs(B) << '\n'; // tri tuyet doi cua so thuc: float
	double C;
	cin >> C;
	cout << fabs(C) << '\n';

	cout << cos(x) << '\n';
	cout << sin(x) << '\n';
	cout << tan(x) << '\n';
	cout << 1.0 / tan(x) << '\n'; // cot(x)

	if (x >= -1 && x <= 1) cout << acos(x) << '\n';
	else cout << "Error.\n";
	if (x >= -1 && x <= 1) cout << asin(x) << '\n';
	else cout << "Error.\n";
	cout << atan(x) << '\n';

	cout << floor(x) << '\n';
	cout << ceil(x) << '\n';
}
//BT5:phuongtrinhbacnhat
void ptbn(double a, double b) {
	cin >> a >> b;
	if (a == 0) { // if (!a)
		if (b == 0) cout << "Vo so nghiem.\n";
		else cout << "Vo nghiem.\n";
	} else {
		if (b == 0) cout << "x = 0.\n";
		else cout << "x = " << - b / a << "\n";
	}
}
//BT6:phuongtrinhbachai
void ptbh(double a, double b, double c) {
	cin >> a >> b >> c;
	if (a == 0) {
		if (b == 0) {
			if (c == 0) cout << "Vo so nghiem.\n";
			else cout << "Vo nghiem.\n";
		} else {
			if (c == 0) cout << "x = 0.\n";
			else cout << "x = " << - c / b << "\n";
		}
	} else { // a != 0
		double Delta = b * b - 4 * a * c;
		if (Delta < 0) {
			cout << "Phuong trinh co 2 nghiem phuc x1 = " << -b / (2 * a) << " - i" << sqrt(fabs(Delta)) / (2 * a) << " & ";
			cout << "x2 = " << -b / (2 * a) << " + i" << sqrt(fabs(Delta)) / (2 * a) << '\n';
		} else if (Delta == 0) {
			cout << "Phuong trinh co nghiem kep x = " << -b / (2 * a) << '\n';
		} else { // Delta > 0
			cout << "Phuong trinh co 2 nghiem thuc x1 = " << (-b - sqrt(Delta)) / (2 * a) << " & x2 = " << (-b + sqrt(Delta)) / (2 * a) << '\n';
		}
	}
}
//BT7: min max
void mm(double a, double b, double c) {
	double vmax, vmin;

	cout << "Nhap a = ";
	cin >> a;
	cout << "Nhap b = ";
	cin >> b;
	cout << "Nhap c = ";
	cin >> c;
	//tìm max
	if (a >= b && a >= c)
		vmax = a;
	else if (b >= a && b >= c)
		vmax = b;
	else
		vmax = c;

	cout << "Max trong 3 so thuc cho truoc = " << vmax << endl;

	// Tim min
	if (a <= b && a <= c)
		vmin = a;
	else if (b <= a && b <= c)
		vmin = b;
	else
		vmin = c;

	cout << "Min trong 3 so thuc cho truoc = " << vmin << endl;
}
//BT8:
void DD(int n, int sduong, int sam, int s0) {
	cout << "n: ";
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	s0 = 0;
	sduong = 0;
	sam = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			s0++;
		} else if (a[i] > 0) {
			sduong++;
		} else sam++;
	}
	cout << "Số số 0: " << s0 << '\n';
	cout << "Số số âm: " << sam << '\n';
	cout << "Số số dương: " << sduong << '\n';
}
//BT9: chẵn lẻ
void cl (int n, int m) {
	cin >> n;

	int demChan = 0, demLe = 0;

	for (int i = 1; i <= n; i++) {
		cin >> m;
		if (m % 2 == 0)
			demChan++;
		else
			demLe++;
	}

	cout << demChan << endl;
	cout << demLe << endl;
}
//BT10:
void DE(int n) {
	cout << "Nhap so (0-20): ";
	cin >> n;
	switch (n) {
	case 0:
		cout << "Zero";
		break;
	case 1:
		cout << "One";
		break;
	case 2:
		cout << "Two";
		break;
	case 3:
		cout << "Three";
		break;
	case 4:
		cout << "Four";
		break;
	case 5:
		cout << "Five";
		break;
	case 6:
		cout << "Six";
		break;
	case 7:
		cout << "Seven";
		break;
	case 8:
		cout << "Eight";
		break;
	case 9:
		cout << "Nine";
		break;
	case 10:
		cout << "Ten";
		break;
	case 11:
		cout << "Eleven";
		break;
	case 12:
		cout << "Twelve";
		break;
	case 13:
		cout << "Thirteen";
		break;
	case 14:
		cout << "Fourteen";
		break;
	case 15:
		cout << "Fifteen";
		break;
	case 16:
		cout << "Sixteen";
		break;
	case 17:
		cout << "Seventeen";
		break;
	case 18:
		cout << "Eighteen";
		break;
	case 19:
		cout << "Nineteen";
		break;
	case 20:
		cout << "Twenty";
		break;
	default:
		if (n < 0) {
			cout << "Khong hop le" << endl;
		} else {
			cout <<  "Khong nhap so > 20" << endl;
		}
		break;
	}
	cout << endl;
}
//BT11:
void HH(double a, double b, double c, double A, double B, double C, double x, double y) {
	cin >> a >> b >> c >> A >> B >> C;
	y = (c * B - b * C) / (a * B - b * A);
	x = (c - (b * y)) / a;
	if (a * B - A * b != 0) {
		cout << "He co 1 nghiem duy nhat:\n";
		cout << "x = " << y << ", y = " << x << endl;
	} else {
		if (c * B - C * b == 0 && a * C - A * c == 0) {
			cout << "He co vo so nghiem" << endl;
		} else {
			cout << "He vo nghiem" << endl;
		}
	}
}
//BT12:
void Su(int m, int n) {
	double Sm = 0;
	cin >> m >> n;
	if (m == 0) Sm = n;
	for (int i = 1; i <= n; ++i) Sm += pow(i, m);
	cout << "Sm = " << Sm << '\n';
}
//BT13:
void st(int m, int M) {
// 1st solution
	double Sm = 0; // khai báo biến Sm & khởi tạo giá trị 0. kiểu dữ liệu double vì khi m < 0, Sm là số thực
	int i = 1;
	cin >> m >> M;
	while (Sm <= M) {
		Sm += pow(i, m);
		++i;
	}
	cout << Sm - pow(i, m);

	// 2nd solution
	Sm = 0;
	for (i = 1; i <= 10000; ++i) {
		if (Sm > M) break;
		else Sm += pow(i, m);
	}
	cout << Sm - pow(i, m);
}
//BT14:
void nh(double A, double a) {
	cin >> A >> a;
	if (a > A) cout << "Số tiền rút lớn hơn số dư khả dụng. Bạn bị ảo tưởng sức mạnh tài chính à?";
	else {
		string real_password, input_password;
		cin >> real_password; // 6 digits, from 0 to 9
		int max_trial;
		cin >> max_trial;
		bool ok = false;
		for (int i = 1; i <= 5; ++i) {
			cin >> input_password;
			if (input_password == real_password) {
				ok = true;
				break;
			}
		}
		if (ok) cout << "Mã PIN đúng. Cho rút tiền.\n";
		else cout << "Bạn đã bị khóa thẻ.\n";
	}
}
int main () {
	// BT1: hinh vuong
	double a;
	cin >> a;
	hinh_vuong(a);
	//BT2: hinh chu nhat
	double b;
	cin >> b;
	hinh_chu_nhat(a, b);
	//BT3: hinh hop chu nhat
	double c;
	cin >> c;
	hinh_hop_chu_nhat(a, b, c);
	//BT4: chay ham
	double x, y;
	cin >> x >> y;
	ch(x, y);
	//BT5: phuong trinh bac nhat
	ptbn(a, b);
	//BT6: phuong trinh bac hai
	ptbh(a, b, c);
	//BT7: min max
	mm(a, b, c);
	//BT8:
	int n, sduong, sam, s0;
	cin >> n >> sduong >> sam >> s0;
	DD(n, sduong, sam, s0);
	//BT9: chan le
	int m;
	cin >> m ;
	cl(n, m);
	//BT10:
	DE(n);
	//BT11:
	double A, B, C;
	cin >> A >> B >> C;
	HH(a, b, c, A, B, C, x, y);
	//BT12:
	Su(m, n);
	//BT13:
	int M;
	cin >> M;
	st(m, M);
	//BT14:
	nh(A, a);
}

