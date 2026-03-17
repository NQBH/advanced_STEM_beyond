#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm> 
using namespace std;


// ---------------- BT1 ----------------


void hinh_vuong() {
    float canhA;

    cout << "Nhap canh hinh vuong: ";
    cin >> canhA;

    if (canhA <= 0) {
        cout << -1;
        return;
    }

    float chuVi = 4 * canhA;
    float dienTich = canhA * canhA;

    cout << "Chu vi hinh vuong la: " << chuVi << endl;
    cout << "Dien tich hinh vuong la: " << dienTich << endl;
}


// ---------------- BT2 ----------------


void hinh_chu_nhat() {
    float chieuDai, chieuRong;

    cout << "Nhap chieu dai cua hinh chu nhat: " << endl;
    cin >> chieuDai;

    cout << "Nhap chieu rong cua hinh chu nhat: " << endl;
    cin >> chieuRong;

    float chuVi = 2 * (chieuDai + chieuRong);
    float dienTich = chieuDai * chieuRong;
    float duongCheoHinhChuNhat = sqrt(chieuDai * chieuDai + chieuRong * chieuRong);

    cout << "Chu vi hinh chu nhat la: " << chuVi << endl;
    cout << "Dien tich hinh chu nhat la: " << dienTich << endl;
    cout << "Do dai duong cheo hinh chu nhat la: " << duongCheoHinhChuNhat << endl;
}


// ---------------- BT3 ----------------
void hinh_lap_phuong_hoac_hop_chu_nhat() {
    int canhA, canhB, canhC;

    cout << "Nhap canh A: " << endl;
    cin >> canhA;

    cout << "Nhap canh B: " << endl;
    cin >> canhB;

    cout << "Nhap canh C: " << endl;
    cin >> canhC;

    if (canhA > 0 && canhA == canhB && canhB == canhC) {
        cout << "HLP";
        return;
    }

    if (canhA > 0 && canhB > 0 && canhC > 0) {
        cout << "HHCN" << endl;

        int dienTichXungQuanh = 2 * (canhA + canhB) * canhC;
        int dienTichToanPhan = 2 * (canhA * canhB + canhB * canhC + canhA * canhC);
        double duongCheoHHCN = sqrt(canhA * canhA + canhB * canhB + canhC * canhC);
        int theTichHHCN = canhA * canhB * canhC;

        cout << "Dien tich xung quanh: " << dienTichXungQuanh << endl;
        cout << "Dien tich toan phan: " << dienTichToanPhan << endl;
        cout << "Duong cheo: " << duongCheoHHCN << endl;
        cout << "The tich: " << theTichHHCN << endl;

        return;
    }

    cout << -1;
}


