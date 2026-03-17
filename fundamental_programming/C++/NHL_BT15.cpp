#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
// BT1
void hv_dt_cv(long long a) {
    long long dt = a * a;
    long long cv = a * 4;
    cout << "dien tich hv la: " << dt << '\n';
    cout << "chu vi hv la: " << cv;
}
// BT2
void tinh_hcn(long long a, long long b) {
    double dt = a * b;
    double cv = (a + b) * 2;
    double duongcheo = sqrt(a * a + b * b);
    cout << "dien tich hcn la: " << dt << '\n';
    cout << "chu vi hcn la: " << cv << '\n';
    cout << "duong cheo  la: " << duongcheo;
}
// BT3
void hlp(long long a, long long b, long long c) {

    if (a > 0 && b > 0 && c > 0 && a == b && b == c)
        cout << "HLP";

    else if (a > 0 && b > 0 && c > 0 ) {
        cout << "HHCN" << '\n';
        int xq = 2 * c * (a + b);
        int tp = 2 * (a * b + a * c + b * c);
        float dc = sqrt(a * a + b * b + c * c);
        int tt = a * b * c ;
        cout << "dien tich xung quanh cua hhcn: " << xq << '\n';
        cout << "dien tich toan phan  cua hhcn: " << tp << '\n';
        cout << "duong cheo cua hhcn: " << dc << '\n';
        cout << "the tich cua hhcn: " << tt << '\n';
    }
    else {
        cout << -1;
    }
}
// BT4
void chay_thu_ham(long long x , long long y, long long a, long long b, long long c) {


    if (x < 0) cout << "x phải lớn hơn hoặc bằng 0" << '\n';
    else cout << "căng bậc hai của " << x << ": " << sqrt(x) << '\n';

    pow(x, y);
    if (x <= 0) cout << "x phải lớn hơn 0";
    else cout << "x lũy thừa y: " << pow(x, y) << '\n';
    cout << "e mũ x : " << exp(x) << '\n';
    cout << "logarit cơ số e của x: " << log(x) << '\n';
    cout << "logarit cơ số 10 của x : " << log10(x) << '\n';

    cout << "giá trị tuyệt đối |a| với a nguyên: " << abs( a) << '\n';

    cout << "giá trị tuyệt đối |b| với b nguyên dài: " << abs( b) << '\n';

    cout << "giá trị tuyệt đối |c| với c là số thực: " << abs( c) << '\n';
    cout << "sin(x): " << sin(x) << '\n';
    cout << "cos(x): " << cos(x) << '\n';
    cout << "tan(x): " << tan(x) << '\n';
    cout << "hàm lượng giác ngược arcsin(x): " << asin(x) << '\n';
    cout << "hàm lượng giác ngược arccos(x): " << acos(x) << '\n';
    cout << "hàm lượng giác ngược arctan(x): " << atan(x) << '\n';
    cout << "số nguyên lớn nhất không vượt quá x: " << floor(x) << '\n';
    cout << "số nguyên nhỏ nhất lớn hơn hay bằng x: " << ceil(x) << '\n';

}

//  BT5
void giai_phuong_trinh_bac1(long long a, long long b, long long x) {

    double s = (a * x + b == 0);
    if (a != 0) {
        x = -b / a;
        cout << "phương trình có nghiệm là: " << x ;
    }
    else {
        if  (b == 0)
            cout << "phương trình vô số nghiệm";
        else
            cout << "phương trình vô nghiệm ";

    }
}


