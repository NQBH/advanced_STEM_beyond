#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long n,m;
    long long T = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        T +=(long long)pow(i, m); 
    }
    cout << T;
return 0;
}