 #include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, M;
    double S = 0;
    cin >> n >> m >> M;
    for ( int i=1; i<= n; i++){
      double sum  = pow(i,m);
     if(S + sum > M)break;
     S += sum;  
}
    cout << "Tong Sm =" << S;
}
