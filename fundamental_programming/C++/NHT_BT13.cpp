/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int m;
    long long M;
    long long S = 0;
    int n = 0;

    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap M: ";
    cin >> M;

    while (true) {
        long long t = pow(n + 1, m);
        if (S + t <= M) {
            S += t;
            n++;
        } else {
            break;
        }
    }

    cout << "n lon nhat = " << n << endl;
    cout << "Sm = " << S;
    return 0;
}