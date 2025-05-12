#include <bits/stdc++.h>
using namespace std;

int main(){
    double e;
    cin >> e;
    int n = 1;
    double d = (double)(n + 1) / pow(3,n);
    while (d >= e) {
        n++;
        d = (double)(n + 1) / pow(3,n);
    }
    cout << "Em tinh ra: " << n << endl; cout << "Ket qua : ";
}