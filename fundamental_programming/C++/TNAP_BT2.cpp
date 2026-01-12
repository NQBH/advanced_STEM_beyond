#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    // tính chu vi hinh chu nhat
    int P = (a + b) / 2;
    // tính dien tính hinh chu nhat
    int S = a * b;
    cout << " Chu vi hinh nhat la " << P << '\n';
    cout << " Dien tinh hinh nhat la " << S << '\n';
    // tính duong chéo hình chu nhat
    double dc = sqrt( a * a + b * b );
    cout << "Do dai duong cheo hinh chu nhat là " << dc << '\n';
    return 0;
}

