#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//BT1
void chuvi_dientichhinhvuong(double a) {
    double S = a * a ;
    cout << "Dien tich hinh vuong la: " << S << endl ;
    double P = 4 * a ;
    cout << "Chu vi hinh vuong la: " << P << endl ;
}

//BT2
void hinhchunhat(double a, double b) {
    double S = a * b ;
    cout << "Dien tich hinh chu nhat la: " << S << endl ;
    double P = 2 * (a + b) ;
    cout << "Chu vi hinh chu nhat la: " << P << endl ;
    double d = sqrt(a * a + b * b) ;
    cout << "Do dai duong cheo hinh chu nhat la: " << d << endl ;
}
//BT3
void kiemtrahinhlapphuong(double a , double b , double c) {
    if (a <= 0 || b <= 0 || c <= 0) cout << "-1\n";
    else {
        if (a > 0 && a == b && b == c) { // case HLP
            cout << "HLP\n";
            double Sxq = 4 * a * a, Stp = 6 * a * a, V = a * a * a, d = sqrt(3) * a;
            cout << "Dien tich xung quanh Sxq = " << Sxq << '\n';
            cout << "Dien tich toan phan Stp = " << Stp << '\n';
            cout << "The tich V = " << V << '\n';
            cout << "Duong cheo d = " << d << '\n';

        } else { // case HHCN
            cout << "HHCN\n";
            double Sxq = 2 * (a + b) * c, Stp = 2 * (a * b + b * c + c * a), V = a * b * c, d = sqrt(a * a + b * b + c * c);
            cout << "Dien tich xung quanh Sxq = " << Sxq << '\n';
            cout << "Dien tich toan phan Stp = " << Stp << '\n';
            cout << "The tich V = " << V << '\n';
            cout << "Duong cheo d = " << d << '\n';
        }
    }
}
//BT5
void giaphuongtrinhbacnhat(double a, double b ) {
    if (a == 0 && b == 0) {
        cout << "phuong trinh vo so nghiem" << endl ;
    } else if (a == 0 && b != 0) {
        cout << "phuong trinh vo nghiem" << endl ;
    }
    else {
        double x = -b / a ;
        cout << "phuong trinh co nghiem duy nhat x = " << x << endl ;
    }
}
//BT6
void giaiphuongtrinhbac2(double a, double b, double c) {
    if (a == 0 && b == 0 && c == 0 )
    {
        cout << "phuong trinh vo so nghiem" << endl ;
    }
    else if ( a == 0 && b == 0 && c != 0 )
    {
        cout << "phuong trinh vo nghiem" << endl ;
    }
    else if ( a == 0 && b != 0 )
    {
        double x = -c / b ;
        cout << "phuong trinh co nghiem duy nhat x = " << x << endl ;
    }
    else
    {
        double delta = b * b - 4 * a * c ;
        if ( delta < 0 )
        {
            cout << "phuong trinh vo nghiem" << endl ;
        }
        else if ( delta == 0 )
        {
            double x = -b / (2 * a) ;
            cout << "phuong trinh co nghiem kep x1 = x2 = " << x << endl ;
        }
        else
        {
            double x1 = ( -b + sqrt ( delta ) ) / ( 2 * a ) ;
            double x2 = ( -b - sqrt ( delta ) ) / ( 2 * a ) ;
            cout << "phuong trinh co hai nghiem phan biet: " << endl ;
            cout << "x1 = " << x1 << endl ;
            cout << "x2 = " << x2 << endl ;
        }
    }
}
//BT7
void timmaxmin(double a, double b, double c) {
    double vmax, vmin;
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
//BT8
void demsoluong(int n) {
    int sduong, sam, s0;
    cout << "n: ";
    cin >> n;
    vector<int> a(n);
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
//BT9
void demchanle(int n) {
    int demChan = 0, demLe = 0;
    int a;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a % 2 == 0)
            demChan++;
        else
            demLe++;
    }

    cout << demChan << endl;
    cout << demLe << endl;
}
//BT10
void chuyensangchu(int n) {
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
//BT11
void hephuongtrinh(double a, double b, double c, double A, double B, double C) {
    double x, y;
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
//BT12
void tongmucthu(int n, int m) {
    double s = 0;
    for (int i = 1; i <= n ; i++) {
        s = s + pow(i, m);

    }
    cout << "S = " << s;
}
//BT13
void tongmucthu2(int n, int m, int M) {
    double s = 0;
    int i;
    for (i = 1; i <= n ; i++) {
        double s2 = pow(i, m);
        if (s + s2 <= M) {
            s = s + s2;
        } else {
            break;
        }
    }
    cout << "S = " << s;
}
//BT14
void ruttien() {
    double A, a;
    cin >> A >> a;
    if (a > A) cout << "Số tiền rút lớn hơn số dư khả dụng. Bạn bị ảo tưởng sức mạnh tài chính à?";
    else {
        string real_password, input_password;
        cin >> real_password; // 6 digits, from 0 to 9
        int max_trial;
        cin >> max_trial;
        bool ok = false;
        for (int i = 1; i <= max_trial; ++i) {
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
int main() {
//BT1
    double a;
    cin >> a;
    chuvi_dientichhinhvuong(a);
//BT2
    double b;
    cin >> a >> b;
    hinhchunhat(a, b);
//BT3
    double c;
    cin >> a >> b >> c;
    kiemtrahinhlapphuong(a, b, c);
//BT5
    cin >> a >> b;
    giaphuongtrinhbacnhat(a, b);
//BT6
    cin >> a >> b >> c;
    giaiphuongtrinhbac2(a, b, c);
//BT7
    cin >> a >> b >> c;
    timmaxmin(a, b, c);
//BT8
    int n;
    cin >> n;
    demsoluong(n);
//BT9
    cin >> n;
    demchanle(n);
//BT10
    cin >> n;
    chuyensangchu(n);
//BT11
    double A, B, C;
    cin >> a >> b >> c >> A >> B >> C;
    hephuongtrinh(a, b, c, A, B, C);
//BT12
    int m;
    cin >> n >> m;
    tongmucthu(n, m);
//BT13
    int M;
    cin >> n >> m >> M;
    tongmucthu2(n, m, M);
//BT14
    ruttien();
}
