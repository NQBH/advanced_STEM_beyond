#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long n, m, M;
    cin >> n >> m >> M;
    long long T = 0;
    long long i = 1;
    while(i <= n){
        long long u = pow(i, m);
        if(T + u <= M){
            T = T + u;
            i++;
        } else {
            break;
        }
    }
    cout << T;
return 0;
}