// ---- BT4------------
void cac_ham_toan_hoc() {
    double x;
    double y;

    cout << "Nhap so x: "<< endl;
    cin >> x;
    cout << "Nhap so y: "<< endl;
    cin >> y;

    cout << "TINH CAN BAC HAI" << endl;

    if (x < 0) {
        cout << "sqrt(x): x phai >=0." << endl;
    } else {
        cout << "sqrt(x) can bac hai = " << sqrt(x) << endl;
    }

    cout << "TINH LUY THUA" << endl;
    cout << "pow(x, y) = " << pow(x, y) << endl;

    cout << "TINH e^x VOI e LA CO SO LOGARIT" << endl;
    cout << "exp(x) = " << exp(x) << endl;

    cout << "TINH LOGARIT TU NHIEN CUA x" << endl;
    if (x <=0) {
        cout << "log(x): x phai lon hon (>) 0 " << endl;
    }
    else {
        cout << "log(x) = " << log(x) << endl;
    }

    cout << "TINH LOGARIT CO SO 10" <<endl;

    if (x <=0) {
        cout << "log10(x): x phai lon hon 0." << endl;
    }
    else {
        cout << "log10(x) = " << log10(x) << endl;
    }

    cout << "TINH TRI TUYET DOI" <<endl;

    int a;
    long b;
    double c;

    cout << "Nhap so a: " << endl;
    if (!(cin >> a)) {
        cout << "Gia tri so a ban vua nhap khong hop le (phai la so nguyen)." << endl;
        return;
    }

    cout << "Nhap so b: " << endl;
    if (!(cin >> b)) {
        cout << "Gia tri so b ban vua nhap khong hop le (phai la so nguyen)." << endl;
        return;
    }

    cout << "Nhap so c: " << endl;
    if (!(cin >> c)) {
        cout << "Gia tri so c ban vua nhap khong hop le (phai la so thuc)." << endl;
        return;
    }

    cout << "abs(a) = " << abs(a) << endl;
    cout << "labs(b) = " << labs(b) << endl;
    cout << "fabs(c) = " << fabs(c) << endl;

    double g;

    cout << "TINH CAC HAM LUONG GIAC" << endl;
    cout << "Nhap g (radian): " << endl;
    cin >> g;

    cout << "sin(g) = " << sin(g) << endl;
    cout << "cos(g) = " << cos(g) << endl;
    cout << "tan(g) = " << tan(g) << endl;

    double t;

    cout << "TINH CAC HAM LUONG GIAC NGUOC." << endl;
    cout << "Nhap t (thuoc [-1;1]) de tinh asin, acos, atan: " << endl;
    cin >> t;

    if (t < -1 || t > 1) {
        cout << "asin(t), acos(t): t phai thuoc trong tap [-1; 1] " << endl;
    }
    else {
        cout << "asin(t)= " << asin(t) << endl;
        cout << "acos(t)= " << acos(t) << endl;
    }
    cout << "atan(t) = " << atan(t) << endl;

    double f;

    cout << "TINH FLOOR VA CEIL." << endl;
    cout << "Nhap f de tinh floor va ceil: " << endl;
    cin >> f;

    cout << "floor(f) = " << floor(f) << endl;
    cout << "ceil(f) = " << ceil(f) << endl;
}


// ------------ BT5--------------
void giai_phuong_trinh_bac_nhat() {

    float a, b;
    float x;

    cout << "GIAI PHUONG TRINH BAC NHAT" << endl;

    cout << "Nhap so a: ";
    cin >> a;

    cout << "Nhap so b: ";
    cin >> b;

    if (a == 0) {

        if (b == 0) {
            cout << "Phuong trinh co vo so nghiem." << endl;
        } else {
            cout << "Phuong trinh vo nghiem." << endl;
        }
    } else {
        x = - b / a;
        cout << "Phuong trinh co nghiem x = " << x << endl;
    }
}


// ---------------- Bt6-------
void giai_phuong_trinh_bac_hai() {

    float a, b, c;

    cout << "GIAI PHUONG TRINH BAC HAI" << endl;

    cout << "Nhap so a: ";
    cin >> a;

    cout << "Nhap so b: ";
    cin >> b;

    cout << "Nhap so c: ";
    cin >> c;

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Phuong trinh co vo so nghiem"<< endl;
            } else {
                cout << "Phuong trinh tren vo nghiem"<< endl;
            }
        }
        else {
            float x = - c / b;
            cout << "Phuong trinh co so nghiem x = " << x << endl;
        }
    }
    else {
        float delta = pow(b, 2) - 4*a*c;

        if (delta > 0) {

            float x1 = ( - b + sqrt(delta)) / (2*a);
            float x2 = (-b - sqrt(delta)) / (2*a);

            cout << "Phuong trinh co 2 nghiem phan biet:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }

        else if ( delta == 0 ) {

            float x = - b / ( 2 * a );
            cout << "Phuong trinh co nghiem kep x = " << x << endl;
        }

        else {

            float phanNghiemThuc = - b / ( 2 * a );
            float phanNghiemAo = sqrt ( -delta ) / ( 2 * a );

            cout << "Phuong trinh co 2 nghiem phuc:" << endl;
            cout << "x1 = " << phanNghiemThuc << " + " << phanNghiemAo << "i" << endl;
            cout << "x2 = " << phanNghiemThuc << " - " << phanNghiemAo << "i" << endl;
        }
    }
}


