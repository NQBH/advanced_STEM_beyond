#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

// BT1 midterm
void chu_vi_dien_tich_hinh_vuong(float z) {
    cout << z * 4 << endl;
    cout << z * z << endl;
}


// BT2 midterm
void chu_vi_dien_tich_duong_cheo_hcn(float chieudai, float chieurong) {
    float chuvi = 2 * (chieudai + chieurong);
    float dientich = chieudai * chieurong;
    float duongcheo = sqrt(chieudai * chieudai + chieurong * chieurong);
    cout << "Chu vi HCN: " << chuvi << endl;
    cout << "Dien tich HCN: " << dientich << endl;
    cout << "Duong cheo HCN: " << duongcheo << endl;
}

// BT3 midterm
void thong_so_hinh_hop(float a, float b, float c)
{
    if (a > 0 && b > 0 && c > 0)
    {
        if (a == b && b == c)
            cout << "HLP" << endl;
        else
            cout << "HHCN" << endl;

        float Sxq = 2 * c * (a + b);
        float Stp = 2 * (a * b + b * c + a * c);
        float d = sqrt(a * a + b * b + c * c);
        float V = a * b * c;

        cout << "Dien tich xung quanh la: " << Sxq << endl;
        cout << "Dien tich toan phan la: " << Stp << endl;
        cout << "Duong cheo la: " << d << endl;
        cout << "The tich la: " << V << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
// BT4 midterm
void kiem_tra_cac_ham(double x, double y)
{
    if (x >= 0)
        cout << sqrt(x) << endl;
    else
        cout << "x must be non-negative" << endl;

    double p = pow(x, y);
    double lg = log(x);
    double lg10 = log10(x);
    double a = fabs(x);
    long l = labs((long)x);

    cout << "pow=" << p << endl;
    cout << "log=" << lg << endl;
    cout << "log10=" << lg10 << endl;
    cout << "abs=" << a << endl;
    cout << "labs=" << l << endl;
    cout << "fabs=" << fabs(x) << endl;

    cout << "cos=" << cos(x) << endl;
    cout << "sin=" << sin(x) << endl;
    cout << "tan=" << tan(x) << endl;

    cout << "acos=" << acos(x) << endl;
    cout << "asin=" << asin(x) << endl;
    cout << "atan=" << atan(x) << endl;

    cout << "floor=" << floor(x) << endl;
    cout << "ceil=" << ceil(x) << endl;
}

// BT5 midterm
void giai_pt_bac_1()
{
    double a, b;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;

    if (a == 0)
    {
        if (b == 0)
        {
            cout << "phuong trinh vo so nghiem" << endl;
        }
        else
        {
            cout << "phuong trinh vo nghiem" << endl;
        }
    }
    else
    {
        double x;
        x = -b / a;
        cout << "phuong trinh co nghiem x la: " << x << endl;
    }
}

// BT6 midterm
void giai_pt_bac_2()
{
    double a, b, c;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap c: ";
    cin >> c;

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                cout << "Vo so nghiem";
            else
                cout << "Vo nghiem";
        }
        else
        {
            double x = -c / b;
            cout << "Nghiem x = " << x;
        }
    }
    else
    {
        double delta;
        delta = b * b - 4 * a * c;

        if (delta > 0)
        {
            double x1, x2;
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);

            cout << "Hai nghiem phan biet" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2;
        }
        else
        {
            if (delta == 0)
            {
                double x;
                x = -b / (2 * a);
                cout << "Nghiem kep x = " << x;
            }
            else
            {
                cout << "Phuong trinh vo nghiem thuc";
            }
        }
    }
}

