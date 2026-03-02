#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int m;
    long long M;
    long long Sm = 0;
    int n = 0;

    cin >> m >> M;
    cout << "Nhap m: " << m << "Nhap M: " << M << endl;

    while (true){
        n++;
        Sm += pow(n, m);
        if(Sm > M) {
            n--;
            break;
        }
    }
    cout << "Gia tri n lon nhat la: " << n << endl;
    return 0;
}
