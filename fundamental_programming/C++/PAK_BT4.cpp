#include <bits/stdc++.h>
using namespace std;

int main() {
    double x,y; cout << " Nhâp 2 số thực :" ; cin >> x >> y;
    int x1; long x2 ; double x3;
    cout << "Nhập số dạng int x = " ; cin >> x1;
    cout << "Nhập số dạng long x = "; cin >> x2;
    cout << "Nhập số dạng double x= "; cin >> x3;
    if (x < 0) {
        cout << "ERROR do x < 0"; "\n";
    }
    else{
    cout << "căn bậc 2 của x = "; 
    cout << sqrt(x) << '\n';
    }

    cout << "x lũy thừa y = ";
    cout << pow(x,y) << '\n';
    
    cout << "e mũ x = ";
    cout << exp(x) << '\n';

    
    cout << "logarit cơ số e của x = ";
    cout << log(x) << '\n';
    

    cout << "logarit cơ số 10 của x = ";
    cout<< log10(x) << '\n';


    cout << "trị tuyệt đối của số nguyên x = ";
    cout <<  abs(x) << '\n';

    cout << "trị tuyệt đối của số nguyên dài (long) x = ";    
    cout << labs(x) << '\n';

    cout << "trị tuyệt đối của số thực (double) x = ";
    cout << fabs(x) << '\n';
    
    double x4 ; 
    cout << "Nhập góc x = "  << '\n'; cin >> x4 ;
    cout << "giá trị cos(x) = ";
    cout << cos(x4) << '\n';

    cout << "giá trị sin(x) = ";    
    cout << sin(x4) << '\n';

    
    cout << "giá trị tan(x) = ";
    cout << tan(x4) << '\n';

    double x5;
    cout << "Nhập giá trị lượng giác x" << '\n'; cin >> x5;
    cout << "giá trị góc arccos(x) = ";
    cout << acos(x5) << '\n';

    cout << "giá tr5ị góc arcsin(x) = ";
    cout << asin(x5) << '\n';
    
    cout << "giá trị góc arctg(x) = ";
    cout << atan(x5) << '\n';


    cout << "Làm tròn xuống x = ";
    cout << floor(x) << '\n';


    cout << "làm tròn lên x = ";
    cout << ceil(x) << '\n';
}