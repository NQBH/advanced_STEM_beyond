#include <bits/stdc++.h>

using namespace std;

int main(){
    double e;
    cin >> e;
    int n = 1; 
    double d = sqrt(n + 2) ;
    while (d <= e) {
        n++;
        d = sqrt(n + 2);
    }
    cout << n;
}