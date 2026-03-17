#include <iostream>
#include <cmath>
using namespace std;


void problem_1(int canh) {
    if (canh > 0) {
        float C = canh * 4;
        float S = canh * canh;
        cout << "Chu vi hinh vuong la " << C << '\n';
        cout << "Dien tich hinh vuong la " << S << '\n';
    }
    else {
        cout << "Vui long nhap so thuc duong" << '\n';
    }
}

void problem_2(float dai, float rong) {
    if (dai > 0 && rong > 0) {
        double C = (dai + rong) * 2;
        double S = dai * rong;
        float cheo = sqrt(dai * dai + rong * rong);
        cout << "Chu vi cua hinh chu nhat la " << C << '\n';
        cout << "Dien tich cua hinh chu nhat la " << S << '\n';
        cout << "Do dai duong cheo hinh chu nhat la " << cheo << '\n';
    }
    else {
        cout << "Vui long nhap so thuc duong \n";
    }
}

void problem_3(float a, float b, float c) {
    if (a > 0 && b > 0 && c > 0) {
        if (a == b && b == c) {
            cout << "HLP" << '\n';
        }
        else {
            cout << "HHCN" << '\n';
        }
        // Gia su chieu cao cua HHCN la c
        double DTXQ = (a * c + b * c) * 2;
        double DTTP = (a * b + b * c + c * a) * 2;
        double CHEO = sqrt(a * a + b * b + c * c);
        double V = a * b * c;
        cout << "Dien tich xung quanh la " << DTXQ << '\n';
        cout << "Dien tich toan phan la " << DTTP << '\n';
        cout << "Do dai duong cheo la " << CHEO << '\n';
        cout << "The tich la " << V << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}

void problem_4(double x, double y) {
    // can bac hai
    if (x >= 0) cout << sqrt(x) << endl;
    else cout << "khong the tinh can bac hai cua x" << endl;

    // luy thua
    cout << pow(x, y) << endl;

    // e^x
    cout << exp(x) << endl;

    // logarit co so e cua x
    cout << log(x) << endl;

    // logarit co so 10 cua x
    cout << log10(x) << endl;

    // tinh gia tri tuyet doi cua x
    int a; cin >> a;
    long b; cin >> b;
    cout << abs(a) << endl;
    cout << labs(b) << endl;
    cout << fabs(x) << endl;

    // luong giac
    cout << cos(x) << endl;
    cout << sin(x) << endl;
    cout << tan(x) << endl;

    // luong giac nguoc
    cout << acos(x) << endl;
    cout << asin(x) << endl;
    cout << atan(x) << endl;

    // lam tron
    cout << floor(x) << endl;
    cout << ceil(x) << endl;
}

void problem_5(float a, float b) {
    if (a != 0 ) {
        cout << "x= " << -b / a << endl;
    }
    else {
        if (b == 0) cout << "phuong trinh co vo so nghiem" << endl;
        else cout << "phuong trinh vo nghiem" << endl;
    }
}

void problem_6(float a, float b, float c) {
    if (a == 0) {
        if (b != 0) {
            if (c == 0) cout << "x= 0" << endl;
            else cout << "x= " << -c / b << endl;
        }
        else {
            if (c == 0) cout << "phuong trinh co vo so nghiem" << endl;
            else cout << "phuong trinh vo nghiem" << endl;
        }
    }
    else {
        float del = b * b - 4 * a * c;
        float thuc = -b / (2 * a), ao = sqrt(abs(del)) / (2 * a);
        if (del > 0) {
            cout << "x1= " << thuc + ao << endl;
            cout << "x2= " << thuc - ao << endl;
        }
        else if (del == 0) cout << "x= " << thuc << endl;
        else {
            ao = abs(ao);
            cout << "x1= " << thuc << "+" << ao << "i" << endl;
            cout << "x2= " << thuc << "-" << ao << "i" << endl;
        }
    }
}

void problem_7(long long a, long long b) {
    long long tong = a + b, hieu = a - b, tich = a * b;
    cout << tong << " " << hieu << " " << tich << " ";
    if (!b) cout << "division by zero";
    else cout << a / b << endl;
}

void problem_8(long long a, long long b) {
    if (a <= 0 || b <= 0) cout << "-1";
    else {
        long long chu_vi = (a + b) * 2;
        long long dien_tich = a * b;
        cout << chu_vi << " " << dien_tich;
    }
}

void problem_9(long long a, long long b) {
    if (!a) {
        if (!b) cout << "infinity";
        else cout << 0;
    } else cout << 1;
}

void problem_10(long long a, long long b, long long c) {
    if (!a) {
        if (!b) {
            if (!c) cout << "infinity";
            else cout << 0;
        } else cout << 1;
    } else {
        long long delta = b * b - 4 * a * c;
        if (delta > 0) cout << 2;
        else if (!delta) cout << 1;
        else cout << 0;
    }
}

void problem_11(int n) {
    int a, even = 0, odd = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a & 1) ++odd;
        else ++even;
    }
    cout << even << ' ' << odd;
}

