#include <iostream>
#include <algorithm>
#include <cmath>
const double pi=3.14159265359;
using namespace std;
int main(){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        float x,y;cin>>x>>y;
        float d=sqrt(x*x+y*y);
        float t=(pi*d*d)/100;
        cout<<"Property"<<" "<<i<<": This property will begin eroding in year "<<ceil(t)<<endl;
    }
    cout<<"END OF OUTPUT"<<endl;
}