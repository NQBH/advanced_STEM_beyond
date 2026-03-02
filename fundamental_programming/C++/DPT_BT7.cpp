#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a, b, c, vmax, vmin;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    if (a > b && b > c){
        double max = a;
        cout << "Max trong 3 so thuc cho truoc = " << max << '\n';
    }else if (b > a && a > c){
        double max = b;
        cout << "Max trong 3 so thuc cho truoc = " << max << '\n';
    }else{
        double max = c;
        cout << "Max trong 3 so thuc cho truoc = " << max << '\n';
    }
    if (a < b && b < c){
        double min = a;
        cout << "Min trong 3 so thuc cho truoc = " << min << '\n';
    }else if (b < a && a < c){
        double min = b;
        cout << "Min trong 3 so thuc cho truoc = " << min << '\n';
    }else{
        double min = c;
        cout << "Min trong 3 so thuc cho truoc = " << min << '\n';
    }
}