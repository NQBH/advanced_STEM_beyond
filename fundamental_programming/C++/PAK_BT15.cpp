#include <bits/stdc++.h>
using namespace std;

void hv (long long a) {
    if (a <= 0)
    {
        cout << " Nhập sai giá trị, cạnh phải lớn hơn 0 ";
    }
    else {
        double C, S;
        C = 4 * a;
        S = pow(a, 2);
        cout << "Chu vi của hình vuông cạnh r = " << a << " bằng " << C << '\n';
        cout << "Diện tích của hình vuông cạnh r = " << a << " bằng " << S << '\n';
    }
}

void hcn (long long cd, long long cr) {
    if (cd <= 0 || cr <= 0) {
        cout << " Nhập sai giá trị, cạnh phải lớn hơn 0 ";
    }
    else {
        float C, S, dck;
        C = (cd + cr) * 2;
        S = cd * cr;
        dck = sqrt(pow(cd, 2) + pow(cr, 2));
        cout << "Chu vi của hình chữ nhật : " << C << '\n';
        cout << "Diện tích của hình chữ nhật : " << S << '\n';
        cout << "Độ dài cạnh chéo của hình chữ nhật : " << dck << "\n";
    }
}
void CheckShapeAndArea(long long a, long long b, long long h) {
    if ( a <= 0 || b <= 0 || h <= 0) {
        cout << "-1";
    }
    else if (a > 0 && b > 0 && h > 0) {
        string shape;
        if (a == b && b == h) {cout << " HLP" << '\n'; shape = "HLP";}
        else {cout << " HHCN" << '\n'; shape = "HHCN";}
        float dtxq, dttp, duongcheo, thetich, duongcheoday;
        dtxq = a * h * 2 + b * h * 2;
        dttp = dtxq + a * b * 2;
        duongcheoday = sqrt(pow(a, 2) + pow(b, 2));
        duongcheo = sqrt(pow(duongcheoday, 2) + pow(h, 2));
        thetich = a * b * h;
        cout << "Diện tích xung quanh của " << shape << " : " << dtxq << '\n';
        cout << "Diện tích toàn phần của " << shape << " : " << dttp << '\n';
        cout << "Đường chéo của " << shape << " : " << duongcheo << '\n';
        cout << "Thể tích của " << shape << " : " << thetich << '\n';
    }
    else {cout << "-1" ;}
}

void CheckFunction(double x, double y) {
    if (x < 0) {
        cout << "ERROR do x < 0\n";
    }
    else {
        cout << "căn bậc 2 của x = ";
        cout << sqrt(x) << '\n';
    }

    cout << "x lũy thừa y = ";
    cout << pow(x, y) << '\n';

    cout << "e mũ x = ";
    cout << exp(x) << '\n';


    cout << "logarit cơ số e của x = ";
    cout << log(x) << '\n';


    cout << "logarit cơ số 10 của x = ";
    cout << log10(x) << '\n';


    cout << "trị tuyệt đối của số nguyên x = ";
    cout <<  abs(x) << '\n';

    cout << "trị tuyệt đối của số nguyên dài (long) x = ";
    cout << labs(x) << '\n';

    cout << "trị tuyệt đối của số thực (double) x = ";
    cout << fabs(x) << '\n';

    cout << "giá trị cos(x) = ";
    cout << cos(x) << '\n';

    cout << "giá trị sin(x) = ";
    cout << sin(x) << '\n';


    cout << "giá trị tan(x) = ";
    cout << tan(x) << '\n';


    cout << "giá trị góc arccos(x) = ";
    cout << acos(x) << '\n';

    cout << "giá tr5ị góc arcsin(x) = ";
    cout << asin(x) << '\n';

    cout << "giá trị góc arctg(x) = ";
    cout << atan(x) << '\n';


    cout << "Làm tròn xuống x = ";
    cout << floor(x) << '\n';


    cout << "làm tròn lên x = ";
    cout << ceil(x) << '\n';

}

void SolveEquation1(double a, double b) {
    cout << "Phương trình ta có : " << a << "x + " << b << " = 0" << '\n';
    if (a == 0) {
        if (b == 0 ) { cout << "Phương trình có vô số nghiệm";}
        else { cout << " Phương trình vô nghiệm "; }
    }
    else {
        cout << "Phương trình có nghiệm là x = " << -b / a << '\n';
    }
}

