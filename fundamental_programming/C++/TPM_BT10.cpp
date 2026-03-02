#include <iostream>
using namespace std;

string E_switch(int a){
    string b[21] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty"};
    return b[a];
}

int main(){
    int n;
    cout << "Nhập n";
    cin >> n;
    cout << E_switch(n);
    return 0;
}