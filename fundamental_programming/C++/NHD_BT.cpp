Bai Tap 1:
#include <iostream>
using namespace std;
int main() {
    cout << "Chao moi nguoi" << endl;
    float d;
    cout << "Nhap canh hinh vuong" ;
    cin >> d;
    float C = 4 * d;
    cout << "Chu vi hinh vuong la: " <<  C << endl;
    float S = d * d;
    cout << "Dien tich hinh vuong la: " << S << endl;
    return 0;
}
Bai tap 2: 
#include <iostream>
using namespace std;
int main() {
    float d, r;
    cout << "Nhap chieu dai cua hinh chu nhat d = ";
    cin >> d;
    cout << "Nhap chieu rong cua hinh chu nhat r = "
    cin >> r;
    float Chuvi = (d + r) * 2;
    float Dientich= d * r;
    float Dodaiduongcheo = sqrt(d * d + r * r);
    cout << "Chu vi hinh chu nhat bang = " << Chuvi << endl;
    cout << "Dien tich hinh chu nhat bang = " << Dientich << endl;
    cout << "Do dai duong cheo hinh chu nhat bang = " << Dodaiduongcheo << endl;
    return 0;
}
Bai tap 3: 
#include <iostream>
using namespace std;
int main() {
    int a,b,c;
    cin >> a >> b >> c;
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1;
        return 0;
    }
    if (a == b && b == c) {
        cout << "Hinh Lap Phuong";
        return 0;
    }
    cout << " Hinh Hop Chu Nhat"; << endl;
    double Dien tich xung quanh(sxq) = 2 * (a + b ) * c;
    double Dien tich toan phan(stp) = 2 * ( a * b + b * c + a * c);
    double Duong cheo(d) = sqrt(a * a + b* b + c * c);
    double The tich(V) = a * b * c;
    cout << "Dien tich xung quanh " << sxq << endl;
    cout << "Dien tich toan phan " << stp << endl;
    cout << "Duong cheo " << d << endl;
    cout << "The tich " << V << endl;
    return 0;
}