#include <iostream>
#include <cmath>
using namespace std;

void Bt1(float A1) {
    float CV, S;
    cout << "nhap canh c:";
    CV = A1 * 4;
    S = A1 * A1;
    cout << " vay chu vi hinh vuong la: " << CV << endl;
    cout << "vay dien tich hinh vuong la: " << S << endl;
}

void Bt2(float A2, float B2) {
    float S, Cv, Dc;
    cout << "nhap chieu dai: ";
    cout << "nhap chieu rong: ";
    S = A2 * B2;
    Cv = (A2 + B2) * 2;
    Dc = sqrt(pow(A2, 2) + pow(B2, 2));
    cout << " vay dien tich hcn la:" << S << endl;
    cout << " vay chu vi hcn la:" << Cv << endl;
    cout << " vay duong cheo hcn la: " << Dc << endl;
}

void Bt3(int A3, int B3, int C3) {
    if (A3 > 0 && B3 > 0 && C3 > 0) {
        if (A3 == B3 && A3 == C3) {
            cout << "HLP" << endl;
        } else {
            cout << "HHCN" << endl;
            float Sxq, Stp, Dc, V;
            V = A3 * B3 * C3;
            Sxq = 2 * (A3 + B3) * C3;
            Stp = Sxq + 2 * A3 * B3;
            Dc = sqrt(pow(sqrt(pow(A3, 2) + pow(B3, 2)), 2) + pow(C3, 2));
            cout << "dien tich xuong quanh: " << Sxq << endl;
            cout << "dien tich toan phan: " << Stp << endl;
            cout << "duong cheo: " << Dc << endl;
            cout << "the tich: " << V << endl;
        }
    } else {
        cout << -1;
    }
}

void Bt4(double A4, double B4) {
    int absX = abs(A4);
    long labsX = labs(B4);
    cout << "nhap x: ";
    cout << "nhap y: ";
    if (A4, B4 > 0) {
        cout << "sqrt= " << sqrt(A4) << endl;
        cout << "pow= " << pow(A4, B4) << endl;
        cout << "exp= " << exp(A4) << endl;
        cout << "log= " << log(A4) << endl;
        cout << "log10= " << log10(A4) << endl;
        cout << "abs= " << abs(A4) << endl;
        cout << "labs= " << labs(A4) << endl;
        cout << "fabs= " << fabs(A4) << endl;
        cout << "cos= " << cos(A4) << endl;
        cout << "sin= " << sin(A4) << endl;
        cout << "tan= " << tan(A4) << endl;
        if (A4 >= -1 && A4 <= 1) {
            cout << "acos= " << acos(A4) << endl;
            cout << "asin= " << asin(A4) << endl;
        }
        cout << "atan= " << atan(A4) << endl;
        cout << "floor= " << floor(A4) << endl;
        cout << "ceil= " << ceil(A4) << endl;
    } else {
        cout << "sqrt= " << sqrt(A4) << endl;
        cout << "pow= " << pow(A4, B4) << endl;
        cout << "exp= " << exp(A4) << endl;
        cout << "log= " << log(A4) << endl;
        cout << "log10= " << log10(A4) << endl;
        cout << "abs= " << abs(A4) << endl;
        cout << "labs= " << labs(A4) << endl;
        cout << "fabs= " << fabs(A4) << endl;
        cout << "cos= " << cos(A4) << endl;
        cout << "sin= " << sin(A4) << endl;
        cout << "tan= " << tan(A4) << endl;
        if (A4 >= -1 && A4 <= 1) {
            cout << "acos= " << acos(A4) << endl;
            cout << "asin= " << asin(A4) << endl;
        }
        cout << "atan= " << atan(A4) << endl;
        cout << "floor= " << floor(A4) << endl;
        cout << "ceil= " << ceil(A4) << endl;
    }
}

void Bt5(double A5, double B5) {
    if (A5 != 0) cout << (double) - B5 / A5;
    else if (B5 != 0) cout << "Pt vô nghiệm";
    else if (B5 == 0) cout << "Pt vô số nghiệm";
}

