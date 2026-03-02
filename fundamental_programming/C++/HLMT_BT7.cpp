#include <iostream>
using namespace std;

int main()
{ 
    int n;
    float a , b , c; 
    float  x , max , min;
    
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    
    // Tim max 
    if (a >= b && a >= c) {
        max = a;
    } else if (b >= a && b >= c) {
        max = b;
    } else {
        max = c;
    }
    

    // Tim min 
    if (a <= b && a <= c) {
        min = a;
    } else if (b <= a && b <= c) {
        min = b;
    } else {
        min = c;
    }
    cout << "Nhap n: ";
    cin >> n;
    
    //Nhap so dau tien 
    cout << "Nhap so: ";
    cin >> x;
    max = x;
    min = x;
    
    // In ket qua
    cout << "So lon nhat la: " << max << endl;
    cout <<"So nho nhat la: " << min << endl;
    
    return 0;
}