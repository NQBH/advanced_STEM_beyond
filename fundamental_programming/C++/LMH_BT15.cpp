#include <iostream>;
#include <cmath>;
using namespace std;

void bt1(long long a) {
	double DT = a * a;
	double CV = 4 * a;
	cout << DT << " " << CV << " " << endl;
}
void bt2(long long b, long long c) {
	cout << 2 * (c + b) << ' '  << c * b << ' ' << " Ðg Cheo =  " << sqrt(b * b + c * c) << endl;
}
void bt3(long long a, long long  b, long long c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		cout << "không có hình" << endl;
	}
	else if (a == b && b == c && a == c) {
		cout << "HLP" << endl;
	}
	else if (a == b && a != c || b == c && c != a) {
		cout << "HHCN" << endl;
		cout << "dg chéo =" <<	sqrt(a * a + b * b + c * c ) << endl;
		cout << "DTXQ =" << (a + b) * 2 * c << endl;
		cout << "DTTP =" << (a + b) * 2 * c + 2 * a*b << endl;
		cout << "TT = " << a*b*c << endl;
	}
	else {
		cout << "-1" << endl;
	}
}
void bt4(long long x, long long y, long long e, long long pi) {
	if (x < 0) {
		cout << "error" << '\n';
	}
	else {
		cout << "can bac 2 cua x = " << sqrt(x) << endl;
	}
	if (x <= 0) {
		cout << "error" << '\n';
	}
	else {
		cout << " x^y = " << pow(x, y) << endl;
		cout << "log10(x)= " << log10(x) << endl;
		cout << "log(x)= " << log(x) << endl;
	}
	e = 2.71828;
	cout << "e^x = " << pow(e, x) << endl;
	cout << "|x|= " << abs(x) << endl;
	pi = 3.14159;

	cout << "sin(x)= " << sin(x) << endl;
	cout << "cos(x)= " << cos(x) << endl;
	cout << "tan(x)= " << tan(x) << endl;
	if (-1 <= x <= 1) {
		cout << "arcsin(x): " << asin(x) << endl;
		cout << "arccos(x): " << acos(x) << endl;
		cout << "arctan(x): " << atan(x) << endl;
	}
	else {
		cout << "error";
	}
	cout << "so nguyen lon nhat khong vuot qua x = " << floor(x) << endl;
	cout << "so nguyen nho nhat hay bang x = " << ceil(x) << endl;
}

void bt5( long long a, long long b, long long x ) {
	a*x + b == 0;
	if (a != 0) {
		x = -b / a;
		cout << "x = " << x << endl;
	}
	else if (a == 0 && b != 0) {
		cout << "vô nghiem " << endl;
	}
	else if (a == 0 && b == 0)
	{
		cout << "vo so nghiem" << endl;
	}
}

void bt6(long long a, long long b, long long c, long long d, long long x) {
	if (a == 0) {
		if (b != 0) {
			x = -c / b;
			cout << "x = " << x << endl;
		}
		else if (b == 0 && c != 0) {
			cout << "vô nghiem " << endl;
		}
		else if (b == 0 && c == 0)
		{
			cout << "vo so nghiem" << endl;
		}
	}
	else {
		d = b * b - 4 * a * c;
		if (d < 0) {
			cout << "pt ko co nghiem thuc ,có nghiem phuc" << endl;
			cout << "x1 = " << (-b + sqrt(-d)) / (2 * a) << endl;
			cout << "x2 = " << (-b - sqrt(-d)) / (2 * a) << endl;
		}
		else if (d == 0) {
			cout << "phuong trinh có nghiem kép  = " << -b / (2 * a) << endl;
		}
		else {
			cout << "pt có 2 nghiem thuc " << endl;
			cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << endl;
			cout << "x2 = " << (-b - sqrt(d)) / (2 * a) << endl;
		}
	}
}

void bt7(long long n, long long N, long long max, long long min) {
	cout << "nhap so luong so thuc "; cin >> n;
	if (n <= 0) {
		cout << "error" << endl;
	}
	cout << "so thuc dau  = "; cin >> N;
	max = N;
	min = N;
	for (int i = 1; i <= n; ++i) {
		cout << "nhap so thuc thu tiep theo " << i << "= "; cin >> N;
		if (max < N) {
			max = N;
		}
		if (min > N) {
			min = N;
		}
	}
	cout << "max = " << max << endl;
	cout << "min = " << min << endl;
}

