#include <cmath>
#include <iostream>
using namespace std;

//bai 1
void chu_vi_dien_tich_hinh_vuong(long long a) {
    // Chu vi hinh vuong
    double P = a * 4;
    cout << "chu vi cua hinh vuong co canh ben la " << a << " bang " << P << '\n';

    // Dien tich hinh vuong
    double S = a * a;
    cout << "dien tich cua hinh vuong co canh ben la " << a << " bang " << S << '\n';
}
//bai 2
void CV_DT_DD_hinh_chu_nhat(long long a, long long b) {
    // Chu vi hinh chu nhat
    double P = (a + b) * 2;
    cout << "chu vi cua hinh chu nhat la " << P << '\n';

    // Dien tich hinh chu nhat
    double S = a * b;
    cout << "dien tich cua hinh chu nhat la " << a << " nhan " << b << " bang " << S << '\n';

    // Do dai duong cheo hinh chu nhat
    float d = sqrt(a * a + b * b); // d la ky hieu cua do dai duong cheo
    cout << "do dai duong cheo cua hinh chu nhat la " << d << '\n';
}
//bai 3
void kiem_tra_HLP_HHCN(long long a, long long b, long long c) {
    if (a == b == c) {
        cout << " HLP ";
    }
    else {
        cout << " HHCN " << '\n';
        // Dien tich xung quanh
        float S = (a + b) * 2 * c; //S la ky hieu dien tich xung quanh
        cout << " dien tich xung quanh = " << S << '\n';
        // Dien tich toan phan
        float R = 2 * (a * b + b * c + a * c); //R la ky hieu dien tich toan phan
        cout << " dien tich toan phan = " << R << '\n';
        // Duong cheo
        float D = sqrt(a * a + b * b + c * c); //D la ky hieu duong cheo
        cout << " duong cheo = " << D << '\n';
        // The tich
        float V = a * b * c; //V la ky hieu the tich
        cout << " the tich = " << V << '\n';
    }
}
//bai 4
void chuong_trinh_chay_thu_cac_ham(long long x, long long y, long long n, long long m) {
    {
        double x;
        cin >> x;
        if (x < 0)
            cout << "x phai khong am";
        else
            cout << "can bac hai cua so thuc = " << sqrt(x) << '\n';
        double y;
        cin >> y;
        if (x <= 0)
            cout << "x phai lon hon hoac bang 0";
        else
            cout << "x luy  thua y = " << pow(x, y) << '\n';
        cout << "e mu x = " << exp(x) << '\n';
        cout << "logarit tu nhien  cua x = " << log(x) << '\n';
        cout << "logarit co so 10 cua x = " << log10(x) << '\n';
    }
    {
        {
            int n;
            cin >> n;
            cout << "gia tri tuyet doi |n| voi n nguyen = " << abs(n) << '\n';
        }
        {
            long m;
            cin >> m;
            cout << "gia tri tuyet doi cua |m| voi m nguyen dai = " << labs(m) << '\n';
        }
        {
            double x;
            cin >> x;
            cout << "gia tri tuyet doi cua |x| voi x so thuc = " << fabs(x) << '\n';
        }
    }
    {
        double x;
        cin >> x;
        cout << "cos (x) cua goc x cho bang don vi radian = " << cos(x) << '\n';
        cout << "sin (x) cua goc x cho bang don vi radian = " << sin(x) << '\n';
        cout << "tan (x) cua goc x cho bang don vi radian = " << tan(x) << '\n';
    }
    {
        double x;
        cin >> x;
        cout << "arccos (x) khi da biet truoc gia tri luong giac x = " << acos(x) << '\n';
        cout << "arcsin (x) khi da biet truoc gia tri lhuong giac x = " << asin(x) << '\n';
        cout << "arctan (x) khi da biet truoc gia tri luong giac x = " << atan(x) << '\n';
    }
    {
        double x;
        cin >> x;
        cout << "so nguyen lon nhat khong vuot qua x = " << floor(x) << '\n';
        cout << "so nguyen nho nhat khong vuot qua x = " << ceil(x) << '\n';
    }
}
//bai 5
void giai_phuong_trinh_bac_nhat(long long a, long long b, long long x) {
    if (a != 0) {
        x = -b / a;
        cout << "phuong trinh co gia tri x = " << x;
    }
    else {
        (a = 0);
        cout << "phuong trinh vo nghiem ";
        if (b != 0)
            cout << "phuong trinh vo nghiem ";
        else
            cout << "phuong trinh vo so nghiem ";
    }
}
//bai 6
void giai_phuong_trinh_bac_hai(long long a, long long b, long long c) {
    double y = b * b - 4 * a * c; //y la delta
    if (y < 0) {
        cout << "phuong trinh vo nghiem ";
    }
    else if (y == 0) {
        double x = -b / (2 * a);
        cout << "phuong trinh nghiem kep = " << x << '\n';
    }
    else {
        double x1 = -b + sqrt(y) / (2 * a);
        cout << "phuong trinh 2 nghiem thuc = " << x1 << '\n';
        double x2 = -b - sqrt(y) / (2 * a);
        cout << "phuong trinh 2 nghiem thuc = " << x2 << '\n';
    }
}
// bai 7
void max_min_trong_3_so_thuc(long long a, long long b, long long c) {
    long long max, min;
    if (a >= b && a >= c) {
        max = a;
        cout << "Max trong 3 so thuc cho truoc = " << max << '\n';
    }
    else if (b >= a && b >= c) {
        max = b;
        cout << "Max trong 3 so thuc cho truoc = " << max << '\n';
    }
    else {
        max = c;
        cout << "Max trong 3 so thuc cho truoc = " << max << '\n';
    }
    if (a <= b && a <= c) {
        min = a;
        cout << "Min trong 3 so thuc cho truoc = " << min << '\n';
    }
    else if (b <= a && b <= c) {
        min = b;
        cout << "Min trong 3 so thuc cho truoc = " << min << '\n';
    }
    else {
        min = c;
        cout << "Min trong 3 so thuc cho truoc = " << min << '\n';
    }
}
//bai 8
void dem_so(long long &a, long long &b, long long &c, long long n) {
    for (int i = 0; i < n; ++i) {
        double x;
        cout << "x = ";
        cin >> x;
        if (x == 0) {
            a++;
        }
        else if (x > 0) {
            c++;
        }
        else b++;
    }

}
//bai 9
void dem_so_chan_le(long long a, long long b, long long n) {
    for (int i = 0; i < n; ++i) {
        int x;
        cout << "x = ";
        cin >> x;
        if (x % 2 == 0)
            a++;
        else
            b++;
    }
    cout << "so chan = " << a << '\n';
    cout << "so le = " << b << '\n';
}
// bai 10
void in_tu_tieng_anh(long long n) {
    switch (n) {
    case 0:
        cout << "zero";
        break;
    case 1:
        cout << "one";
        break;
    case 2:
        cout << "two";
        break;
    case 3:
        cout << "three";
        break;
    case 4:
        cout << "four";
        break;
    case 5:
        cout << "five";
        break;
    case 6:
        cout << "six";
        break;
    case 7:
        cout << "seven";
        break;
    case 8:
        cout << "eight";
        break;
    case 9:
        cout << "nine";
        break;
    case 10:
        cout << "ten";
        break;
    case 11:
        cout << "eleven";
        break;
    case 12:
        cout << "twelve";
        break;
    case 13:
        cout << "thirdteen";
        break;
    case 14:
        cout << "fourteen";
        break;
    case 15:
        cout << "fifteen";
        break;
    case 16:
        cout << "sixteen";
        break;
    case 17:
        cout << "seventeen";
        break;
    case 18:
        cout << "eighteen";
        break;
    case 19:
        cout << "nineteen";
        break;
    case 20:
        cout << "twenty";
        break;
    default:
        cout << "so khong hop le " << '\n';
    }
}
// bai 11
void he_pttt_bac_2(long long a, long long b, long long c, long long A, long long B, long long C) {
    double d = a * B - A * b;
    double dx = c * B - C * b;
    double dy = a * C - A * c;
    if (d != 0)
    {
        double x = dx / d;
        double y = dy / d;
        cout << "he phuong trinh co ham duy nhat ";
        cout << "x = " << x << '\n';
        cout << "y = " << y << '\n';
    }
    else
    {
        if (dx == 0 && dy == 0)
            cout << "he phuong trinh co vo so nghiem " << '\n';
        else
            cout << "he phuong trinh vo nghiem " << '\n';
    }
}
//bai 12
void Sm(long long n, long long m, long long sum) {
    if (m < 0 || n < 1) {
        cout << "khong hop le" << '\n';
    }
    for (int i = 1; i <= n; ++i) {
        sum += (long long)pow(i, m);
    }
    cout << "ket qua = " << sum << '\n';
}
//bai 13
void Sum_M_lon(long long n, long long m, long long M) {
    long long i = 1;
    long long S = 0;
    while (S + (int)pow(i, m) <= M) {
        S += (int)pow(i, m);
        ++i;
    }
    cout << S << " <= " << M << '\n';
}
//bai 14