//BT6
void giai_phuong_trinh_bac2(long long a, long long b, long long c, long long x) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0)

                cout << "phương trình vô số nghiệm";
            else
                cout << "phương trình vô nghiệm";
        }
        else {
            x = -c / b;
            cout << "phương trình bậc nhất có nghiệm: " << x;

        }
    }
    else
    {

        double denta = b * b - 4 * a * c;
        if (denta == 0) {
            x = -b / (2 * a);
            cout << "phương trình có nghiệm kép x: " << x;
        }
        else {
            if (denta < 0)
                cout << "phương trình vô nghiệm thực";
            else
            {   double x1 = (-b + sqrt(denta)) / (2 * a);
                double x2  = (-b - sqrt(denta)) / (2 * a);
                cout << "phương trình có 2 nghiệm thực" << '\n';
                cout << "x1 = " << x1 << '\n' ;
                cout << "x2 = " <<  x2;

            }
        }
    }


}


//BT7
void tim_max_min(long long a, long long b, long long c, long long max, long long min) {

    if (a > b && a > c) {
        max = a;
        cout << "so thuc lon nhat trong 3 so cho truoc la: " <<  max << '\n';
    }
    else {
        if (b > a && b > c) {
            max = b;
            cout << "so thuc lon nhat trong 3 so cho truoc la: " << max << '\n';
        }
        else {
            max = c;
            cout << "so thuc lon nhat trong 3 so cho truoc la: " <<  max << '\n';
        }
    }
    if (a < b && a < c) {
        min = a;
        cout << "so thuc nho nhat trong 3 so cho truoc la: " <<  min << '\n';
    }
    else {
        if (b < a && b < c) {
            min = b;
            cout << "so thuc nho nhat trong 3 so cho truoc la: " <<  min << '\n';
        }
        else {
            min = c;
            cout << "so thuc nho nhat trong 3 so cho truoc la: " <<  min << '\n';
        }
    }

}

//BT8
void dem_so(long long n, long long x) {

    int demsoduong = 0;
    int demso0 = 0;
    int demsoam = 0;
    for (int i = 0; i < n; i++)
    {
        if (x == 0) {demso0 ++;}
        else {
            if (x < 0) {demsoam ++;}
            else {demsoduong ++;}
        }
    }
    cout << "so so duong: " << demsoduong << '\n';
    cout << "so so am: " << demsoam << '\n';
    cout << "so so 0: " << demso0 << '\n';

}

//BT9
void demso_chan_le(long long n, long long chan, long long le, long long x) {
    chan = 0;
    le = 0;
    for (int i = 0; i < n; i++) {
        if (x % 2 == 0) {
            chan++;

        }
        else {
            le++;

        }
    }
    cout << "số lượng số chẳn: " << chan << '\n';
    cout << "số lượng số lẻ: " << le;

}

//BT10
void ham_switch(long long a) {
    switch (a) {
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
        cout << "thirteen";
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
        cout << "sevemteen";
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
        cout << "không hợp lệ";
    }

}

//BT11
void giai_hpt_tt_bac2(long long a, long long b, long long c, long long A, long long B, long long C) {
    if (a * B - b * A != 0) {
        double x, y;
        x = (c * B - b * C) / (a * B - b * A);
        y = (a * C - c * A) / (a * B - b * A);
        cout << "hệ có nghiệm duy nhất:" << '\n';
        cout << "x: " << x << '\n';
        cout << "y: " << y;
    }
    else {
        if (a * C == c * A) {
            cout << "hệ có vô số nghiệm";

        }
        else {
            cout << "hệ vô nghệm";

        }
    }
}

