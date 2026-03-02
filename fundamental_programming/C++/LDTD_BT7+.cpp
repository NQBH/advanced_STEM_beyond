#include <iostream>
using namespace std;

int main() {
    int n, so;
    int maxVal, minVal;

    cout << "Nhap so luong phan tu n: ";
    cin >> n;

    
    if (n <= 0) {
        cout << "So luong khong hop le!" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "Nhap so thu " << i + 1 << ": ";
        cin >> so;

        if (i == 0) {
            maxVal = so;
            minVal = so;
        } else {
            
            if (so > maxVal) {
                maxVal = so; 
            }
            if (so < minVal) {
                minVal = so; 
            }
        }
    }

    cout << "-----------------------------" << endl;
    cout << "Gia tri lon nhat (Max) la: " << maxVal << endl;
    cout << "Gia tri nho nhat (Min) la: " << minVal << endl;

    return 0;
}