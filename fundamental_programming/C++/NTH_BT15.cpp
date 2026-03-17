#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// ============================================================
// HÀM SỐ 1: Chu vi & diện tích hình vuông
// ============================================================
void ham1_HinhVuong() {
    cout << "\n===== HAM 1: HINH VUONG =====\n";
    double canh;
    cout << "Nhap canh hinh vuong: ";
    cin >> canh;

    if (canh <= 0) {
        cout << "Canh phai la so duong!\n";
        return;
    }

    double chuVi = 4 * canh;
    double dienTich = canh * canh;

    cout << "Chu vi hinh vuong: " << chuVi << endl;
    cout << "Dien tich hinh vuong: " << dienTich << endl;
}

// ============================================================
// HÀM SỐ 2: Chu vi, diện tích, đường chéo hình chữ nhật
// ============================================================
void ham2_HinhChuNhat() {
    cout << "\n===== HAM 2: HINH CHU NHAT =====\n";
    double dai, rong;
    cout << "Nhap chieu dai: ";
    cin >> dai;
    cout << "Nhap chieu rong: ";
    cin >> rong;

    if (dai <= 0 || rong <= 0) {
        cout << "Chieu dai va chieu rong phai la so duong!\n";
        return;
    }

    double chuVi   = 2 * (dai + rong);
    double dienTich = dai * rong;
    double duongCheo = sqrt(dai * dai + rong * rong);

    cout << "Chu vi hinh chu nhat: " << chuVi << endl;
    cout << "Dien tich hinh chu nhat: " << dienTich << endl;
    cout << "Do dai duong cheo: " << duongCheo << endl;
}

// ============================================================
// HÀM SỐ 3: Kiểm tra hình lập phương / hình hộp chữ nhật
// ============================================================
void ham3_HinhHop() {
    cout << "\n===== HAM 3: HINH HOP =====\n";
    int a, b, c;
    cout << "Nhap 3 so nguyen a, b, c: ";
    cin >> a >> b >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1 << endl;
        return;
    }

    if (a == b && b == c) {
        // Hình lập phương
        cout << "HLP" << endl;

        double dxq   = 4.0 * a * a;        // Diện tích xung quanh = 4 * a^2
        double dtp   = 6.0 * a * a;        // Diện tích toàn phần  = 6 * a^2
        double cheo  = sqrt(3.0) * a;      // Đường chéo           = a*sqrt(3)
        double theT  = (double)a * a * a;  // Thể tích             = a^3

        cout << "Dien tich xung quanh: " << dxq  << endl;
        cout << "Dien tich toan phan : " << dtp  << endl;
        cout << "Duong cheo          : " << cheo << endl;
        cout << "The tich            : " << theT << endl;
    }
    else {
        // Kiểm tra hình hộp chữ nhật: 3 cạnh dương là đủ điều kiện
        // (hình hộp chữ nhật tổng quát với a, b, c > 0 và không phải cả 3 bằng nhau)
        cout << "HHCN" << endl;

        double dxq  = 2.0 * (a*b + b*c);          // 2*(ab + bc) — xung quanh theo chiều cao c
        // Chuẩn: DT xung quanh = chu vi đáy * chiều cao = 2(a+b)*c
        // Ở đây chọn a,b là đáy, c là chiều cao
        double chuViDay = 2.0 * (a + b);
        double dxq2     = chuViDay * c;
        double dtp      = 2.0 * (a*b + b*c + a*c);
        double cheo     = sqrt((double)a*a + (double)b*b + (double)c*c);
        double theT     = (double)a * b * c;

        cout << "Dien tich xung quanh: " << dxq2 << endl;
        cout << "Dien tich toan phan : " << dtp  << endl;
        cout << "Duong cheo          : " << cheo << endl;
        cout << "The tich            : " << theT << endl;
    }
}