//BT12
void tinh_Sm(long long n, long long m, long long sum) {

    sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum = sum + pow(i, m);
    }
    cout << "tổng là: " << sum;
}
//BT13
void tinh_Sm2(long long n, long long m, long long M, long long sum, long long i) {
    sum = 0;
    i = 1;
    if (sum > M) {
        cout << "M không hợp lệ";
    }
    else {
        while (i <= n && sum + pow(i, m) <= M) {

            sum += pow(i, m);
            i++;


        }
        cout << "tổng là: " << sum;
    }
}
//BT14
void mo_phong_rut_tien(long long a, long long A, long long solanthu) {
    string PIN, pinnhapvao;
    cout << "nhập số tiền đang có A: ";
    cin >> A;
    cout << "nhập mã PIN bạn muốn: ";
    cin >> PIN;
    PIN.length() == 6;
    while (PIN.length() != 6) {
        cout << "mã pin đã chọn phải đủ 6 chữ số" << '\n';
        cout << "vui lòng chọn lại mã pin: ";
        cin >> PIN;
    }
    cout << "số lần có thể nhập mã PIN: ";
    cin >> solanthu;

    int i = 0;
    while (i < solanthu) {
        cout << "nhập mã PIN của bạn: ";
        cin >> pinnhapvao;
        if (pinnhapvao.length() != 6) {cout << "mã pin bắt buộc phải có 6 chữ số" << '\n';}
        string pindao = PIN;
        reverse(pindao.begin(), pindao.end());
        if (pinnhapvao == pindao) {
            cout << "đã rút ra số tiền: " << A / 2 << '\n';
            cout << "đã báo với với security";
            break;
        }

        if (pinnhapvao == PIN) {
            cout << "nhập số tiền muốn rút a: ";
            cin >> a;
            if (a > A) {cout << "Số tiền rút lớn hơn số dư khả dụng. Bạn bị ảo tưởng sức mạnh tài chính à?";}
            else {
                cout << "Rút thành công" << '\n';
                cout << "          HÓA ĐƠN RÚT TIỀN" << '\n';
                cout << "                      ngày 2 tháng 2 năm 2026" << '\n';
                cout << "                            " << '\n';
                cout << "                            " << '\n';
                cout << "MB Bank" << '\n';
                cout << "Thông tin người rút: Nguyễn Huy Long" << '\n';
                cout << "số tiền đã rút: " << a << '\n';
                cout << "bằng chữ: " << '\n';
                cout << "số dư còn lại: " << A - a << '\n';
                cout << "                       " << '\n';
                cout << "                            " << '\n';
                cout << "                            " << '\n';
                cout << "                                    người rút kí tên           " << '\n';
                cout << "                                    Nguyễn Huy long           " << '\n';

            }
            break;
        }
        else {
            cout << "sai mã PIN" << '\n';
            i++;
            if (i >= solanthu) {
                cout << "thẻ của bạn đã bị khóa";
            }
        }

    }

}





int main()
{
// BT1
    long long a;
    cin >> a;
    hv_dt_cv(a);

//BT2
    long long b;
    cin >> a >> b;
    tinh_hcn(a, b);

// BT3
    long long c;
    cin >> a >> b >> c;
    hlp (a, b, c);


//BT4
    long long x, y;
    cin >> a >> b >> c >> x >> y;
    chay_thu_ham(x, y, a, b, c);

// BT5
    cin >> a >> b >> x;
    giai_phuong_trinh_bac1(a, b, x);

//BT6
    cin >> a >> b >> c >> x;
    giai_phuong_trinh_bac2(a, b, c, x);

//BT7
    long long max, min;
    cin >> a >> b >> c;
    tim_max_min(a, b, c, max, min);

//BT8
    long long n;
    cin >> n >> x;
    dem_so(n, x);


//BT9
    long long chan, le;
    cin >> n >> x >> chan >> le;
    demso_chan_le(n, x, chan, le);

//BT10
    cin >> a;
    ham_switch(a);

//BT11
    long long A, B, C;
    cin >> a >> b >> c >> A >> B >> C;
    giai_hpt_tt_bac2(a, b, c, A, B, C);


//BT12
    long long m, sum;
    cin >> n >> m >> sum;
    tinh_Sm(n, m, sum);

//BT13
    long long M, i;
    cin >> n >> m >> M >> sum >> i;
    tinh_Sm2(n, m, M, sum, i);

//BT14
    long long solanthu;
    cin >> a >> A >> solanthu;
    mo_phong_rut_tien(a, A, solanthu);

}