#include <iostream>
using namespace std;
#include <cmath>

int main() {
    long long soDu, maPinDung, soLanChoPhep, maPinNhap, tienRut;
    cout << "Nhap: So du, Ma PIN, So lan thu: ";
    cin >> soDu >> maPinDung >> soLanChoPhep;
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
            return 0;
        }

        if (maPinNhap == maPinDung) {
            break;
        } else {
            dem++;
            if (dem == soLanChoPhep) {
                cout << "KHOA THE";
                return 0;
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
    return 0;
}