// ============================================================
// HÀM SỐ 4: Kiểm tra các hàm toán học trong bảng 2.15
// ============================================================
void ham4_HamToanHoc() {
    cout << "\n===== HAM 4: KIEM TRA CAC HAM TOAN HOC (BANG 2.15) =====\n";
    cout << fixed << setprecision(2);

    // 1. Lũy thừa & Căn
    cout << "1. Luy thua & Can:" << endl;
    cout << "   - sqrt(25.0) = " << sqrt(25.0) << endl;
    cout << "   - pow(2.0, 3.0) = " << pow(2.0, 3.0) << endl;
    cout << "   - exp(1.0) = " << exp(1.0) << " (so e)" << endl;

    // 2. Logarit
    cout << "2. Logarit:" << endl;
    cout << "   - log(2.718) = " << log(2.71828) << " (logarit co so e)" << endl;
    cout << "   - log10(100.0) = " << log10(100.0) << " (logarit co so 10)" << endl;

    // 3. Trị tuyệt đối
    cout << "3. Tri tuyet doi:" << endl;
    cout << "   - abs(-5) = " << abs(-5) << " (cho kieu int)" << endl;
    long so_long = -123456789;
    cout << "   - labs(" << so_long << ") = " << labs(so_long) << " (cho kieu long)" << endl;
    cout << "   - fabs(-7.89) = " << fabs(-7.89) << " (cho kieu double)" << endl;

    // 4. Lượng giác
    cout << "4. Luong giac:" << endl;
    double rad = 0.5236; // ~30 độ
    cout << "   - sin(0.5236) = " << sin(rad) << endl;
    cout << "   - cos(0.5236) = " << cos(rad) << endl;
    cout << "   - tan(0.5236) = " << tan(rad) << endl;

    // 5. Lượng giác ngược
    cout << "5. Luong giac nguoc:" << endl;
    cout << "   - asin(0.5) = " << asin(0.5) << " rad" << endl;
    cout << "   - acos(0.5) = " << acos(0.5) << " rad" << endl;
    cout << "   - atan(1.0) = " << atan(1.0) << " rad" << endl;

    // 6. Làm tròn
    cout << "6. Lam tron:" << endl;
    cout << "   - floor(3.9) = " << floor(3.9) << " (lay so nguyen nho hon)" << endl;
    cout << "   - ceil(3.1) = " << ceil(3.1) << " (lay so nguyen lon hon)" << endl;
}

// ============================================================
// HÀM SỐ 5: Giải phương trình bậc 1: ax + b = 0
// ============================================================
void ham5_PhuongTrinhBac1() {
    cout << "\n===== HAM 5: GIAI PHUONG TRINH BAC 1 (ax + b = 0) =====\n";
    double a, b;
    cout << "Nhap he so a: ";
    cin >> a;
    cout << "Nhap he so b: ";
    cin >> b;
    cout << fixed << setprecision(2);

    if (a == 0) {
        if (b == 0)
            cout << "Phuong trinh co vo so nghiem." << endl;
        else
            cout << "Phuong trinh vo nghiem." << endl;
    } else {
        double x = -b / a;
        cout << "Phuong trinh co nghiem duy nhat: x = " << x << endl;
    }
}

// ============================================================
// HÀM SỐ 6: Giải phương trình bậc 2: ax^2 + bx + c = 0
// ============================================================
void ham6_PhuongTrinhBac2() {
    cout << "\n===== HAM 6: GIAI PHUONG TRINH BAC 2 (ax^2 + bx + c = 0) =====\n";
    double a, b, c;
    cout << "Nhap a: "; cin >> a;
    cout << "Nhap b: "; cin >> b;
    cout << "Nhap c: "; cin >> c;
    cout << fixed << setprecision(2);

    if (a == 0) {
        if (b == 0) {
            if (c == 0) cout << "Phuong trinh co vo so nghiem." << endl;
            else        cout << "Phuong trinh vo nghiem." << endl;
        } else {
            cout << "Phuong trinh bac nhat co nghiem: x = " << -c / b << endl;
        }
    } else {
        double delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "Phuong trinh vo nghiem thuc." << endl;
        } else if (delta == 0) {
            cout << "Phuong trinh co nghiem kep: x = " << -b / (2 * a) << endl;
        } else {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem phan biet:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
    }
}

