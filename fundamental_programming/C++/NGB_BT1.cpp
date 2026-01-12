#include <cmath>
#include <iostream>
using namespace std;

int main() {
    float r; //Cạnh
    float C; //Chu vi
    float S; //Dien tích
    cout << "Nhap canh cua hinh vuong: ";
    cin >> r;

    C = r * 4; //Công thức chu vi
    S =  r * r; // Công thức diện tích

    // In kết quả
    cout << "Chu vi hinh vuong la: " << C << endl;
    cout << "Dien tich hinh vuong la: " << S << endl;
    
    return 0;
}