#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int soduong, soam, sokhong;
    soduong = 0; soam = 0; sokhong = 0;
    for (int i = 1; i <= N ; i++ ) {
        int n ; cin >> n;
        if (n > 0) {soduong++;}
        else if (n < 0) {soam++;}
        else {sokhong++;}
    }
    cout << "so luong so 0 : " << sokhong << '\n';
    cout << "so luong so duong : " << soduong << '\n';
    cout << "so luong so am : " << soam << '\n';
}