void SolveEquation2(double a, double b, double c) {
    cout << "Phương trình ta có : " << a << "x^2 + " << b << "x + " << c << " = 0" << '\n';
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {cout << "Phương trình có vô số nghiệm";}
        }
        else {cout << "Phương trình vô nghiệm";}
    }
    else {
        double delta = pow(b, 2) - 4 * a * c;
        if (delta < 0) {
            cout << "Phương trình vô nghiệm";
        }
        else if (delta == 0) {
            cout << "Phương trình có 1 nghiệm kép x = " << -b / (2 * a) << '\n';
        }
        else if (delta > 0) {
            cout << "Phương trình có 2 nghiệm phân biệt :";
            double x1 = (-b - sqrt(delta)) / (2 * a);
            double x2 =  (-b + sqrt(delta)) / (2 * a);
            cout << "x1 = " << x1 << " và x2 = " << x2 << '\n';
        }
    }
}
void CheckMaxMin(long long a, long long b, long long c) {
    int maxnumb, minnumb;
    maxnumb = a; minnumb = a;
    if (b > maxnumb) {maxnumb = b;}
    if (c > maxnumb) {maxnumb = c;}
    if (b < minnumb) {minnumb = b;}
    if (c < minnumb) {minnumb = c;}
    cout << "Số lớn nhất trong ba số : " << maxnumb << '\n';
    cout << "Số nhỏ nhất trong ba số : " << minnumb << '\n';

}
void CheckAmDuong (long long N) {
    int soduong, soam, sokhong;
    soduong = 0; soam = 0; sokhong = 0;
    cout << "Nhập " << N << "số : ";
    for (int i = 1; i <= N ; i++ ) {
        int n ; cin >> n;
        if (n > 0) {soduong++;}
        else if (n < 0) {soam++;}
        else {sokhong++;}
    }
    cout << "so luong so 0 : " << sokhong << '\n';
    cout << "so luong so duong : " << soduong << '\n';
    cout << "so luong so am : " << soam << '\n';
}
void CheckChanLe(long long N) {
    int sochan, sole;
    sochan = 0 ; sole = 0;
    cout << "Nhập " << N << " số : ";
    for (int i = 1; i <= N; i++) {
        int n; cin >> n;
        //n % 2 == 0 ? sochan++ : sole++;
        if (n % 2 == 0) {sochan++;}
        else {sole++;}
    }
    cout << "số lượng số chẵn : " << sochan << '\n';
    cout << "số lượng số lẻ : " << sole << '\n';
}

void CountTo20() {
    for (int i = 0; i <= 20; i++ ) {
        int n = i;
        switch (n) {
        case 0: cout << " Zero"; break;
        case 1: cout << " One"; break;
        case 2: cout << " Two"; break;
        case 3: cout << " Three"; break;
        case 4: cout << " Four"; break;
        case 5: cout << " Five"; break;
        case 6: cout << " Six"; break;
        case 7: cout << " Seven"; break;
        case 8: cout << " Eight"; break;
        case 9: cout << " Nine"; break;
        case 10: cout << " Ten"; break;
        case 11: cout << " Eleven"; break;
        case 12: cout << " Twelve"; break;
        case 13: cout << " Thirteen"; break;
        case 14: cout << " Fourteen"; break;
        case 15: cout << " Fifteen"; break;
        case 16: cout << " Sixteen"; break;
        case 17: cout << " Seventeen"; break;
        case 18: cout << " Eighteen"; break;
        case 19: cout << " Nineteen"; break;
        case 20: cout << " Twenty"; break;
        }
    }
}

void Check2Lines(long long a, long long b, long long c, long long A, long long B, long long C) {
    cout << "Hệ Phương trình ta thu được gồm 2 phương trình\n";
    if (b < 0) {
        cout << a << "x " << b << "y = " << c << '\n';
    }
    else {cout << a << "x + " << b << "y = " << c << '\n';}
    if (B < 0) {
        cout << A << "x " << B << "y = " << C << '\n';
    }
    else {cout << A << "x + " << B << "y = " << C << '\n';}


    if (A != 0 && B != 0 && C != 0) {
        if (a / A == b / B && a / A == c / C) {cout << "Phương trình có vô số nghiệm";}
        if (a / A == b / B && a / A != c / C) {cout << "Phương trình vô nghiệm";}
    }
    else if (a != 0 && b != 0 && c != 0) {
        if (A / a == B / b && A / a == C / c) {cout << "Phương trình có vô số nghiệm";}
        if (A / a == B / b && A / a != C / c) {cout << "Phương trình vô nghiệm"; }
    }
    else {
        long long y = (a * C - A * c) / (a * B - A * b);
        long long x = (c - b * y) / a;
        cout << "Nghiệm của phương trình trên : x = " << x << " và y = " << y;
    }
}