// ---------main--------------

void tim_max_min();
void dem_so_am_duong_khong();
void dem_so_chan_le();
void doc_so_tu_0_den_20();
void giai_he_phuong_trinh_2_an();
void tinh_tong_luy_thua();
void tinh_tong_co_dieu_kien();
void mo_phong_atm();


int main() {

    hinh_vuong();

    hinh_chu_nhat();

    hinh_lap_phuong_hoac_hop_chu_nhat();

    cac_ham_toan_hoc();

    giai_phuong_trinh_bac_nhat();

    giai_phuong_trinh_bac_hai();

    tim_max_min();

    dem_so_am_duong_khong();

    dem_so_chan_le();

    doc_so_tu_0_den_20();

    giai_he_phuong_trinh_2_an();

    tinh_tong_luy_thua();

    tinh_tong_co_dieu_kien();

    mo_phong_atm();

    return 0;
}


// ---------------- BT7 ----------------
void tim_max_min() {

    double a;
    double b;
    double c;
    double vMax;
    double vMin;

    cout << "Nhap so a: " << endl;
    cin >> a;

    cout << "Nhap so b: " << endl;
    cin >> b;

    cout << "Nhap so c: " << endl;
    cin >> c;

    vMax = a;
    vMin = a;

    if (b > vMax) vMax = b;
    if (c > vMax) vMax = c;

    if (b < vMin) vMin = b;
    if (c < vMin) vMin = c;

    cout << "Max cua 3 so thuc = " << vMax << endl;
    cout << "Min cua 3 so thuc = " << vMin << endl;


    int n; 
    double soX;
    double maxSoN, minSoN;

    cout << "Nhap n (bao nhieu so n ban muon nhap): " << endl;
    cin >> n;

    cout << "Nhap so thuc thu nhat: " << endl;
    cin >> soX;
    maxSoN = soX;
    minSoN = soX;

    for (int i = 2; i <= n; i++) {
        cout << "Nhap so thu" << i << ": " << endl;
        cin >> soX;

        if (soX > maxSoN) maxSoN = soX;
        if (soX < minSoN) minSoN = soX;
    }

    cout << "So lon nhat trong n so la: " << maxSoN << endl;
    cout << "So nho nhat trong n so la: " << minSoN << endl;
}


// ---------------- BT8 ----------------
void dem_so_am_duong_khong() {

    int n; 
    cout << "Nhap n= " << endl;
    cin >> n;

    double a;
    int demSo0 = 0;
    int demSoAm = 0;
    int demSoDuong = 0;

    for (int i = 1; i <= n; i++) {
        cout << " Nhap so a" << i << "= " << endl;
        cin >> a;

        if (a == 0)
            demSo0++;
        else if (a < 0)
            demSoAm++;
        else
            demSoDuong++;
    }

    cout << "So luong so 0: " << demSo0 << endl;
    cout << "So luong so am la: " << demSoAm << endl;
    cout << "So luong so duong la: " << demSoDuong << endl;
}


// ---------------- BT9 ----------------
void dem_so_chan_le() {

    int n;
    cout << "Nhap so luong so nguyen n: ";
    cin >> n;

    int x;
    int demSoChan = 0;
    int demSoLe = 0;

    for (int i = 1; i <= n; i++) {

        cout << "Nhap so thu x " << i << "= ";
        cin >> x;

        if (x % 2 == 0)
            demSoChan++;
        else
            demSoLe++;
    }

    cout << "So luong so chan: " << demSoChan << endl;
    cout << "So luong so le: " << demSoLe << endl;
}


