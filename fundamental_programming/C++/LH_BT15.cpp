#include <cmath>
#include <iostream>
using namespace std;
// Bài tập 1:
void hinh_vuong(float canh) {
    float chuvi;
    chuvi = canh * 4;
    cout << "\nChu vi hình vuông bằng " << chuvi << endl;
    float dientich;
    dientich = canh * canh;
    cout << "\nDien tich hình vuông bằng " << dientich << endl;
}
// Bài tập 2:
void hinh_chu_nhat (float chieudai, float chieurong) {
    float chuvichunhat;
    chuvichunhat = ( chieudai + chieurong ) * 2;
    cout << "\nChu vi hình chữ nhật bằng " << chuvichunhat << endl;
    float dientichchunhat;
    dientichchunhat = chieudai * chieurong;
    cout << "\nDiện tích hình chữ nhật bằng " << dientichchunhat << endl;
    float dodaiduongcheochunhat;
    dodaiduongcheochunhat = sqrt(pow(chieudai, 2) + pow(chieurong, 2));
    cout << "\nĐộ dài đường chéo hình chữ nhật bằng " << dodaiduongcheochunhat << endl;
}
//Bài tập 3:
void kiem_tra_hinh(int a, int  b, int c) {
    // Kiểm  tra hình lập phương
    if (a == b && b == c && a > 0) { cout << "HLP"; }
    //Kiểm tra hình hộp chữ nhật
    else if (a > 0 && b > 0 && c > 0) {
        cout << "HHCN" << endl;
        int dientichxungquanh;
        dientichxungquanh = 2 * c * ( a + b );
        cout << "Diện tích xung quanh= " << dientichxungquanh << endl;
        int dientichtoanphan;
        dientichtoanphan = dientichxungquanh + 2 * ( a * b );
        cout << "\nDiện tích toàn phần= " << dientichtoanphan << endl;
        int duongcheo;
        duongcheo = sqrt (a * a + b * b + c * c);
        cout << "\nĐường chéo= " << duongcheo << endl;
        int thetich;
        thetich = a * b * c;
        cout << "\nThể tích= " << thetich << endl;
    }
    // Không phải hình hộp chữ nhật
    else {
        cout << "\n-1";
    }
}
//Bài tập 4:
void chay_thu_ham(double x, double z, double t, double h, double a, double b, int c, long r, double j, double d, double e, double f) {
    if (x < 0) cout << "x must be nonnegative";
    else cout << sqrt(x) << '\n';
    if (z < 0 || t < 0 ) cout << "x must be nonnegative";
    else cout << pow(z, t) << '\n';
    cout << exp(h) << '\n';
    cout << log(a) << '\n';
    cout << log10(b) << '\n';
    cout << abs(c) << labs(r) << fabs(j) << '\n';
    cout << cos(d) << sin(d) << tan(d) << '\n';
    cout << acos(e) << asin(e) << atan(e) << '\n';
    cout << floor(f) << ceil(f) << '\n';
}
// Bài tập 5:
void phuong_trinh_bat_nhat (double v, double k) {
    if (v == 0) {
        if (k == 0) {
            cout << "Vô số nghiệm";
        } else {
            cout << "Vô nghiệm";
        }
    } else {
        cout << double(-k / v);
    }
}
//Bài tập 6
void phuong_trinh_bat_2 (double n, double m, double l) {
    if (n == 0) {
        if (m == 0) {
            if (l == 0) {
                cout << "Vo so nghiem." << endl;
            } else {
                cout << "Vo nghiem." << endl;
            }
        } else {
            cout << "x = " << -l / m << endl;
        }
    }
    else {
        double delta = m * m - 4 * n * l;
        if (delta > 0 ) {
            cout << "Hai nghiem phan biet: \n";
            cout << "x= " << (-m + sqrt(delta)) / (2 * n) << endl;
            cout << "x= " << (-m - sqrt(delta)) / (2 * n) << endl;
        }
        else if (delta == 0) {
            cout << "Phuong trinh co nghiem kep: " << endl;
            cout << "x= " << -m / (2 * n) << endl;
        }
        else if (delta < 0) {
            cout << "Phuong trinh co 2 nghiem phuc: " << endl;
            cout << "x= " << -m / (2 * n) << " + " << sqrt(abs(delta)) / (2 * n) << "i" << endl;
            cout << "x= " << -m / (2 * n) << " - " << sqrt(abs(delta)) / (2 * n) << "i" << endl;
        }
    }
}
// Bài tập 7
void max_min(double a, double b, double c) {
    double maxVal = a;
    double minVal = a;
    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;
    if (b < minVal) minVal = b;
    if (c < minVal) minVal = c;
    cout << "So lon nhat: " << maxVal << endl;
    cout << "So nho nhat: " << minVal << endl;
}
//Bài tập 8
void dem_so(int n, double x) {
    int dem0 = 0, demAm = 0, demDuong = 0;
    for (int i = 1; i <= n; i++) {
        if (x == 0) dem0++;
        else if (x < 0) demAm++;
        else demDuong++;
    }
    cout << "So so 0: " << dem0 << endl;
    cout << "So so am: " << demAm << endl;
    cout << "So so duong: " << demDuong << endl;

}
//Bài tập 9
void chan_le(int n, int x) {
    int demChan = 0, demLe = 0;
    for (int i = 1; i <= n; i++) {
        if (x % 2 == 0) demChan++;
        else demLe++;
    }
    cout << "So chan: " << demChan << endl;
    cout << "So le: " << demLe << endl;

}
void docSo(int n) {
    switch (n) {
    case 0: cout << "zero"; break;
    case 1: cout << "one"; break;
    case 2: cout << "two"; break;
    case 3: cout << "three"; break;
    case 4: cout << "four"; break;
    case 5: cout << "five"; break;
    case 6: cout << "six"; break;
    case 7: cout << "seven"; break;
    case 8: cout << "eight"; break;
    case 9: cout << "nine"; break;
    case 10: cout << "ten"; break;
    case 11: cout << "eleven"; break;
    case 12: cout << "twelve"; break;
    case 13: cout << "thirteen"; break;
    case 14: cout << "fourteen"; break;
    case 15: cout << "fifteen"; break;
    case 16: cout << "sixteen"; break;
    case 17: cout << "seventeen"; break;
    case 18: cout << "eighteen"; break;
    case 19: cout << "nineteen"; break;
    case 20: cout << "twenty"; break;
    default: cout << "Khong hop le"; break;
    }
}
//Bài tập 11
void he_phuong_trinh(double a, double b, double c, double A, double B, double C) {
    double D = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;

    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        cout << "He co nghiem duy nhat:" << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    } else {
        if (Dx == 0 && Dy == 0) {
            cout << "He co vo so nghiem" << endl;
        } else {
            cout << "He vo nghiem" << endl;
        }
    }
}
//Bài tập 12
void baitap12 (int n, int m) {
    double sm = 0;
    for (int i = 1; i <= n; i++) { sm += pow(i, m); }
    cout << "Sm= " << sm;
}
//Bài tập 13
void baitap13(double M, int m) {
    int n = 0;
    double sm = 0;
    cin >> m >> M;
    while (true) {
        long long a = pow(n + 1, m);
        if (sm + a <= M) {
            n++;
            sm += a;
        } else {
            break;
        }
    }
    cout << "n = " << n << endl;
    cout << "Sm= " << sm << endl;
}
//Bài tập 14
void nganhang(long long soDu, long long maPinDung, long long soLanChoPhep, long long maPinNhap, long long tienRut) {
    long long maPinNguoc = 0;
    long long tam = maPinDung;
    while (tam > 0) {
        maPinNguoc = maPinNguoc * 10 + tam % 10;
        tam /= 10;
    }
    int dem = 0;
    while (dem < soLanChoPhep) {
        cout << "Nhap ma PIN: ";
        cin >> maPinNhap;
        if (maPinNhap == maPinNguoc) {
            cout << "CANH BAO AN NINH! KHOA HE THONG.";
        }

        if (maPinNhap == maPinDung) {
            break;
        } else {
            dem++;
            if (dem == soLanChoPhep) {
                cout << "KHOA THE";
            }
            cout << "Sai PIN. Nhap lai.\n";
        }
    }
    cout << "Nhap so tien can rut: ";
    cin >> tienRut;
    if (tienRut > soDu) {
        cout << "So tien rut lon hon so du kha dung. Ban bi ao tuong suc manh tai chinh a?";
    } else {
        soDu = soDu - tienRut;
        cout << "HOA DON GIAO DICH\n";
        cout << " So tien rut: " << tienRut << " VND\n";
        cout << " So du con lai: " << soDu << " VND\n";
    }
}
int main()
{
    float canh;
    cin >> canh;
    hinh_vuong(canh);
//Bài tập 2:
    float chieudai;
    cin >> chieudai;
    float chieurong;
    cin >> chieurong;
    hinh_chu_nhat(chieudai, chieurong);
// Bài tập 3:
    int a; // Chiều dài
    cin >> a;
    int b; // Chiều rộng
    cin >> b;
    int c; // Chiều cao
    cin >> c;
    kiem_tra_hinh (a, b, c);
//Bài tập 4:
    cout << "Bài tập 4: \n";
    double x, z, t, h, j, d, e, f;
    cin >> x >> z >> t >> h >> a >> b >> j >> d >> e >> f;
    long r;
    cin >> c >> r;
    chay_thu_ham(x, z, t, h, a, b, j, d, e, f, c, r);
//Bài tập 5
    double v, k;
    cin >> v >> k;
    phuong_trinh_bat_nhat(v, k);
//bài tập 6
    double n, m, l;
    cin >> n >> m >> l;
    phuong_trinh_bat_2(n, m, l);
//Bài tập 7
    cin >> a >> b >> c;
    max_min(a, b, c);
//Bài tập 8
    cin >> n;
    cin >> x;
    dem_so(n, x);
//Bài tập 9
    cin >> n;
    cin >> x;
    chan_le(n, x);
//Bài tập 10
    cin >> n;
    docSo(n);
//Bài tập 11
    double A, B, C;
    cin >> a >> b >> c;
    cin >> A >> B >> C;
    he_phuong_trinh(a, b, c, A, B, C);
//Bài tập 12
    cin >> n >> m;
    baitap12 (n, m);
//Bài tập 13
    double M;
    cin >> M >> m;
    baitap13 (M, m);
//Bài tập 14
    long long soDu, maPinDung, soLanChoPhep, maPinNhap, tienRut;
    cin >> soDu >> maPinDung >> soLanChoPhep;
    nganhang(soDu, maPinDung, soLanChoPhep, maPinNhap, tienRut);
}