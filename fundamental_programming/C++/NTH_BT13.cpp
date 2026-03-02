#include <iostream>
#include <cmath>
using namespace std;

long long tinhSm(int n, int m) {
    long long sum = 0;
    
    for (int i = 1; i <= n; i++) {
        sum += pow(i, m);
    }
    
    return sum;
}

int timNLonNhat(int m, long long M) {
    int n = 0;
    long long sum = 0;
    
    while (true) {
        n++;
        long long giaTriMoi = pow(n, m);
        
        if (sum + giaTriMoi > M) {
            n--;
            break;
        }
        
        sum += giaTriMoi;
    }
    
    return n;
}

int main() {
    int m;
    long long M;
    
    cout << "Nhap m: ";
    cin >> m;
    
    cout << "Nhap M: ";
    cin >> M;
    
    if (M < 1) {
        cout << "M phai la so nguyen duong!" << endl;
        return 1;
    }
    
    int nMax = timNLonNhat(m, M);
    long long Sm = tinhSm(nMax, m);
    
    cout << "\nn lon nhat: " << nMax << endl;
    cout << "Sm = 1^" << m << " + 2^" << m << " + ... + " << nMax << "^" << m << " = " << Sm << endl;
    cout << "Sm <= M (" << Sm << " <= " << M << ")" << endl;
    
    if (nMax > 0) {
        long long SmTiepTheo = Sm + (long long)pow(nMax + 1, m);
        cout << "\nNeu n = " << (nMax + 1) << " thi Sm = " << SmTiepTheo << " > M" << endl;
    }
    
    return 0;
}