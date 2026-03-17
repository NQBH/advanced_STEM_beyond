#include <cmath>
#include <iostream>
using namespace std;
double Df(double a, double x, double n){
    cout<<"f("<<x<<"): "<<a*pow(x,n)<<'\n';
    return a*pow(x,n);}
    double D2f(double a, double x, double n){
     cout<<"f'("<<x<<"): "<<n*a*pow(x,(n-1))<<'\n';
     cout<<"f''("<<x<<"): "<<n*(n-1)*a*pow(x,(n-2));
     return 0;
    }


int main()
{
    double a,x,n;
    cout<<"nhập a,x,n: ";
    cin>>a>>x>>n;
    Df(a,x,n);
    D2f(a,x,n);
}
