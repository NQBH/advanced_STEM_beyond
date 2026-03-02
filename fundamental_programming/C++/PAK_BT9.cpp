#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int sochan, sole;
    sochan = 0 ; sole = 0;
    cout << "Nhập " << N << " số : ";
    for (int i = 1; i <= N; i++) {
        int n; cin >> n;
        //n % 2 == 0 ? sochan++ : sole++;
        if (n % 2 == 0) {sochan++;}
        else {sole++;}
    }
    cout << "số lượng số chẵn : " << sochan << '\n';
    cout << "số lượng số lẻ : " << sole << '\n';
}