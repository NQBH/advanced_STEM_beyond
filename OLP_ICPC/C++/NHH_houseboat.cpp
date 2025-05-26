#include <iostream> 
#include <cmath>
using namespace std;

int main() {
    int t; 
    cin >> t; 

    for (int i = 1; i <= t; i++) {
        double x, y; 
        cin >> x >> y;
        double d = x*x + y*y;
        int z = ((d * M_PI) / 100) + 1;  // cộng 1 nếu đề yêu cầu
        cout << "Property " << i << ": This property will begin eroding in year " << z << ".\n";
    }
    cout << "END OF OUTPUT\n";
    return 0;
}