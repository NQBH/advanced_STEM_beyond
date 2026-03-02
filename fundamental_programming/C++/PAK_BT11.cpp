#include <bits/stdc++.h>
using namespace std;

int main() {
    double a,b,c,A,B,C,x,y;
    cout << "Nhập vào 6 số :" ;
    cin >> a >> b >> c >> A >> B >> C;
    cout << "Hệ Phương trình ta thu được gồm 2 phương trình\n";


    if (b < 0) {
        cout << a << "x " << b << "y = " << c <<'\n';
    } 
    else {cout << a << "x + " << b << "y = " << c << '\n';}
    if (B < 0) {
        cout << A << "x " << B << "y = " << C <<'\n';
    } 
    else {cout << A << "x + " << B << "y = " << C << '\n';}

    
    if (A != 0 && B!= 0 && C != 0){
        if (a/A == b/B && a/A == c/C) {cout << "Phương trình có vô số nghiệm";return 1;}
        if (a/A == b/B && a/A != c/C) {cout << "Phương trình vô nghiệm";return 1;}
    }
    else if (a != 0 && b != 0 && c != 0) {
        if (A/a == B/b && A/a == C/c) {cout <<"Phương trình có vô số nghiệm";return 1;}
        if (A/a == B/b && A/a != C/c) {cout <<"Phương trình vô nghiệm"; return 1;}
    }
    y = (a*C - A*c)/(a*B - A*b);
    x = (c - b*y)/a;
    cout << "Nghiệm của phương trình trên : x = " << x << " và y = " << y; 
    return 1;
}