// ============================================================
// HÀM SỐ 6 BONUS: Giải PT bậc 2 có hỗ trợ nghiệm phức
// ============================================================
void ham6bonus_PhuongTrinhBac2Phuc() {
    cout << "\n===== HAM 6 BONUS: GIAI PT BAC 2 (HO TRO NGHIEM PHUC) =====\n";
    double a, b, c;
    cout << "Nhap a: "; cin >> a;
    cout << "Nhap b: "; cin >> b;
    cout << "Nhap c: "; cin >> c;
    cout << fixed << setprecision(2);

    if (a == 0) {
        if (b == 0) {
            if (c == 0) cout << "Phuong trinh co vo so nghiem." << endl;
            else        cout << "Phuong trinh vo nghiem." << endl;
        } else {
            cout << "Nghiem duy nhat: x = " << -c / b << endl;
        }
    } else {
        double delta = b * b - 4 * a * c;
        if (delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem thuc phan biet:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        } else if (delta == 0) {
            cout << "Phuong trinh co nghiem kep thuc: x = " << -b / (2 * a) << endl;
        } else {
            double realPart      = -b / (2 * a);
            double imaginaryPart = sqrt(-delta) / (2 * a);
            cout << "Phuong trinh co 2 nghiem phuc:" << endl;
            cout << "x1 = " << realPart << " + " << imaginaryPart << "i" << endl;
            cout << "x2 = " << realPart << " - " << imaginaryPart << "i" << endl;
        }
    }
}

// ============================================================
// HÀM SỐ 7: Tìm Max, Min trong n số thực
// ============================================================
void timMaxMin_helper(int n) {
    double so, maxVal, minVal;
    cout << "Nhap so thu 1: ";
    cin >> so;
    maxVal = minVal = so;

    for (int i = 2; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> so;
        if (so > maxVal) maxVal = so;
        if (so < minVal) minVal = so;
    }

    cout << "\n===== KET QUA =====\n";
    cout << fixed << setprecision(2);
    cout << "So lon nhat (Max): " << maxVal << endl;
    cout << "So nho nhat (Min): " << minVal << endl;
    cout << "Chenh lech (Max - Min): " << (maxVal - minVal) << endl;
}

void ham7_TimMaxMin() {
    cout << "\n===== HAM 7: TIM MAX VA MIN TRONG N SO THUC =====\n";
    int n;
    do {
        cout << "Nhap so luong phan tu n (n > 0): ";
        cin >> n;
        if (n <= 0) cout << "Vui long nhap n > 0!\n";
    } while (n <= 0);

    cout << "\nNhap " << n << " so thuc:\n";
    timMaxMin_helper(n);
}

// ============================================================
// HÀM SỐ 8: Đếm số âm, số dương, số 0 trong n số thực
// ============================================================
void ham8_DemAmDuongKhong() {
    cout << "\n===== HAM 8: DEM SO AM, DUONG, KHONG TRONG N SO THUC =====\n";
    int n;
    do {
        cout << "Nhap so luong phan tu n (n > 0): ";
        cin >> n;
        if (n <= 0) cout << "Vui long nhap n > 0!\n";
    } while (n <= 0);

    int dem_so_0 = 0, dem_so_am = 0, dem_so_duong = 0;

    cout << "\nNhap " << n << " so thuc:\n";
    for (int i = 0; i < n; i++) {
        double a;
        cout << "Nhap so thu " << (i + 1) << ": ";
        cin >> a;
        if (a == 0)       dem_so_0++;
        else if (a < 0)   dem_so_am++;
        else              dem_so_duong++;
    }

    cout << "\n===== KET QUA =====\n";
    cout << "So luong so 0: "     << dem_so_0     << endl;
    cout << "So luong so am: "    << dem_so_am    << endl;
    cout << "So luong so duong: " << dem_so_duong << endl;
}

// ============================================================
// HÀM SỐ 9: Đếm số chẵn, số lẻ trong n số nguyên
// ============================================================
void ham9_DemChanLe() {
    cout << "\n===== HAM 9: DEM SO CHAN VA SO LE TRONG N SO NGUYEN =====\n";
    int n;
    do {
        cout << "Nhap so luong phan tu n (n > 0): ";
        cin >> n;
        if (n <= 0) cout << "Vui long nhap n > 0!\n";
    } while (n <= 0);

    int dem_chan = 0, dem_le = 0;

    cout << "\nNhap " << n << " so nguyen:\n";
    for (int i = 0; i < n; i++) {
        int so;
        cout << "Nhap so thu " << (i + 1) << ": ";
        cin >> so;
        if (so % 2 == 0) dem_chan++;
        else             dem_le++;
    }

    cout << "\n===== KET QUA =====\n";
    cout << "So luong so chan: " << dem_chan << endl;
    cout << "So luong so le: "  << dem_le   << endl;
}

