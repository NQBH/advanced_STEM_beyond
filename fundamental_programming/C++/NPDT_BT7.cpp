#include <iostream>
#include <vector>
using namespace std;

int main() {
    double a, b, c;
    //nhap abc
    cout << "nhap 3 so: " << endl;
    cin >> a >> b >> c;

    //max min
    double xmin;
    double xmax;
    
    if (a > b) {
        xmin = b;
        xmax = a;
    } else {
        xmin = a;
        xmax = b;
    }

    if (xmin > c) {
        xmin = c;
    }

    if (xmax < c) {
        xmax = c;
    }

    cout << "min: " << xmin << endl;
    cout << "max: " << xmax << endl << endl;

//-----min va max cua n so thuc-----
    int n;
    vector<double> arr(n);
    
    cout << "nhap n so thuc: ";
    cin >> n;

    //nhap n so thuc
    for (int i = 0; i < n; i++) {
        cout << "nhap so: ";
        cin >> arr[i];
    }

    //min max
    double vmax = arr[0],  vmin = arr[0];

    for (int i = 0; i < n; i++) {
        if (vmax < arr[i] ) {
            vmax = arr[i];
        }

        if (vmin > arr[i]) {
            vmin = arr[i];
        }
    }

    cout << "min: " << vmin << endl;
    cout << "max: " << vmax << endl; 
}