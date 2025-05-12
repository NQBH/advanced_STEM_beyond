//Cau b
#include <iostream> 
using namespace std;

int main() {
    double epsilon;

    
    cout << "Nhap epsilon: ";
    cin >> epsilon;

    int n = 2;
    double d = 1.0 / (n + 1);
    while (d >= epsilon) {
        n++;
        d = 1.0 / (n + 1);
    }
    cout << "Gia tri n nho nhat de 1/(n+1) < epsilon la: " << n << endl;

    return 0;
}