#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, m;
    long long sum = 0;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    if (m < 0 || n < 1){
        cout << "khong hop le" << '\n';
        return 0;
    }
    for (int i = 1; i <=n; ++i){
        sum += (long long)pow(i,m);
    }
    cout << "ket qua = " << sum << '\n';
    return 0;
}