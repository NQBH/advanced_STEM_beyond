// ex1-b
#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    
    cout << "Nhap x:";
    cin >> x;
    cout << "Nhap y:";
    cin >> y;
    cout << "Nhap z:";
    cin >> z;
    
    if (x + y == z){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    
    return 0;
}