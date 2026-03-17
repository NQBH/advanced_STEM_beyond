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
void thong_so_hinh_hop(float a, float b, float c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1 << endl; 
    } else {
        if (a == b && b == c) cout << "HLP" << endl;
        else cout << "HHCN" << endl;
        
        float dientichxungquanh = 2 * (a + b) * c;
        float dientichtoanphan = 2 * (a * b + b * c + c * a);
        float duongcheo = sqrt(a * a + b * b + c * c);
        float thetich = a * b * c;
        
        cout << "Dien tich xung quanh la: " << dientichxungquanh << endl;
        cout << "Dien tich toan phan la: " << dientichtoanphan << endl;
        cout << "Duong cheo la: " << duongcheo << endl;
        cout << "The tich la: " << thetich << endl;
    }
}

// BT4 midterm
void kiem_tra_cac_ham(double x, double y) {
    if (x < 0) cout << "x must be non-negative" << endl;
    else cout << sqrt(x) << endl;
    
    cout << "pow=" << pow(x, y) << endl;
    cout << "log=" << log(x) << endl;
    cout << "log10=" << log10(x) << endl;
    cout << "abs=" << abs(x) << endl;
    cout << "labs=" << labs((long int)x) << endl;
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
void ptb1(double a, double b) {
    cout << "Phuong trinh cua toi la: " << a << "x + " << b << " = 0" << endl;
    if (a == 0) {
        if (b == 0) cout << "Ket qua: Phuong trinh vo so nghiem" << endl;
        else cout << "Ket qua: Phuong trinh vo nghiem" << endl;
    } else {
        cout << "Ket qua: x = " << -b / a << endl;
    }
}

// BT6 midterm
void ptb2(double q, double w, double e) {
    cout << "Ket qua phuong trinh bac hai: " << q << "x^2 + " << w << "x + " << e << " = 0" << endl;
    if (q == 0) {
        if (w == 0) {
            if (e == 0) cout << "Phuong trinh vo so nghiem" << endl;
            else cout << "Phuong trinh vo nghiem" << endl;
        } else {
            cout << "Phuong trinh co mot nghiem: " << -e / w << endl;
        }
    } else {
        double delta = w * w - 4 * q * e;
        if (delta > 0) {
            double x1 = (-w + sqrt(delta)) / (2 * q);
            double x2 = (-w - sqrt(delta)) / (2 * q);
            cout << "Phuong trinh co hai nghiem phan biet:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        } else if (delta == 0) {
            cout << "Phuong trinh co nghiem kep: " << -w / (2 * q) << endl;
        } else {
            double phanthuc = -w / (2 * q);
            double phanao = sqrt(abs(delta)) / (2 * q);
            cout << "Phuong trinh co hai nghiem phuc:" << endl;
            cout << "x1 = " << phanthuc << " + " << phanao << " i" << endl;
            cout << "x2 = " << phanthuc << " - " << phanao << " i" << endl;
        }
    }
}

// BT7 midterm
void min_max(double a, double b, double c) {
    double maxVal = a;
    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;
    double minVal = a;
    if (b < minVal) minVal = b;
    if (c < minVal) minVal = c;
    cout << "So lon nhat la: " << maxVal << endl;
    cout << "So nho nhat la: " << minVal << endl;
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
void doc_so(int n) {
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
void tong_chuoi_luy_thua(int n, int m) {
    double S = 0;
    for (int i = 1; i <= n; ++i) {
        S += pow(i, m);
    }
    cout << "So mu = " << S << endl;
}

// BT13 midterm
void tong_luy_thua_max(int n, int m, double M) {
    double S = 0;
    for (int i = 1; i <= n; ++i) {
        double sotieptheo = pow(i, m);
        if (S + sotieptheo <= M) {
            S += sotieptheo;
        } else {
            break;
        }
    }
    cout << "Gia tri lon nhat khong vuot qua M la: " << S << endl;
}

// BT14 midterm
void quan_ly_atm(long long A, int max_trial) {
    string realPIN = "123456"; 
    string pinInput;    
    long long a;
    int count = 0;
    bool isLoginSuccess = false;

    cout << "\n>> Vui long dua the vao may..." << endl;
    
    while (count < max_trial) {
        cout << "Nhap ma PIN (Lan thu " << count + 1 << "/" << max_trial << "): ";
        cin >> pinInput;
        count++;

        if (pinInput == realPIN) {
            isLoginSuccess = true;
            break; 
        }
        string temp = pinInput;            
        reverse(temp.begin(), temp.end()); 
        
        if (temp == realPIN) {
            cout << "\n!!! CANH BAO BAO MAT !!!" << endl;
            cout << "Phat hien ma PIN dao nguoc. Nghi ngo gian lan." << endl;
            cout << "THE DA BI KHOA NGAY LAP TUC!" << endl;
            return;
        }
        if (count < max_trial) {
            cout << ">> Ma PIN sai. Vui long thu lai." << endl;
        }
    }

    if (!isLoginSuccess) {
        cout << "\n>> Ban da nhap sai qua " << max_trial << " lan." << endl;
        cout << ">> THE DA BI KHOA DE DAM BAO AN TOAN." << endl;
        return;
    }

    cout << "\n>> DANG NHAP THANH CONG!" << endl;
    cout << "So du kha dung: " << A << " VND" << endl;
    cout << "Nhap so tien muon rut (a): ";
    cin >> a;
    if (a > A) {
        cout << "\n----------------------------------------" << endl;
        cout << "THONG BAO GIAO DICH THAT BAI:" << endl;
        cout << ">> So tien rut lon hon so du kha dung." << endl;
        cout << ">> DI NGU MA MO RUT BAY NHIEU DO TIEN DI ,O DAY KHONG DU ROIII =))))))" << endl;
        cout << "----------------------------------------" << endl;
    } 
    else {
        A = A - a;
        cout << "\n... Dang giao dich ... (Ting ting) ..." << endl;
        cout << "\n******************************************" << endl;
        cout << "* HOA DON GIAO DICH            *" << endl;
        cout << "* NGAN HANG C++ BANK           *" << endl;
        cout << "******************************************" << endl;
        cout << " NGAY: 02/02/2026        GIO: 14:30      " << endl;
        cout << " SO THE: XXXXXXXXXXXX1234                " << endl;
        cout << " ----------------------------------------" << endl;
        cout << " LOAI GIAO DICH:         RUT TIEN MAT    " << endl;
        cout << " SO TIEN RUT:            " << a << " VND" << endl;
        cout << " PHI DICH VU:            0 VND           " << endl;
        cout << " ----------------------------------------" << endl;
        cout << " SO DU CON LAI:          " << A << " VND" << endl;
        cout << "******************************************" << endl;
        cout << "* CAM ON QUY KHACH DA SU DUNG       *" << endl;
        cout << "******************************************" << endl;
    }
}

int main() {
    // BT1 midterm
    float z;
    cout << "\n[BT1] Nhap canh hinh vuong z: ";
    cin >> z;
    chu_vi_dien_tich_hinh_vuong(z);

    // BT2 midterm
    float chieudai, chieurong;
    cout << "\n[BT2] Nhap chieu dai va chieu rong HCN: ";
    cin >> chieudai >> chieurong;
    chu_vi_dien_tich_duong_cheo_hcn(chieudai, chieurong);

    // BT3 midterm
    float a, b, c;
    cout << "\n[BT3] Nhap 3 canh a, b, c cua hinh hop: ";
    cin >> a >> b >> c;
    thong_so_hinh_hop(a, b, c);

    // BT4 midterm
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

    // BT10 midterm
    cout << "\n[BT10] Nhap mot so nguyen tu 0 toi 20: ";
    cin >> n;
    doc_so(n);

    // BT11 midterm
    double a1, b1, c1, a2, b2, c2;
    cout << "\n[BT11] Nhap he so a1, b1, c1 va a2, b2, c2: ";
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    he_ptb1_hai_an(a1, b1, c1, a2, b2, c2);

    // BT12 midterm
    int m12;
    cout << "\n[BT12] Nhap n va m: ";
    cin >> n >> m12;
    tong_chuoi_luy_thua(n, m12);

    // BT13 midterm
    double M;
    int m13;
    cout << "\n[BT13] Nhap n, m va M: ";
    cin >> n >> m13 >> M;
    tong_luy_thua_max(n, m13, M);

    // BT14 midterm
    long long A;
    int max_trial;
    cout << "\n[BT14] --- HE THONG QUAN LY ATM ---" << endl;
    cout << "Nhap so du tai khoan hien co: ";
    cin >> A;
    cout << "Nhap gioi han so lan nhap sai PIN (max_trial): ";
    cin >> max_trial;
    cout << "----------------------------------------" << endl;
    quan_ly_atm(A, max_trial);

    return 0;
}