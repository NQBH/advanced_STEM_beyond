#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n, m ;
    long long Sm = 0;
    cout << "nhap so n" ;
    cin >> n;
    cout << "nhap so m" ;
    cin >> m;
    for(int i = 1; i <= n; i++){
        Sm += pow(i, m);
    }
    cout << "Sm = " << Sm << endl;
    return 0;
}