void problem_12(int n, int m) {
    double S = 0;
    for (int i = 1; i <= n; i++) {
        S += pow(i, m);
    }
    cout << S << endl;
}

void problem_13(int m, double M) {
    double S = 0;
    int i = 1;
    while (S <= M) {
        S += pow(i, m);
        i++;
    }
    cout << S - pow(i, m) << endl;
}

void problem_14(long long A) {
    long long a;
    cout << "Số dư còn lại là: " << A << endl;
    string b, PIN = "084989";
    int i = 1;
    while (1) {
        cout << "Nhập số tiền cần rút: " ;
        cin >> a;
        if (a > A) cout << "Số tiền rút lớn hơn số dư khả dụng. Bạn bị ảo tưởng sức mạnh tài chính à?" << endl;
        else {
            cout << "#số lần thử: ";
            int max_trial; cin >> max_trial;
            while (max_trial - (i - 1) > 0) {
                cout << "Nhập mã PIN: ";
                cin >> b;
                if (b != PIN && b != "989480") {
                    cout << "Bạn còn " << max_trial - i << " lần thử." << endl;
                    if (!(max_trial - (i))) {
                        cout << "Thẻ của bạn đã bị khóa." << endl;
                        break;
                    }
                }
                else if (b == "989480") {
                    cout << "Security!" << endl;
                    break;
                }
                else {
                    cout << "Rút tiền thành công." << endl;
                    cout << "Số dư còn lại là: " << A - a << endl;
                    break;
                }
                ++i;
            }
            break;
        }
    }
}

int main() {
    long long a, b, c;
    double x, y, z;

    cout << "*problem_1" << endl;
    cin >> a;
    problem_1(a);


    cout << "*problem_2" << endl;
    cin >> x >> y;
    problem_2(x, y);


    cout << "*problem_3" << endl;
    cin >> x >> y >> z;
    problem_3(x, y, z);


    cout << "*problem_4" << endl;
    cin >> x >> y;
    problem_4(x, y);


    cout << "*problem_5" << endl;
    cin >> x >> y;
    problem_5(x, y);



    cout << "*problem_6" << endl;
    cin >> x >> y >> z;
    problem_6(x, y, z);


    cout << "*problem_7" << endl;
    cin >> a >> b;
    problem_7(a, b);


    cout << "*problem_8" << endl;
    cin >> a >> b;
    problem_8(a, b);


    cout << "*problem_9" << endl;
    cin >> a >> b;
    problem_9(a, b);


    cout << "*problem_10" << endl;
    cin >> a >> b >> c;
    problem_10(a, b, c);


    cout << "*problem_11" << endl;
    cin >> a;
    problem_11(a);


    cout << "*problem_12" << endl;
    cin >> a >> b;
    problem_12(a, b);


    cout << "*problem_13" << endl;
    cin >> a >> x;
    problem_13(a, x);


    cout << "*problem_14" << endl;
    cin >> a;
    problem_14(a);
}