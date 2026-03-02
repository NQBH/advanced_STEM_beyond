#include<iostream>
using namespace std;
int main (){
   int n;
   cout << "Nhap so luong phan tu: ";
   cin >> n;

    if (n == 0) {
        double a;
        cout << "Nhap so thuc: ";
        cin >> a;
        cout << "So am: 0" << endl;
        cout << "So duong: 0" << endl;  
        cout << "So  0 : 1" << endl;
        return 0;
    }

    double a;
    int demAm = 0, demDuong = 0, demZero = 0;

    cout << "Nhap " << n << " so thuc: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a < 0) demAm++;
        else if (a > 0) demDuong++;
        else demZero++;
    }

    cout << "So am: " << demAm << endl;
    cout << "So duong: " << demDuong << endl;
    cout << "So  0 : " << demZero << endl;

   

}