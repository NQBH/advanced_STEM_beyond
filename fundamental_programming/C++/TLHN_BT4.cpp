// --------------------------------------- BT4 ---------------------------------------

// Nhap lan luot: x= 4, y= 2, a=-5, b=-10, c=-2.5, g=1, t=0.5, 3.7
// => De kiem tra doan code ma khong bi dung chuong trinh.


#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;


int main() {
    double x;
    double y;
    cout << "Nhap so x: "<< endl;
    cin >> x;
    cout << " Nhap so y: "<< endl;
    cin >> y;


    // Tinh sqrt(double x): can bac hai
    cout << "TINH CAN BAC HAI" << endl;

    if (x < 0) {
        cout << "sqrt(x): x phai >=0." << endl;
    } else {
        cout << "sqrt(x) can bac hai = " << sqrt(x) << endl;
    }

    // Tinh ham pow(): tinh luy thua
    cout << "TINH LUY THUA" << endl;

    cout << "pow(x, y) = " << pow(x, y) << endl;

    // Tinh exp(double x) :

    cout << "TINH e^x VOI e LA CO SO LOGARIT" << endl;

    cout << "exp(x) = " << exp(x) << endl;


    // Tinh log: Tinh logarit tu nhien

    cout << "TINH LOGARIT TU NHIEN CUA x" << endl;
    if (x <=0) {
        cout << "log(x): x phai lon hon (>) 0 " << endl;
    }
    else {
        cout << "log(x) = " << log(x) << endl;
    }


    // Tinh log10

    cout << "TINH LOGARIT CO SO 10" <<endl;

    if (x <=0) {
        cout << "log10(x): x phai lon hon 0." << endl;
    }
    else {
        cout << "log10(x) = " << log10(x) << endl;
    }



    // Tinh ham tri tuyet doi
    cout << "TINH TRI TUYET DOI" <<endl;

    int a;
    long b;
    double c;

    cout << "Nhap so a: " << endl;
    if (!(cin >> a)) {
        cout << "Gia tri so a ban vua nhap khong hop le (phai la so nguyen)." << endl;
        return 0;
    }

    cout << "Nhap so b: " << endl;
    if (!(cin >> b)) {
        cout << "Gia tri so b ban vua nhap khong hop le (phai la so nguyen)." << endl;
        return 0;
    }


    cout << "Nhap so c: " << endl;
    if (!(cin >> c)) {
        cout << "Gia tri so c ban vua nhap khong hop le (phai la so thuc)." << endl;
        return 0;
    }


    cout << "abs(a) = " << abs(a) << endl;
    cout << "labs(b) = " << labs(b) << endl;

    cout << "fabs(c) = " << fabs(c) << endl;


    // Tinh cac ham luong giac (don vi: radian)
    double g;

    cout << "TINH CAC HAM LUONG GIAC" << endl;
    cout << "Nhap g (radian): " << endl;
    cin >> g;

    cout << "sin(g) = " << sin(g) << endl;
    cout << "cos(g) = " << cos(g) << endl;
    cout << "tan(g) = " << tan(g) << endl;




    // Tinh cac ham luong giac nguoc
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



    //            Tinh FLOOR va CEIL:

    double f;

    cout << "TINH FLOOR VA CEIL." << endl;
    cout << "Nhap f de tinh floor va ceil: " << endl;
    cin >> f;

    cout << "floor(f) = " << floor(f) << endl;
    cout << "ceil(f) = " << ceil(f) << endl;

    return 0;
}
