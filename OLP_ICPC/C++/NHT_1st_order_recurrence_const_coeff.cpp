#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using cd = complex<ld>;

// Hàm giải phương trình đặc trưng
pair<cd, cd> roots(cd a, cd b, bool &repeated) {
    cd D = a * a + cd(4, 0) * b;
    cd delta = sqrt(D);
    cd r1 = (a + delta) / cd(2, 0);
    cd r2 = (a - delta) / cd(2, 0);
    repeated = abs(r1 - r2) < 1e-9;
    return {r1, r2};
}

// Tìm A, B sao cho u0 = A + B, u1 = A*r1 + B*r2
pair<cd, cd> constants(cd r1, cd r2, cd u0, cd u1, bool repeated) {
    cd A, B;
    if (repeated) {
        A = u0;
        B = (u1 - u0 * r1) / r1;
    } else {
        B = (u1 - u0 * r1) / (r2 - r1);
        A = u0 - B;
    }
    return {A, B};
}

// Tính un
cd term(int n, cd r1, cd r2, cd A, cd B, bool repeated) {
    if (repeated) return (A + B * cd(n, 0)) * pow(r1, n);
    return A * pow(r1, n) + B * pow(r2, n);
}

// Làm tròn số gần 0 về 0 để tránh -0.000000
cd Round(cd z) {
    ld re = abs(z.real()) < 1e-9 ? 0 : z.real();
    ld im = abs(z.imag()) < 1e-9 ? 0 : z.imag();
    return cd(re, im);
}

int main() {
    cd a, b, u0, u1;
    cout << "Nhap a: ";
    ld ar, ai; cin >> ar >> ai; a = cd(ar, ai);

    cout << "Nhap b: ";
    ld br, bi; cin >> br >> bi; b = cd(br, bi);

    cout << "Nhap u0: ";
    ld u0r, u0i; cin >> u0r >> u0i; u0 = cd(u0r, u0i);

    cout << "Nhap u1: ";
    ld u1r, u1i; cin >> u1r >> u1i; u1 = cd(u1r, u1i);

    bool repeated;
    auto [r1, r2] = roots(a, b, repeated);
    auto [A, B] = constants(r1, r2, u0, u1, repeated);

    cout << fixed << setprecision(3);
    //cout << "\nNghiem dac trung: r1 = " << r1 << ", r2 = " << r2 << endl;
    //cout << "He so: A = " << A << ", B = " << B << endl;

    int N;
    cout << "\nNhap so luong phan tu muon in: ";
    cin >> N;
    for (int n = 0; n <= N; ++n) {
        cd un = term(n, r1, r2, A, B, repeated);
        un = Round(un);
        cout << "u[" << n << "] = " << un.real() << " + " << un.imag() << "i" << endl;
    }

    return 0;
}