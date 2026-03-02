#include <iostream>
using namespace std;

 int main() {
     int n;
     int x;
     int chan = 0, le = 0;
cout << "Nhap n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Nhap so thu " << i + 1 << ": ";
        cin >> x;

        if (x % 2 == 0)
            chan++;
        else
            le++;
    }
cout << "So luong so chan: " << chan << endl;
cout << "So luong so le: " << le << endl;

   return 0;
}