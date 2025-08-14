#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

const double PI = 3.141592653589793238462643383279502884197169399;

bool isValidTriangle(double a,double b,double c){
    return (a+b>c)&&(a+c>b)&&(b+c>a)&&(a>0)&&(b>0)&&(c>0);
}

void calculateTriangleParameters(double a,double b,double c){
    double chuvi=a+b+c;
    double p=chuvi/2;
    double dientich=sqrt(p*(p-a)*(p-b)*(p-c));

    double ha=(2*dientich)/a;
    double hb=(2*dientich)/b;
    double hc=(2*dientich)/c;

    double ma=0.5*sqrt(2*b*b+2*c*c-a*a);
    double mb=0.5*sqrt(2*a*a+2*c*c-b*b);
    double mc=0.5*sqrt(2*a*a+2*b*b-c*c);

    double angleA=acos((b*b+c*c-a*a)/(2*b*c))*180/PI;
    double angleB=acos((a*a+c*c-b*b)/(2*a*c))*180/PI;
    double angleC= 180 - angleA-angleB;

    cout<<fixed<<setprecision(2);
    cout<<"\nThong tin tam giac:\n";
    cout<<"----------------------\n";
    cout<<"1.Cac canh:\n";
    cout<<"-canh a:"<<a<<endl;
    cout<<"-canh b:"<<b<<endl;
    cout<<"-canh c:"<<c<<endl;

    cout<<"\nCac goc(tinh theo do):\n";
    cout<<"-goc A:"<<angleA<<endl;
    cout<<"-goc B:"<<angleB<<endl;
    cout<<"-goc C:"<<angleC<<endl;

    cout<<"\nCac thong so khac:\n";
    cout<<"-chuvi:"<<chuvi<<endl;
    cout<<"-dientich:"<<dientich<<endl;
    cout<<"-duongcao ha:"<<ha<<endl;
    cout<<"-duong cao hb:"<<hb<<endl;
    cout<<"-duong cao hc:"<<hc<<endl;
    cout<<"-trung tuyen ma:"<<ma<<endl;
    cout<<"-trung tuyen mb:"<<mb<<endl;
    cout<<"-trung tuyen mc:"<<mc<<endl;
}
int main(){
    double b,c,angleA;
    cout<<"nhap b:"; cin>>b;
    cout<<"nhap c:"; cin>>c;
    cout<<"nhap goc A:"; cin>>angleA;

    double angleA_rad=angleA*PI/180;

    double a=sqrt(b*b+c*c-2*b*c*cos(angleA_rad));

    if(!isValidTriangle(a,b,c)){
        cout<<"cac thong so nhap vao khong hop le\n";
        return 1;
    }
    cout<<"\nket qua:\n";
    cout<<"Canh a:"<<fixed<<setprecision(2)<<a<<endl;
    calculateTriangleParameters(a,b,c);
    return 0;
    
}