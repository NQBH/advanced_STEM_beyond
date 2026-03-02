#include <iostream>
using namespace std;

// Ham tinh luy thua a^b
long long power(int a , int b ) {
    long long result = 1;
    for (int i = 1; i <= b; i++) {
        result = result * a;
    }
    return result;
}
int main()
{
    int n,m;
    long long Sm = 0;
    
    cout <<"Nhap n: ";
    cin >> n;
    cout <<"Nhap m: ";
    cin >> m;
    
    for (int i = 1; i<= n; i++)  {
        Sm = Sm + power (i , m);
    }
    cout << "Tong Sm  = " << Sm << endl;
    
    return 0;
}