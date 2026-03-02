#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int n, m, M;
    long long sum = 0;
    cout << "nhập số n: ";
    cin >> n;
    cout << "nhập số m: ";
    cin >> m;
    cout << "nhập số M: ";
    cin >> M;
    int i = 1;
    if (sum > M) {
        cout << "M không hợp lệ";
    }
    else {
        while (i <= n && sum + pow(i, m) <= M) {

            sum += pow(i, m);
            i++;


        }
        cout << "tổng là: " << sum;
    }


}