void Bt6(double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) cout << "Phuong trinh co vo so nghiem" << endl;
            else cout << "Phuong trinh vo nghiem" << endl;
        } else {
            cout << "Phuong trinh co nghiem: x = " << -c / b << endl;
        }
    } else {
        double delta = b * b - 4 * a * c;
        if (delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem phan biet:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        } else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "Phuong trinh co nghiem kep: x = " << x << endl;
        } else {
            cout << "Phuong trinh vo nghiem thuc" << endl;
        }
    }
}


void Bt7(double a, double b, double C7) {
    double max, min;
    if ( a >= b  && a >= C7 ) {
        max = a;
    } else if ( b >= a && b >= C7 ) {
        max = b;
    } else if ( C7 >= a && C7 >= b) {
        max = C7;
    }
    if ( a <= b && a <= C7 ) {
        min = a;
    } else if ( b <= a && b <= C7) {
        min = b;
    } else if ( C7 <= a && C7 <= b) {
        min = C7;
    }
    cout << " vay max la: " << max << endl;
    cout << " vay min la: " << min << endl;
// bonus
    int n;
    cin >> n;
    double v[n];
    double maxn, minn;
    for ( int i = 0 ; i < n ; ++i ) {
        cin >> v[i];
    }
    maxn = v[0];
    minn = v[0];
    for ( int i = 0 ; i < n ; ++ i) {
        if (v[i] > maxn) maxn = v[i];
        if (v[i] < minn) minn = v[i];
    }
    cout << " vay max cua n la: " << maxn << endl;
    cout << " vay min cua n la: " << minn << endl;

}

void Bt8(int n) {
    cout << "nhap n : ";
    double v[n];
    for ( int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int am, duong, ko;
    am = 0;
    duong = 0;
    ko = 0;
    for (int i = 0; i < n; ++i ) {
        if (v[i] == 0) ko++;
        if (v[i] > 0) duong++;
        if (v[i] < 0) am++;
    }
    cout << " vay am la: " << am << endl;
    cout << " vay duong la: " << duong << endl;
    cout << " vay ko la: " << ko << endl;
}

void Bt9(int A9) {
    cout << "nhap n: ";
    int v[A9];
    for (int i = 0; i < A9; ++i) {
        cin >> v[i];
    }
    int chan, le;
    chan = 0;
    le = 0;
    for ( int i = 0; i < A9; ++i) {
        if (v[i] % 2 == 0) {chan++;}
        else le++;
    }
    cout << "vay tong so chan la: " << chan << endl;
    cout << "vay tong so le la: " << le << endl;
}

void Bt10(int A10) {
    cout << "Nhap so (0-20): ";
    switch (A10) {
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
        if (A10 < 0) {
            cout << "Khong hop le" << endl;
        } else {
            cout <<  "Khong nhap so > 20" << endl;
        }
        break;
    }
    cout << endl;
}

void Bt11(double A11, double B11, double C11, double A, double B, double C) {
    double D = A11 * B - A * B11;
    double Dx = C11 * B - C * B11;
    double Dy = A11 * C - A * C11;

    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        cout  << "hpt co nghiem duy nhat: " << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    } else {
        if (Dx == 0 &&  Dy == 0) {
            cout << "hpt co vo so nghiem." << endl;
            cout << "hpt vo nghiem." << endl;
        }
    }
}

void Bt12(double m, double B12) {
    double sm;
    sm = 0;
    for (int i = 1; i <= B12; ++i ) {
        sm += pow(i, m);
    }
    cout << sm << endl;
}
void Bt13(long long n, long long m, long long M) {
    int s = 1, i = 1;
    while (s <= M) {
        i++;
        if (i <= n) {
            if (s + pow(i, m) <= M) {
                if (s + pow(i, m) == M) {
                    s += pow(i, m);
                    break;
                } else s += pow(i, m);
            } else break;
        } else break;
    }
    cout << s;
}

