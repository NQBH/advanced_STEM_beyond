#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n,m,M, i = 1;
    double ketqua = 0;
    cout << "nhap m: ";
    cin >> m;  
    cout << "nhap n: ";
    cin >> n;
    cout << "nhap M: ";
    cin >> M;
    while (i <= n){
        if ( ketqua + pow (i,m) <= M)
            ketqua += pow(i,m);
        else break;
        i += 1;
    }   
    cout << "ket qua: " << ketqua << endl;
}