int main() {
    //bai 1
    long long a;
    cout << "canh hinh vuong a = " << '\n';
    cin >> a;
    chu_vi_dien_tich_hinh_vuong(a);


    //bai 2
    cout << "chieu dai hinh chu nhat a = " << '\n';
    cin >> a;
    long long b; // b la chieu rong
    cout << "chieu rong hinh chu nhat b = " << '\n';
    cin >> b;
    CV_DT_DD_hinh_chu_nhat(a, b);


    //bai 3
    long long c;
    cout << "nhap canh a: "; //a la chieu dai
    cin >> a;
    cout << "nhap canh b: "; //b la chieu rong
    cin >> b;
    cout << "nhap canh c: "; //c la chieu cao
    cin >> c;
    kiem_tra_HLP_HHCN(a, b, c);


    //bai 4
    long long x;
    cin >> x;
    long long y;
    cin >> y;
    int n;
    cin >> n;
    long long m;
    cin >> m;
    chuong_trinh_chay_thu_cac_ham(x, y, n, m);


    //bai 5
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    giai_phuong_trinh_bac_nhat(a, b, x);


    //bai 6
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    giai_phuong_trinh_bac_hai(a, b, c);


    //bai 7
    long long max, min;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    max_min_trong_3_so_thuc(a, b, c);


    //bai 8
    cout << "n = ";
    cin >> n;
    dem_so(a, b, c, n);
    {
        cout << "dem so so 0 = " << a << '\n';
        cout << "dem so so am = " << b << '\n';
        cout << "dem so so duong = " << c << '\n';
    }


    //bai 9
    cout << "n = ";
    cin >> n;
    dem_so_chan_le(a, b, n );


    //bai 10
    cout << "n = ";
    cin >> n;
    in_tu_tieng_anh(n);


    //bai 11
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    double A, B, C;
    cout << "A = ";
    cin >> A;
    cout << "B = ";
    cin >> B;
    cout << "C = ";
    cin >> C;
    he_pttt_bac_2(a, b, c, A, B, C);


    //bai 12
    long long sum = 0;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    Sm(n, m, sum);


    //bai 13
    long long M;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    cout << "M = ";
    cin >> M;
    Sum_M_lon(n, m, M);


    //bai 14

}