void bt8(long long a, long long soDuong, long long soAm, long long so0, long long n) {
	cout << "nhap cac so thuc a : "; cin >> n;
	if (
	    n <= 0) {
		cout << "khong hop le";
	}
	else {
		for (int i = 1; i <= n; ++i) {
			cout << "so thuc a " << i << " = "; cin >> a;
			if (a > 0) {
				soDuong++;
			}
			else if (a < 0) {
				soAm++;
			}
			else {
				so0++;
			}
		}
		cout << "so so duong la : " << soDuong << endl;
		cout << "so so am la : " << soAm << endl;
		cout << "so so 0 la : " << so0 << endl;
	}
}
void bt9(long long a, long long n, long long chan, long long le) {
	cout << " nhap so luong so thuc = "; cin >> n;
	if (n <= 0) {
		cout << "error" << endl;
	}
	else {

		for (int i = 1; i <= n; ++i) {
			cout << "nhap so thuc a " << i << " = "; cin >> a;
			if (a % 2 == 0) {
				chan++;
			}
			else {
				le++;
			}

		}
		cout << "so so chan la : " << chan << endl;
		cout << "so so le la : " << le << endl;
	}
}
void bt10(long long i) {
	for (int i = 0; i <= 20; ++i) {
		switch (i) {
		case 0: cout << "zero" << endl; break;
		case 1: cout << "one" << endl; break;
		case 2: cout << "two" << endl; break;
		case 3: cout << "three" << endl; break;
		case 4: cout << "four" << endl; break;
		case 5: cout << "five" << endl; break;
		case 6: cout << "six" << endl; break;
		case 7: cout << "seven" << endl; break;
		case 8: cout << "eight" << endl; break;
		case 9: cout << "nine" << endl; break;
		case 10: cout << "ten" << endl; break;
		case 11: cout << "eleven" << endl; break;
		case 12: cout << "twelve" << endl; break;
		case 13: cout << "thirteen" << endl; break;
		case 14: cout << "fourteen" << endl; break;
		case 15: cout << "fifteen" << endl; break;
		case 16: cout << "sixteen" << endl; break;
		case 17: cout << "seventeen" << endl; break;
		case 18: cout << "eighteen" << endl; break;
		case 19: cout << "nineteen" << endl; break;
		case 20: cout << "twenty" << endl; break;
		}
	}
}
void bt11(long long a, long long  b, long long c, long long A, long long  B, long long C, long long d, long long  dx, long long dy, long long x, long long  y) {
	d = d = a * B - A * b;
	dx = c * B - C * b;
	dy = a * C - A * c;
	if (d != 0) {
		x = dx / d;
		y = dy / d;
		cout << "pt có 1 nghiem" << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}
	else if (dx == 0 && dy == 0) {
		cout << "vo so nghiem" << endl;
	}
	else {
		cout << "vo nghiem" << endl;
	}
}
void bt12(long long n, long long m, long long S) {
	for (int i = 1; i <= n; ++i)
		S += pow(i, m);
	cout << S;
}
void bt13(long long n, long long m, long long S, long long M) {
	cin >> n >> m >> M;
	for (int i = 1; i <= n; i++) {
		if (S + pow(i, m) > M) {
			break;
		}
		S += pow(i, m);
	}
	cout << S;
}
int main () {
	double a;
	cin >> a;
	if (a > 0) {
		bt1(a);
	}
	else {
		cout << "vô ngiem" << '/n';
	}
	double b, c, d;
	cout << "nhap CD và CR = ";
	cin >> b >> c;
	if (c <= 0 || b <= 0) {
		cout << "vô nghiem" << endl;
	}
	else {
		bt2(b, c) ;
	}


	cout << "nhap 3 canh a b c:" ;
	cin >> a >> b >> c;
	bt3(a, b, c);


	double x, y, e, pi;
	cout << "nhap x và y : ";
	cin >> x >> y;
	bt4(x, y, e, pi) ;

	cout << "nhap a và b : ";
	cin >> a >> b;
	bt5(a, b, x) ;

	cout << "nhap a b c:";
	cin >> a >> b >> c;
	bt6(a, b, c, d, x);

	double n, N, max, min;
	bt7(n, N, max, min);

	double soDuong, soAm, so0;
	bt8(a, soDuong, soAm, so0, n);

	double chan, le;
	bt9(a, n, chan, le);

	double i;
	bt10(i) ;

	double A, B, C, dx, dy;
	cout << "ax+by=c" << endl;
	cout << "Ax+By=C" << endl;
	cout << "nhap a = "; cin >> a;
	cout << "nhap b = "; cin >> b;
	cout << "nhap c = "; cin >> c;
	cout << "nhap A = "; cin >> A;
	cout << "nhap B = "; cin >> B;
	cout << "nhap C = "; cin >> C;
	bt11(a, b, c, A, B, C, d, dx, dy, x, y);

	double m, S;
	bt12(n, m, S);

	double M;
	bt13(n, m, S, M) ;
	return 0;
}

