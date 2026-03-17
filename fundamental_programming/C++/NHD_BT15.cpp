#include <bits/stdc++.h>
#include <cmath>
#include <string>
using namespace std;

/*bt1*/
void bt1() {
    double a;
    cout << "Nhap canh hinh vuong: ";
    cin >> a;

    cout << "Chu vi: " << 4 * a << endl;
    cout << "Dien tich: " << a*a << endl;
}

/*bt2*/
void bt2() {
    double dai, rong;
    cout << "Nhap chieu dai va chieu rong: ";
    cin >> dai >> rong;

    cout << "Chu vi: " << 2 * (dai + rong) << endl;
    cout << "Dien tich: " << dai*rong << endl;
    cout << "Duong cheo: " << sqrt(dai * dai + rong * rong) << endl;
}

/*bt3*/
void bt3() {
    int a, b, c;
    cout << "Nhap a b c: ";
    cin >> a >> b >> c;

    if (a == b && b == c && a > 0) {
        cout << "HLP" << endl;
    }
    else if (a > 0 && b > 0 && c > 0) {
        cout << "HHCN" << endl;
        cout << "Dien tich xung quanh: " << 2 * c*(a + b) << endl;
        cout << "Dien tich toan phan: " << 2 * (a * b + b * c + a * c) << endl;
        cout << "Duong cheo: " << sqrt(a * a + b * b + c * c) << endl;
        cout << "The tich: " << a*b*c << endl;
    }
    else {
        cout << -1 << endl;
    }
}

/*bt4*/
void bt4() {
    double x = 9.5;
    double y = -4.3;

    cout << "abs(y): " << abs(y) << endl;
    cout << "sqrt(x): " << sqrt(x) << endl;
    cout << "pow(2,3): " << pow(2, 3) << endl;
    cout << "ceil(x): " << ceil(x) << endl;
    cout << "floor(x): " << floor(x) << endl;
    cout << "round(x): " << round(x) << endl;
    cout << "exp(1): " << exp(1) << endl;
    cout << "log(x): " << log(x) << endl;
    cout << "sin(x): " << sin(x) << endl;
    cout << "cos(x): " << cos(x) << endl;
}

/*bt5*/
void bt5() {
    double a, b;
    cout << "Nhap a b: ";
    cin >> a >> b;

    if (a == 0) {
        if (b == 0) cout << "Vo so nghiem\n";
        else cout << "Vo nghiem\n";
    }
    else {
        cout << "x = " << -b / a << endl;
    }
}

/*bt6*/
void bt6() {
    double a, b, c;
    cout << "Nhap a b c: ";
    cin >> a >> b >> c;

    if (a == 0) {
        cout << "Phuong trinh tro thanh bac nhat\n";
        return;
    }

    double delta = b * b - 4 * a * c;

    if (delta < 0)
        cout << "Vo nghiem\n";
    else if (delta == 0)
        cout << "Nghiem kep x = " << -b / (2 * a) << endl;
    else {
        cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
        cout << "x2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
    }
}

/*bt12*/
void bt12() {
    int n, m;
    cout << "Nhap n m: ";
    cin >> n >> m;

    long long S = 0;
    for (int i = 1; i <= n; i++)
        S += pow(i, m);

    cout << "S = " << S << endl;
}

/*bt13*/
void bt13() {
    int n, m;
    long long M;
    cout << "Nhap n m M: ";
    cin >> n >> m >> M;

    long long S = 0;
    int i;
    for (i = 1; i <= n; i++) {
        long long temp = pow(i, m);
        if (S + temp > M) break;
        S += temp;
    }

    cout << "S lon nhat <= M: " << S << endl;
}

/*bt14*/
void bt14() {
    string pin = "123456";
    string input;
    int max_trial;
    double A, a;

    cout << "Nhap so du: ";
    cin >> A;
    cout << "Nhap so tien muon rut: ";
    cin >> a;
    cout << "Nhap so lan thu toi da: ";
    cin >> max_trial;

    int dem = 0;
    while (dem < max_trial) {
        cout << "Nhap PIN: ";
        cin >> input;

        string dao(input.rbegin(), input.rend());

        if (input == dao && input != pin) {
            cout << "Security! The bi khoa!\n";
            return;
        }

        if (input == pin) {
            if (a > A)
                cout << "So tien rut lon hon so du kha dung!\n";
            else {
                A -= a;
                cout << "Rut tien thanh cong!\n";
                cout << "So du con lai: " << A << endl;
            }
            return;
        }

        dem++;
    }

    cout << "The bi khoa do nhap sai qua so lan!\n";
}

/*main*/
int main() {
    int chon;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. bt1\n";
        cout << "2. bt2\n";
        cout << "3. bt3\n";
        cout << "4. bt4\n";
        cout << "5. bt5\n";
        cout << "6. bt6\n";
        cout << "7. bt12\n";
        cout << "8. bt13\n";
        cout << "9. bt14\n";
        cout << "0. Thoat\n";
        cout << "Chon bai tap: ";
        cin >> chon;

        switch (chon) {
        case 1: bt1(); break;
        case 2: bt2(); break;
        case 3: bt3(); break;
        case 4: bt4(); break;
        case 5: bt5(); break;
        case 6: bt6(); break;
        case 7: bt12(); break;
        case 8: bt13(); break;
        case 9: bt14(); break;
        case 0: cout << "Chao tam biet ban, chuc ban ngay moi tot lanh!\n"; break;
        default: cout << "Lua chon khong hop le, vui long chon lai ban nhe!\n";
        }

    } while (chon != 0);

    return 0;
}