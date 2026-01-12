#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, h;
    cout << "Nhập độ dài của 3 cạnh : ";
    cin >> a >> b >> h;
    if ( a <= 0 || b <= 0 || h <= 0) {
        cout << "-1";
        return 0;
    }
    if ( a == b && a == h )  {
        cout << " HLP " ;
        return 0;
    }
    else if (a > 0 && b > 0 && h > 0) {   // với mọi 3 cạnh có độ dài lớn hơn 0 đều có thể là cạnh của một HHCN
        cout << " HHCN" << '\n';
        float dtxq, dttp, duongcheo, thetich, duongcheoday;
        dtxq = a * h * 2 + b * h * 2;
        dttp = dtxq + a * b * 2;
        duongcheoday = sqrt(pow(a, 2) + pow(b, 2));
        duongcheo = sqrt(pow(duongcheoday, 2) + pow(h, 2));
        thetich = a * b * h;
        cout << "Diện tích xung quanh của HHCN : " << dtxq << '\n';
        cout << "Diện tích toàn phần của HHCN : " << dttp << '\n';
        cout << "Đường chéo của HHCN : " << duongcheo << '\n';
        cout << "Thể tích của HHCN : " << thetich << '\n';
    }
    else {cout << "-1" ;}
}