void TongGiaiThua(long long n, long long m) {
    double Sm = 0;
    long long temp;
    for (int i = 1; i <= n; ++i ) {
        temp = 1;
        if (m > 0) {
            for (int j = 1; j <= m; j++) {
                temp *= i;
            }
            Sm += temp;
        }
        else {
            for (int j = 1; j <= -m; j++) {
                temp *= i;
            }
            Sm += (double)1 / temp;
        }
    }
    cout << Sm;
}
void TongGiaiThuaCoGioiHan(long long n, long long m, long long M) {
    double Sm = 0;
    long long i = 1, temp;
    while (i <= n) {
        long long mu;
        temp = 1;
        if (m < 0) {mu = - m;}
        else {mu = m;}
        while (mu--) {temp *= i;}{
            if (Sm + temp <= M) {
                if ( m >= 0) {Sm += temp;}
                else  {Sm += (double) 1 / temp;}
            }
            else {break;}
        }
        i++;
    }
    cout << Sm;
}

void Bank(long long A, long long a, long long max_trial) {
    string PIN = "123456";
    string PIN_nguoc = "654321";
    while (max_trial--) {
        string YOURPIN;
        cout << "NHẬP MÃ PIN 6 SỐ CỦA BẠN : ";
        cin >> YOURPIN;
        if (YOURPIN == PIN) {
            if (a <= A) {
                cout << "RÚT TIỀN THÀNH CÔNG" << '\n';
                cout << "SỐ DƯ CÒN LẠI : " << A - a << "VND";
                break;
            }
            else {
                cout << "Số tiền rút lớn hơn số dư khả dụng. Bạn bị ảo tưởng sức mạnh tài chính à?"; break;
            }
        }
        else if (YOURPIN == PIN_nguoc) {
            cout << "ĐÃ BÁO VỚI SECURITY!"; break;
        }
        else {continue;}
    }
    if (max_trial == -1) {cout << "THẺ ĐÃ BỊ KHÓA" ;}
}

int main() {
    long long chv;
    cout << "Nhập cạnh hình vuông : ";
    cin >> chv;
    hv (chv);

    long long cdhcn, crhcn;
    cout << "Nhập chiều dài HCN : ";
    cin >> cdhcn;
    cout << "Nhập chiều rộng HCN : ";
    cin >> crhcn;
    hcn (cdhcn, crhcn);

    long long a, b, h;
    cout << "Nhập độ dài 3 cạnh : ";
    cin >> a >> b >> h;
    CheckShapeAndArea (a, b, h);

    long long x, y;
    cout << "Nhập hai số thực";
    cin >> x >> y;
    CheckFunction(x, y);

    double a1, b1, c1;
    cout << "Nhập hệ số của phương trình : ";
    cin >> a1 >> b1 >> c1;
    SolveEquation1(a1, b1);
    SolveEquation2(a1, b1, c1); cout << '\n';

    long long a2, b2, c2;
    cout << "Nhập 3 số bất kì : ";
    cin >> a2 >> b2 >> c2;
    CheckMaxMin(a2, b2, c2);

    long long N;
    cout << "Nhập số lượng số : ";
    cin >> N;
    CheckAmDuong(N);
    CheckChanLe(N);
    CountTo20(); cout << '\n';

    long long a3, b3, c3, A3, B3, C3;
    cout << "Nhập hệ số của đường thẳng 1 : ";
    cin >> a3 >> b3 >> c3;
    cout << "Nhập hệ số của đường thẳng 2 : ";
    cin >> A3 >> B3 >> C3;
    Check2Lines(a3, b3, c3, A3, B3, C3); cout << '\n';

    long long n, m, M;
    cout << "Nhập 3 số :";
    cin >> n >> m >> M;
    TongGiaiThua(n, m); cout << '\n';
    TongGiaiThuaCoGioiHan(n, m, M); cout << '\n';

    long long A4, a4, max_trial;
    cout << "Nhập Số tiền tài khoản hiện có : "; cin >> A4 ;
    cout << "Nhập Số tiền muốn rút : "; cin >> a4 ;
    cout << "Nhập Số lần được nhập pin sai : "; cin >> max_trial ;
    Bank(A4, a4, max_trial);
}