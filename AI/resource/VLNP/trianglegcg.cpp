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
    double angleB,angleC,a;
    cout<<"nhap a:";cin>>a;
    cout<<"nhap goc B(do):";cin>>angleB;
    cout<<"nhap goc C(do):";cin>>angleC;

    double angleA=180-angleB-angleC;

    if(angleA<=0){
        cout<<"tong 3 goc vuot qua 180 do.Tam giac khong hop le.\n";
        return 1;

    }
    double angleA_rad=angleA*PI/180;
    double angleB_rad=angleB*PI/180;
    double angleC_rad=angleC*PI/180;

    double b=a*sin(angleB_rad)/sin(angleA_rad);
    double c=a*sin(angleC_rad)/sin(angleA_rad);

    if(!isValidTriangle(a,b,c)){
        cout<<"cac thong so nhap vao khong hop le.\n";
        return 1;
    }

    cout<<"\nket qua:\n";
    cout<<"goc A:"<<fixed<<setprecision(2)<<angleA<<endl;
    cout<<"canh b:"<<b<<endl;
    cout<<"canh c:"<<c<<endl;

    calculateTriangleParameters(a,b,c);
    return 0;
}