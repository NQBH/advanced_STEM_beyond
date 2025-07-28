#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Nhap so diem: ";
    cin >> n;

    int lines = n * (n - 1) / 2;
    cout << "So duong thang tao duoc: " << lines << endl;
    return 0;
}