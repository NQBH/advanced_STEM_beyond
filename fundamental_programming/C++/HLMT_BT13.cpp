#include <iostream>
using namespace std;

// Ham tinh luy thua a^b
long long power (int a , int b ) {
    long long result = 1;
    for (int i = 1; i <= b; i++ ) {
        result  = result * a;
    }
    return result;

}
int main() {
    int m;
    long long M;
    long long Sm = 0;
    int n = 0;

    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap M: ";
    cin >> m;

    while (true) {
        long long next = Sm + power(n + 1, m);
        if (next > M)
            break;
        n++;
        Sm = next;
    }
    cout << "Gia tri lon nhat = " << n << endl;
    cout << "Tong Sm = " << Sm << endl;


    return 0;
}