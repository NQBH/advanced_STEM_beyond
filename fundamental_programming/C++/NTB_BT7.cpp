#include <iostream>
using namespace std;

int main(){
    double a,b,c;
    cout << "nhap so thuc a: ";
    cin >> a;
    cout << "nhap so thuc b: ";
    cin >> b;
    cout << "nhap so thuc c: ";
    cin >> c;
    double max,min;
    if ( a >= b  && a >= c ) {
        max = a;
    } else if ( b >= a && b >= c ) {
        max = b;
    } else if ( c >= a && c >= b) {
        max = c;
    }
    if ( a <= b && a <= c ) {
        min = a;
    } else if ( b <= a && b <= c) {
        min = b;
    } else if ( c <= a && c <= b) {
        min = c;
    }
    cout << " vay max la: " << max << endl;
    cout << " vay min la: " << min << endl;
// bonus
    int n;
    cout << "nhap n: ";
    cin >> n;
    double v[n];
    double maxn, minn;
    if ( n > 0 ) {
        maxn = n ;
    } else if ( n < 0 ) {
        minn = n ;
    }
    for( int i = 0 ; i < n ; ++i ) {
        cin >> v[i];
    }
    maxn = v[0];
    minn = v[0];
    for( int i = 0 ; i < n ; ++ i) {
        if (v[i]>maxn) maxn=v[i];
        if (v[i]<minn) minn=v[i];
    }
    cout << " vay max cua n la: " << maxn << endl;
    cout << " vay min cua n la: " << minn << endl;

}

