#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Nhap so duong thang: ";
    cin >> n;

    int intersections = n * (n -1) / 2;
    cout << "So giao diem tao duoc: " << intersections << endl;
    return 0;
}