// ============================================================
// HÀM SỐ 10: Đọc số thành chữ (0–20)
// ============================================================
void soThanhChu_helper(int n) {
    switch (n) {
        case 0:  cout << "Zero";      break;
        case 1:  cout << "One";       break;
        case 2:  cout << "Two";       break;
        case 3:  cout << "Three";     break;
        case 4:  cout << "Four";      break;
        case 5:  cout << "Five";      break;
        case 6:  cout << "Six";       break;
        case 7:  cout << "Seven";     break;
        case 8:  cout << "Eight";     break;
        case 9:  cout << "Nine";      break;
        case 10: cout << "Ten";       break;
        case 11: cout << "Eleven";    break;
        case 12: cout << "Twelve";    break;
        case 13: cout << "Thirteen";  break;
        case 14: cout << "Fourteen";  break;
        case 15: cout << "Fifteen";   break;
        case 16: cout << "Sixteen";   break;
        case 17: cout << "Seventeen"; break;
        case 18: cout << "Eighteen";  break;
        case 19: cout << "Nineteen";  break;
        case 20: cout << "Twenty";    break;
        default: cout << "So khong nam trong khoang 0-20"; break;
    }
}

void ham10_SoThanhChu() {
    cout << "\n===== HAM 10: DOC SO THANH CHU (0-20) =====\n";
    int n;
    cout << "Nhap mot so nguyen tu 0 den 20: ";
    cin >> n;
    cout << "So " << n << " bang tieng Anh la: ";
    soThanhChu_helper(n);
    cout << endl;
}

// ============================================================
// HÀM SỐ 11: Giải hệ phương trình tuyến tính 2 ẩn
// ============================================================
void giaiHePT_helper(double a, double b, double c, double A, double B, double C) {
    cout << "\n===== HE PHUONG TRINH =====\n";
    cout << fixed << setprecision(2);
    cout << "{ " << a << "x + " << b << "y = " << c << endl;
    cout << "{ " << A << "x + " << B << "y = " << C << endl;
    cout << "\n===== GIAI =====\n";

    double D  = a * B - A * b;
    double Dx = c * B - C * b;
    double Dy = a * C - A * c;

    if (D != 0) {
        cout << "He co nghiem duy nhat:\n";
        cout << "x = " << Dx / D << endl;
        cout << "y = " << Dy / D << endl;
    } else {
        if (Dx == 0 && Dy == 0) {
            cout << "He co vo so nghiem (phuong trinh phu thuoc tuyen tinh)\n";
            if (b != 0)
                cout << "Nghiem tong quat: x = t, y = (" << c << " - " << a << "t) / " << b << " (t la tham so bat ky)\n";
            else if (B != 0)
                cout << "Nghiem tong quat: x = t, y = (" << C << " - " << A << "t) / " << B << " (t la tham so bat ky)\n";
        } else {
            cout << "He vo nghiem (phuong trinh mau thuan)\n";
        }
    }
}

void ham11_GiaiHePhuongTrinh() {
    cout << "\n===== HAM 11: GIAI HE PHUONG TRINH TUYEN TINH 2 AN =====\n";
    cout << "He co dang: { ax + by = c\n";
    cout << "            { Ax + By = C\n\n";

    double a, b, c, A, B, C;
    cout << "--- Phuong trinh thu nhat ---\n";
    cout << "Nhap a: "; cin >> a;
    cout << "Nhap b: "; cin >> b;
    cout << "Nhap c: "; cin >> c;
    cout << "--- Phuong trinh thu hai ---\n";
    cout << "Nhap A: "; cin >> A;
    cout << "Nhap B: "; cin >> B;
    cout << "Nhap C: "; cin >> C;

    giaiHePT_helper(a, b, c, A, B, C);
}

