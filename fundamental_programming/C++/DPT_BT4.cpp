#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    {
        double x;
        cin >> x;
        if (x < 0)
            cout << "x phai khong am";
        else
            cout << "can bac hai cua so thuc = " << sqrt(x) << '\n';
        double y;
        cin >> y;
        if (x <= 0)
            cout << "x phai lon hon hoac bang 0";
        else
            cout << "x luy  thua y = " << pow(x, y) << '\n';
        cout << "e mu x = " << exp(x) << '\n';
        cout << "logarit tu nhien  cua x = " << log(x) << '\n';
        cout << "logarit co so 10 cua x = " << log10(x) << '\n';
    }
    {
        {
            int x;
            cin >> x;
            cout << "gia tri tuyet doi |x| voi x nguyen = " << abs(x) << '\n';
        }
        {
            long x;
            cin >> x;
            cout << "gia tri tuyet doi cua |x| voi x nguyen dai = " << labs(x) << '\n';
        }
        {
            double x;
            cin >> x;
            cout << "gia tri tuyet doi cua |x| voi x so thuc = " << fabs(x) << '\n';
        }
    }
    {
        double x;
        cin >> x;
        cout << "cos (x) cua goc x cho bang don vi radian = " << cos(x) << '\n';
        cout << "sin (x) cua goc x cho bang don vi radian = " << sin(x) << '\n';
        cout << "tan (x) cua goc x cho bang don vi radian = " << tan(x) << '\n';
    }
    {
        double x;
        cin >> x;
        cout << "arccos (x) khi da biet truoc gia tri luong giac x = " << acos(x) << '\n';
        cout << "arcsin (x) khi da biet truoc gia tri lhuong giac x = " << asin(x) << '\n';
        cout << "arctan (x) khi da biet truoc gia tri luong giac x = " << atan(x) << '\n';
    }
    {
        double x;
        cin >> x;
        cout << "so nguyen lon nhat khong vuot qua x = " << floor(x) << '\n';
        cout << "so nguyen nho nhat khong vuot qua x = " << ceil(x) << '\n';
    }

}