void Bt14(double A, double a, string true_PIN, string input_PIN, int max_trial) {
    bool ok = false;
    for (int i = 1; i <= max_trial; ++i) {
        cout << "\nEnter PIN = ";
        cin >> input_PIN;
        if (input_PIN == true_PIN) {
            ok = true;
            break;
        } else cout << "\nWrong PIN. Re-enter PIN = ";

    }
    if (ok) {
        cout << "Mã PIN đúng. Cho phép rút tiền.\nVui lòng nhập số tiền bạn muốn rút: ...\n";
        cout << "\nEnter a = ";
        cin >> a;
        if (a > A) cout << "Số tiền rút lớn hơn số dư khả dụng. Bạn bị ảo tưởng sức mạnh tài chính à?\n";
        else {
            cout << "Bạn đã rút thành công " << a << " VND.\nSố dư khả dụng: " << A - a << " VND.\n";
            cout << "Bạn muốn in hóa đơn? (Yes/No)?\n";
            string bill;
            cin >> bill;
            if (bill == "Yes") cout << "Đang in hóa đơn. Vui lòng đợi để nhận cả hóa đơn, cash, & thẻ.\n";
            else cout << "Vui lòng đợi để nhận cash, & thẻ.\n";
            cout << "Cảm ơn bạn đã giao dịch tại ngân hàng X.\nVui lòng đánh giá chất lượng dịch vụ.\n";
        }
    } else cout << "Bạn đã bị khóa thẻ. Vui lòng liên hệ chi nhánh ngân hàng X gần nhất để hỗ trợ nhận lại thẻ.\nXin chân thành cảm ơn.\n";

}


int main() {
    //Bt1
    cout << "BT1:" << endl;
    float A1;
    cin >> A1;
    Bt1(A1);
    //Bt2
    cout << "BT2:" << endl;
    float A2, B2;
    cin >> A2 >> B2;
    Bt2(A2, B2);
    //Bt3
    cout << "BT3:" << endl;
    int A3, B3, C3;
    cin >> A3 >> B3 >> C3;
    Bt3(A3, B3, C3);
    //Bt4
    cout << "BT4:" << endl;
    double A4, B4;
    cin >> A4 >> B4;
    Bt4(A4, B4);
    //Bt5
    cout << "BT5:" << endl;
    double A5, B5;
    cin >> A5 >> B5;
    Bt5(A5, B5);
    //Bt6
    cout << "BT6:" << endl;
    double c, k, g;
    cin >> c >> k >> g;
    Bt6(c, k, g);
    //Bt7
    cout << "BT7:" << endl;
    double a, b, C7;
    cin >> a >> b >> C7;
    Bt7(a, b, C7);
    //Bt8
    cout << "BT8:" << endl;
    int n;
    cin >> n;
    Bt8(n);
    //Bt9
    cout << "BT9:" << endl;
    int A9;
    cin >> A9;
    Bt9(A9);
    //Bt10
    cout << "BT10:" << endl;
    int A10;
    cin >> A10;
    Bt10(A10);
    //Bt11
    cout << "BT11:" << endl;
    double A11, B11, C11, A, B, C;
    cin >> A11 >> B11 >> C11 >> A >> B >> C;
    Bt11(A11, B11, C11, A, B, C);
    //Bt12
    cout << "BT12:" << endl;
    double m, B12;
    cin >> m >> B12;
    Bt12(m, B12);
    //Bt13
    cout << "BT13" << '\n';
    long long n13, m13, M13;
    cin >> n13 >> m13 >> M13;
    Bt13(n13, m13, M13);
    cout << '\n';
    //Bt14
    cout << "BT14:" << endl;
    double A14, a14;
    string true_PIN, input_PIN;
    int max_trial;
    cin >> A14 >> a14 >> true_PIN >> input_PIN >> max_trial;
    Bt14(A14, a14, true_PIN, input_PIN, max_trial);
    return 0;
}