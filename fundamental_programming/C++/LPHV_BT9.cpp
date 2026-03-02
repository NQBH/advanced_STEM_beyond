#include<iostream>
using namespace std;
int main () {
    int n;
    cin >> n;
    int x;
    int chan = 0;
    int le = 0;
    cout << " Nhap " << n << " so nguyen ";
    for (int i = 0 ; i < n ; i++ ) {
        cin >> x;
        if (x % 2 == 0) {
            chan++;
        } else {
            le++;
        }
    }
    cout << "SO CHAN: " << chan << endl;
    cout << "SO LE: " << le << endl;
}