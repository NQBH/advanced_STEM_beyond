#include <iostream>
using namespace std;
int main()
{
    float a = 2;
    float b = 3;

    if (a == 0 && b == 0) {
        cout << "Phuong trinh co vo so nghiem";
    }
    else if (a == 0 && b != 0) {
        cout << "Phuong trinh vo nghiem";
    }
    else if (a != 0 && b == 0) {
        cout << "Phuong trinh co nghiem x = 0";
    }
    else {
        float x = -b / a;
        cout << "Phuong trinh co nghiem x = " << x;
    }

    return 0;
}