#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "nhap n : ";
    cin >> n;
    double v[n];
    for ( int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int am, duong, ko;
    am = 0;
    duong = 0;
    ko = 0;
    for (int i = 0; i < n; ++i ) {
        if (v[i] == 0) ko++;
        if (v[i] > 0) duong++;
        if (v[i] < 0) am++;
    }
    cout << " vay am la: " << am << endl;
    cout << " vay duong la: " << duong << endl;
    cout << " vay ko la: " << ko << endl;
}
