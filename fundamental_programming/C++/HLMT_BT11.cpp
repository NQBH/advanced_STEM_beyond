#include <iostream>
using namespace std;

int main()
{
    float a, b, c;
    float A, B, C;

    cout << "Nhap a, b, c: ";
    cin >> a >> b >> c;

    cout << "Nhap A, B, C: ";
    cin >> A >> B >> C;

    float D  = a * B - A * b;
    float Dx = c * B - C * b;
    float Dy = a * C - A * c;

    if (D == 0)
    {
        if (Dx == 0 && Dy == 0)
            cout << "He phuong trinh vo so nghiem";
        else
            cout << "He phuong trinh vo nghiem";
    }
    else
    {
        float x = Dx / D;
        float y = Dy / D;
        cout << "He phuong trinh co nghiem duy nhat:" << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }

    return 0;
}