// ============================================================
// HÀM SỐ 12: Tính tổng Sm = 1^m + 2^m + ... + n^m
// ============================================================
void ham12_TongLuyThua() {
    cout << "\n===== HAM 12: TINH TONG Sm = 1^m + 2^m + ... + n^m =====\n";
    int m, n;
    cout << "Nhap m, n = ";
    cin >> m >> n;

    double Sm = 0;
    if (m == 0)
        Sm = n; // i^0 = 1 voi moi i, nen tong = n
    else
        for (int i = 1; i <= n; ++i)
            Sm += pow(i, m);

    cout << "Sm = " << Sm << '\n';
}

// ============================================================
// HÀM SỐ 13: Tính tổng Sm = 1^m + 2^m + ... không vượt quá M
// ============================================================
void ham13_TongKhongVuotM() {
    cout << "\n===== HAM 13: TINH TONG Sm = 1^m + 2^m + ... <= M =====\n";
    int m;
    double M;
    cout << "Nhap m, M = ";
    cin >> m >> M;

    // Cách 1: dùng vòng lặp while
    double Sm = 0;
    int i = 1;
    double term = 1; // term = i^m, bắt đầu với i=1
    while (Sm + term <= M) {
        Sm += term;
        ++i;
        term = pow(i, m);
    }
    cout << "[While] Sm = " << Sm << '\n';

    // Cách 2: dùng vòng lặp for
    Sm = 1;
    int max_iteration = 10000;
    for (i = 2; i <= max_iteration; ++i) {
        term = pow(i, m);
        if (Sm + term > M) break;
        else Sm += term;
    }
    cout << "[For]   Sm = " << Sm << '\n';
}

// ============================================================
// HÀM SỐ 14: Mô phỏng ATM rút tiền có PIN
// ============================================================
void ham14_MoPhongATM() {
    cout << "\n===== HAM 14: MO PHONG ATM RUT TIEN CO PIN =====\n";

    double A;
    cout << "Nhap so du tai khoan A = ";
    cin >> A;

    string true_PIN, input_PIN;
    cout << "Nhap PIN dung (6 chu so): ";
    cin >> true_PIN;

    int max_trial;
    cout << "Nhap so lan nhap PIN toi da: ";
    cin >> max_trial;

    bool ok = false;
    for (int i = 1; i <= max_trial; ++i) {
        cout << "Nhap PIN lan " << i << ": ";
        cin >> input_PIN;
        if (input_PIN == true_PIN) {
            ok = true;
            break;
        } else {
            if (i < max_trial)
                cout << "Sai PIN. Vui long nhap lai.\n";
        }
    }

    if (ok) {
        cout << "Ma PIN dung. Cho phep rut tien.\n";
        cout << "Nhap so tien muon rut (a) = ";
        double a;
        cin >> a;

        if (a > A) {
            cout << "So tien rut lon hon so du kha dung. Giao dich that bai!\n";
        } else {
            cout << "Ban da rut thanh cong " << a << " VND.\n";
            cout << "So du kha dung con lai: " << A - a << " VND.\n";
            cout << "Ban muon in hoa don? (Yes/No): ";
            string bill;
            cin >> bill;
            if (bill == "Yes")
                cout << "Dang in hoa don. Vui long doi nhan hoa don, cash & the.\n";
            else
                cout << "Vui long doi nhan cash & the.\n";
            cout << "Cam on ban da giao dich tai ngan hang X.\n";
        }
    } else {
        cout << "Ban da bi khoa the do nhap sai PIN qua so lan cho phep.\n";
        cout << "Vui long lien he chi nhanh ngan hang X gan nhat de duoc ho tro.\n";
    }
}

// ============================================================
// MAIN — gọi lần lượt tất cả 14 hàm
// ============================================================
int main() {
    ham1_HinhVuong();
    ham2_HinhChuNhat();
    ham3_HinhHop();
    ham4_HamToanHoc();
    ham5_PhuongTrinhBac1();
    ham6_PhuongTrinhBac2();
    ham6bonus_PhuongTrinhBac2Phuc();
    ham7_TimMaxMin();
    ham8_DemAmDuongKhong();
    ham9_DemChanLe();
    ham10_SoThanhChu();
    ham11_GiaiHePhuongTrinh();
    ham12_TongLuyThua();
    ham13_TongKhongVuotM();
    ham14_MoPhongATM();

    return 0;
}