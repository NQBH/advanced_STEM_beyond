#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//BT1: hình vuông
void hinh_vuong(double a) {
    if (a <= 0) cout << "-1";
    else {
        double chuvi = 4 * a; 
        cout << "Chu vi = " << chuvi << endl;
        double dientich = a * a; 
        cout << "Dien tich = " << dientich << endl;
    }
 }
 
//BT2: hình chữ nhật
void hinh_chu_nhat(double a, double b) {
    if (a <= 0 || b <= 0) cout << "-1";
    else {
        double chuvi = 2 * ( a + b );
        cout << "Chu vi = " << chuvi << endl;
        double dientich = a * b;
        cout << "Dien tich  = " << dientich << endl;
        double duongcheo = sqrt( a * a + b * b );
        cout << "Duong cheo = " << duongcheo << endl;
    }
}

//BT3: hình hộp chữ nhật
void hinh_hop_chu_nhat(double a, double b, double c) {
	if (a <= 0 || b <= 0 || c <= 0) cout << "-1\n";
	else {
		if (a > 0 && a == b && b == c) {
			cout << "HLP\n";
			double Sxq = 4 * a * a, Stp = 6 * a * a, V = a * a * a, d = sqrt(3) * a;
			cout << "Dien tich xung quanh = " << Sxq << '\n';
			cout << "Dien tich toan phan = " << Stp << '\n';
			cout << "The tich = " << V << '\n';
			cout << "Duong cheo = " << d << '\n';
		} else {
			cout << "HHCN\n";
			double Sxq = 2 * (a + b) * c, Stp = 2 * (a * b + b * c + c * a), V = a * b * c, d = sqrt(a * a + b * b + c * c);
			cout << "Dien tich xung quanh = " << Sxq << '\n';
			cout << "Dien tich toan phan = " << Stp << '\n';
			cout << "The tich = " << V << '\n';
			cout << "Duong cheo = " << d << '\n';
        }
    }
}

//BT4: chạy hàm
void chay_ham(double x, double y) {
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

//BT5: phương trình bậc nhất
void ptb1(double a, double b) {
	cin >> a >> b;
	if (a == 0) { // if (!a)
		if (b == 0) cout << "Vo so nghiem.\n";
		else cout << "Vo nghiem.\n";
	} else {
		if (b == 0) cout << "x = 0.\n";
		else cout << "x = " << - b / a << "\n";
	}
}

//BT6: phương trình bậc hai
void ptb2(double a, double b, double c) {
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
void min_max(double a, double b, double c) {
    double vmax, vmin;

    cout << "Nhap a = ";
    cin >> a;
    cout << "Nhap b = ";
    cin >> b;
    cout << "Nhap c = ";
    cin >> c;
    //Tìm max
    if (a >= b && a >= c)
        vmax = a;
    else if (b >= a && b >= c)
        vmax = b;
    else
        vmax = c;

    cout << "Max trong 3 so thuc cho truoc = " << vmax << endl;
    
    // Tìm min
    if (a <= b && a <= c)
        vmin = a;
    else if (b <= a && b <= c) 
        vmin = b;
    else
        vmin = c;

      cout << "Min trong 3 so thuc cho truoc = " << vmin << endl;
	}
	
	//BT8: đếm số 0, số âm, số dương
	void dem_so_0_so_am_so_duong(int n) {
	    cin>>n;
        double x;
        int duong=0,am=0,zero=0;
        for(int i=1;i<=n;i++){
        cin>>x;
        if(x>0) duong++;
        else if(x<0) am++;
        else zero++;
    }
    cout<<duong<<endl<<am<<endl<<zero;
}

	//BT9: chẵn lẻ
	void chan_le(int n, int m){
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

//BT10: in ra từ tiếng anh 
void in_ra_tu_tieng_anh(int n) {
    string str;
    cout << "Input n = ";
    cin >> n;
    switch(n){
        case 0: cout<<"zero"; break;
        case 1: cout<<"one"; break;
        case 2: cout<<"two"; break;
        case 3: cout<<"three"; break;
        case 4: cout<<"four"; break;
        case 5: cout<<"five"; break;
        case 6: cout<<"six"; break;
        case 7: cout<<"seven"; break;
        case 8: cout<<"eight"; break;
        case 9: cout<<"nine"; break;
        case 10: cout<<"ten"; break;
        case 11: cout<<"eleven"; break;
        case 12: cout<<"twelve"; break;
        case 13: cout<<"thirteen"; break;
        case 14: cout<<"fourteen"; break;
        case 15: cout<<"fifteen"; break;
        case 16: cout<<"sixteen"; break;
        case 17: cout<<"seventeen"; break;
        case 18: cout<<"eighteen"; break;
        case 19: cout<<"nineteen"; break;
        case 20: cout<<"twenty"; break;
        default: cout<<"Out of range";
    }
}

//BT11: hệ phương trình tuyến tính bậc hai
void hpt_tuyen_tinh_bac2(double a, double b, double c, double A, double B, double C) {
    cin>>a>>b>>c>>A>>B>>C;

    double D = a * B - A * b;
    double Dx = c * B - b * C;
    double Dy = a * C - c * A;

    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        cout << "He co nghiem duy nhat:\n";
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    } else {
        if (Dx == 0 && Dy == 0) {
            cout << "He co vo so nghiem\n";
        } else {
            cout << "He vo nghiem\n";
        }
    }
}

//BT12: tính Sm
void Sm(int m, int n) {
	double Sm = 0;
	cin >> m >> n;
	if (m == 0) Sm = n;
	for (int i = 1; i <= n; ++i) Sm += pow(i, m);
	cout << "Sm = " << Sm << '\n';
}

//BT13:tính Sm <= m
void Sm_M(int m,int M) {
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

//BT14: ATM
void ATM(double A, double a) {
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
    // BT1: hình vuông
    double a;
    cin >> a;
    hinh_vuong(a);
    //BT2: hình chữ nhật
    double b;
    cin >> b;
    hinh_chu_nhat(a,b);
    //BT3: hình hộp chữ nhật
    double c;
    cin >> c;
    hinh_hop_chu_nhat(a,b,c);
    //BT4: chạy hàm
	double x,y;
	cin >> x >> y;
	chay_ham(x,y);
	//BT5: phương trình bậc nhất
	ptb1(a,b);
	//BT6: phương trình bậc hai
	ptb2(a,b,c);
	//BT7: min max
	min_max(a,b,c);
	//BT8: đếm số 0, số âm, số dương
	int n;
	cin >> n;
	dem_so_0_so_am_so_duong(n);
	//BT9: chẵn lẻ
	int m;
	cin >> m ;
	chan_le(n,m);
	//BT10: in ra từ tiếng anh
	string str;
	in_ra_tu_tieng_anh(n);
	//BT11: hệ phương trình tuyến tính bậc hai
	double A,B,C;
    cin >> A >> B >> C;
    hpt_tuyen_tinh_bac2(a,b,c,A,B,C);
	//BT12: tính Sm
	Sm(m,n);
	//BT13: tính Sm <= m
	int M;
	cin >> M;
	Sm_M(m,M);
	//BT14: ATM
	ATM(A,a);

}