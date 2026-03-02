#include<iostream>
#include<cmath>
using namespace std;
int main (){

    double x,y;
    cin >> x;
    cin >> y;
    if (x < 0)cout <<" x must be non-negative";
    else cout << sqrt (x) << endl;
    cout <<"pow="<< pow (x,y)<<endl;
    cout <<"log=" << log (x)<<endl;
    cout <<"log10=" << log10 (x)<<endl;
    cout <<"abs=" << abs (x)<<endl;
    cout <<"labs=" << labs (x)<<endl;
    cout <<"fabs=" << fabs (x)<<endl;
    cout <<"cos=" << cos (x)<<endl;
    cout <<"sin=" << sin (x)<<endl;
    cout <<"tan=" << tan (x)<<endl;
    cout <<"acos=" << acos (x)<<endl;
    cout <<"asin=" << asin (x)<<endl;
    cout <<"atan=" << atan (x)<<endl;
    cout <<"floor=" << floor (x)<<endl;
    cout <<"ceil=" << ceil (x)<<endl;
    return 0;
}   