// ---------------- BT10 ----------------
void doc_so_tu_0_den_20() {

    int n;
    cout << "Nhap n: " << endl;
    cin >> n;

    switch(n) {
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

        default: 
            cout << "So ngoai cac so 0-20, so ban vua nhap la khong hop le. Xin moi nhap lai!!";
    }
}


// ---------------- BT11 ----------------
void giai_he_phuong_trinh_2_an() {

    double a;
    cout << "Nhap a: " << endl;
    cin >> a;

    double b;
    cout << "Nhap b: " << endl;
    cin >> b;

    double c;
    cout << "Nhap c: " << endl;
    cin >> c;

    double A;
    cout << "Nhap A: " << endl;
    cin >> A;

    double B;
    cout << "Nhap B: " << endl;
    cin >> B;

    double C;
    cout << "Nhap C: " << endl;
    cin >> C;

    double D;
    double Dx;
    double Dy;

    D  = a * B - A * b;
    Dx = c * B - C * b;
    Dy = a * C - A * c;

    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;

        cout << "He phuong trinh co nghiem duy nhat:" << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
    else {
        if (Dx == 0 && Dy == 0)
            cout << "He phuong trinh co vo so nghiem." << endl;
        else
            cout << "He phuong trinh vo nghiem." << endl;
    }
}

// ---------------- BT12 ----------------
void tinh_tong_luy_thua() {

    int n, m;
    double Sm = 0;

    cout << "Nhap n: " << endl;
    cin >> n;

    cout << "Nhap m: " << endl;
    cin >> m;

    for (int i = 1; i <= n; ++i) {
        Sm += pow(i, m);
    }

    cout << Sm;
}


// ---------------- BT13 ----------------
void tinh_tong_co_dieu_kien() {

    int n;
    int m;
    double M;
    double Sm = 0;

    cout << "Nhap n: ";
    cin >> n;

    cout << "Nhap m: ";
    cin >> m;

    cout << "Nhap M: ";
    cin >> M;

    for (int i = 1; i <= n; ++i) {
        double t = pow(i, m);

        if (Sm + t > M) break;

        Sm += t;
    }

    cout << "Sm = " << Sm << endl;
}


// ---------------- BT14 ----------------
void mo_phong_atm() {

    long long so_du, so_rut;
    string pin_that, pin_nhap;
    int so_lan_toi_da;

    cout << "Nhap so du tai khoan (VND): ";
    cin >> so_du;

    cout << "Nhap so tien muon rut (VND): ";
    cin >> so_rut;

    do {
        cout << "Nhap ma PIN (6 chu so): ";
        cin >> pin_that;
    } while (pin_that.length() != 6);

    cout << "Nhap so lan nhap PIN toi da: ";
    cin >> so_lan_toi_da;

    string pin_nguoc = pin_that;
    reverse(pin_nguoc.begin(), pin_nguoc.end());

    bool dung_pin = false;

    for (int i = 1; i <= so_lan_toi_da; i++) {
        cout << "Nhap PIN (lan " << i << "): ";
        cin >> pin_nhap;

        if (pin_nhap == pin_nguoc) {
            cout << "Security! The bi khoa." << endl;
            return;
        }

        if (pin_nhap == pin_that) {
            dung_pin = true;
            break;
        }

        cout << "PIN sai!" << endl;
    }

    if (!dung_pin) {
        cout << "Ban da nhap sai qua so lan cho phep. The bi khoa." << endl;
        return;
    }

    if (so_rut > so_du) {
        cout << "So tien rut lon hon so du kha dung. Ban bi ao tuong suc manh tai chinh a?" << endl;
    } else {
        so_du -= so_rut;
        cout << endl << "===== HOA DON ATM =====" << endl;
        cout << "So tien rut: " << so_rut << " VND" << endl;
        cout << "So du con lai: " << so_du << " VND" << endl;
        cout << "Giao dich rut tien thanh cong" << endl;
    }
}