// BT7 midterm
void tim_max_min()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Khong co gia tri";
        return;
    }

    double a;
    double maxVal, minVal;

    cin >> a;
    maxVal = a;
    minVal = a;

    for (int i = 1; i < n; i++)
    {
        cin >> a;

        if (a > maxVal)
        {
            maxVal = a;
        }

        if (a < minVal)
        {
            minVal = a;
        }
    }

    cout << "max: " << maxVal << endl;
    cout << "min: " << minVal << endl;
}
// BT8 midterm
void dem_duong_am_khong(int n) {
    int demduong = 0, demam = 0, dem0 = 0;
    double x;
    for (int i = 0; i < n; ++i) {
        cout << "Nhap so thuc thu " << i + 1 << ": ";
        cin >> x;
        if (x > 0) demduong += 1;
        else if (x < 0) demam += 1;
        else dem0 += 1;
    }
    cout << "-------------------------" << endl;
    cout << "So phan tu duong la: " << demduong << endl;
    cout << "So phan tu am la: " << demam << endl;
    cout << "So phan tu 0 la: " << dem0 << endl;
}

// BT9 midterm
void dem_chan_le(int n) {
    int demchan = 0, demle = 0, x;
    for (int i = 0; i < n; ++i) {
        cout << "Nhap so nguyen thu " << i + 1 << ": ";
        cin >> x;
        if (x % 2 == 0) demchan += 1;
        else demle += 1;
    }
    cout << "------------------------" << endl;
    cout << "So phan tu chan la: " << demchan << endl;
    cout << "So phan tu le la: " << demle << endl;
}
// BT10 midterm
void nhap_so(int n) {
    switch (n) {
    case 0: cout << "Zero" << endl; break;
    case 1: cout << "One" << endl; break;
    case 2: cout << "Two" << endl; break;
    case 3: cout << "Three" << endl; break;
    case 4: cout << "Four" << endl; break;
    case 5: cout << "Five" << endl; break;
    case 6: cout << "Six" << endl; break;
    case 7: cout << "Seven" << endl; break;
    case 8: cout << "Eight" << endl; break;
    case 9: cout << "Nine" << endl; break;
    case 10: cout << "Ten" << endl; break;
    case 11: cout << "Eleven" << endl; break;
    case 12: cout << "Twelve" << endl; break;
    case 13: cout << "Thirteen" << endl; break;
    case 14: cout << "Fourteen" << endl; break;
    case 15: cout << "Fifteen" << endl; break;
    case 16: cout << "Sixteen" << endl; break;
    case 17: cout << "Seventeen" << endl; break;
    case 18: cout << "Eighteen" << endl; break;
    case 19: cout << "Nineteen" << endl; break;
    case 20: cout << "Twenty" << endl; break;
    default: cout << "So nay khong hop le" << endl; break;
    }
}
// BT11 midterm
void he_ptb1_hai_an(double a1, double b1, double c1, double a2, double b2, double c2) {
    double D = a1 * b2 - a2 * b1;
    double Dx = c1 * b2 - c2 * b1;
    double Dy = a1 * c2 - a2 * c1;
    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        cout << "He phuong trinh co nghiem duy nhat: " << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
    else if (Dx != 0 || Dy != 0) cout << "Phuong trinh vo nghiem" << endl;
    else cout << "Phuong trinh co vo so nghiem" << endl;
}
// BT12 midterm
void tinh_luy_thua()
{
    double a;
    int n;
    double ketqua = 1;

    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap n: ";
    cin >> n;

    if (n >= 0)
    {
        for (int i = 1; i <= n; i++)
        {
            ketqua = ketqua * a;
        }
    }
    else
    {
        for (int i = 1; i <= -n; i++)
        {
            ketqua = ketqua * a;
        }
        ketqua = 1 / ketqua;
    }

    cout << "a^n = " << ketqua << endl;
}
// BTAP 13 midterm
void tong_luy_thua_max()
{
    double m, M;
    double S = 0;
    int n = 0;

    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap M: ";
    cin >> M;

    while (S <= M)
    {
        n++;
        S = S + pow(n, m);

        if (S > M)
        {
            n--;
            break;
        }
    }

    cout << "Gia tri n lon nhat la: " << n << endl;
}
// BTAP14 midterm
void rut_tien()
{
    long long A;
    long long a;
    string pinDung = "123456";
    string pinNhap;
    int maxTrial;
    bool ok = false;

    cout << "Nhap so tai khoan (VND): ";
    cin >> A;
    cout << "Nhap so lan nhap PIN toi da: ";
    cin >> maxTrial;

    for (int i = 1; i <= maxTrial; i++)
    {
        cout << "Nhap ma PIN: ";
        cin >> pinNhap;

        if (pinNhap == pinDung)
        {
            ok = true;
            break;
        }
        else
        {
            cout << "Sai PIN!" << endl;
        }
    }

    if (!ok)
    {
        cout << "The da bi khoa!" << endl;
        return;
    }

    cout << "Nhap so tien can rut (VND): ";
    cin >> a;

    if (a > A)
    {
        cout << "So du khong du de thuc hien giao dich!" << endl;
        return;
    }

    A = A - a;

    cout << "Rut tien thanh cong!" << endl;
    cout << "So du con lai: " << A << " VND" << endl;
}
int main() {

    // BT1
    float z;
    cout << "\n[BT1] Nhap canh hinh vuong z: ";
    cin >> z;
    chu_vi_dien_tich_hinh_vuong(z);

    // BT2
    float chieudai, chieurong;
    cout << "\n[BT2] Nhap chieu dai va chieu rong HCN: ";
    cin >> chieudai >> chieurong;
    chu_vi_dien_tich_duong_cheo_hcn(chieudai, chieurong);

    // BT3
    float a, b, c;
    cout << "\n[BT3] Nhap 3 canh a, b, c cua hinh hop: ";
    cin >> a >> b >> c;
    thong_so_hinh_hop(a, b, c);

    // BT4
    double x, y;
    cout << "\n[BT4] Nhap 2 so x, y: ";
    cin >> x >> y;
    kiem_tra_cac_ham(x, y);

    // BT5 midterm
    double a5, b5;
    cout << "\n[BT5] Nhap he so a, b cho PTB1: ";
    cin >> a5 >> b5;
    ptb1(a5, b5);

    // BT6 midterm
    double q, w, e;
    cout << "\n[BT6] Nhap he so q, w, e cho PTB2: ";
    cin >> q >> w >> e;
    ptb2(q, w, e);

    // BT7 midterm
    double a7, b7, c7;
    cout << "\n[BT7] Nhap 3 so thuc a, b, c: ";
    cin >> a7 >> b7 >> c7;
    min_max(a7, b7, c7);

    // BT8 midterm
    int n;
    cout << "\n[BT8] Nhap so luong phan tu n: ";
    cin >> n;
    dem_duong_am_khong(n);

    // BT9 midterm
    cout << "\n[BT9] Nhap so luong phan tu n: ";
    cin >> n;
    dem_chan_le(n);

    // BT10
    int n;
    cout << "\n[BT10] Nhap mot so nguyen tu 0 toi 20: ";
    cin >> n;
    doc_so(n);

    // BT11
    double a1, b1, c1, a2, b2, c2;
    cout << "\n[BT11] Nhap he so a1, b1, c1 va a2, b2, c2: ";
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    he_ptb1_hai_an(a1, b1, c1, a2, b2, c2);

    // BT12
    int m12;
    cout << "\n[BT12] Nhap n va m: ";
    cin >> n >> m12;
    tong_chuoi_luy_thua(n, m12);

    // BT13
    double M;
    int m13;
    cout << "\n[BT13] Nhap n, m va M: ";
    cin >> n >> m13 >> M;
    tong_luy_thua_max(n, m13, M);

    // BT14
    long long A;
    int max_trial;
    cout << "\n[BT14] --- HE THONG QUAN LY ATM ---" << endl;
    cout << "Nhap so du tai khoan hien co: ";
    cin >> A;
    cout << "Nhap gioi han so lan nhap sai PIN (max_trial): ";
    cin >> max_trial;
    cout << "---------------------------------" << endl;
    quan_ly_atm(A, max_trial);

    return 0;
}
