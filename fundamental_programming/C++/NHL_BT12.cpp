#include <cmath>
#include <iostream>
using namespace std;
int main(){
    int n,m;
    long long sum = 0;
    cout<<"nhập số n: ";
    cin>>n;
    cout<<"nhập số m: ";
    cin>>m;
    for (int i =1;i <=n;i++)
    {
     sum = sum +pow(i,m);
    }
       cout <<"tổng là: "<<sum;
     
}    