#include <iostream>
#include <string>
using namespace std;
string Englist_swich(int e ){
    string eng[21] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty"};
    return eng[e];
}
int main(){
    int n;
    cout << "nhap n: ";
    cin >> n; 
    cout << Englist_swich(n);
}
