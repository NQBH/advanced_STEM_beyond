#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n;
    int chan = 0, le = 0;
    cout << "Nhap n so nguyen" << endl;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cout << "nhap so: " << endl;
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if ( arr[i] % 2 == 0 ) {
            chan += 1;
        } else le += 1;
    }

    cout << "so luong so chan: " << chan << endl;
    cout << "so luong so le: " << le << endl;

}