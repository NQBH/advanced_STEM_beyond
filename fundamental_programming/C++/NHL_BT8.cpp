#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "nhap so n: ";
    cin >> n;
    int demsoduong = 0;
    int demso0 = 0;
    int demsoam = 0;
    for (int i = 0; i < n; i++)
    {
        double x;
        cout << " nhap so x: ";
        cin >>  x;
        if (x == 0) {demso0 ++;}
        else {
            if (x < 0) {demsoam ++;}
            else {demsoduong ++;}
        }
    }
    cout << "so so duong: " << demsoduong << '\n';
    cout << "so so am: " << demsoam << '\n';
    cout << "so so 0: " << demso0 << '\n';
}