#include <iostream>
using namespace std;

int main()
{
    int n;
    
    cout << "Nhap n: ";
    cin >> n;
    
    int x;

    cout << "Nhap so thuc 1: ";
    cin >> x;
    
    int max = x;
    int min = x;

    for (int i = 2; i <= n; i++)
    {
        cout << "Nhap so thuc " << i << ": ";
        cin >> x;

        if (x > max)
            max = x;
        if (x < min)
            min = x;
    }

    cout << "So lon nhat: " << max << endl;
    cout << "So nho nhat: " << min << endl;

    return 1;
}