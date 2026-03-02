#include <iostream>
using namespace std;

int main () {

    int n;
    cout <<"Nhap so tu 0-20" << endl;
    cin >> n;

    while ( n < 0 || n > 20 ) {
        cout << "Lua chon khong hop le, vui long nhap lai so tu 0-20" << endl;
        cin >> n;
    }

    switch (n) {

    case 0:
        cout << "zero" << endl;
        break;

    case 1:
        cout << "one" << endl;
        break;

    case 2:
        cout << "two" << endl;
        break;

    case 3:
        cout << "three" << endl;
        break;

    case 4:
        cout << "four" << endl;
        break;

    case 5:
        cout << "five" << endl;
        break;

    case 6:
        cout << "six" << endl;
        break;

    case 7:
        cout << "seven" << endl;
        break;

    case 8:
        cout << "eight" << endl;
        break;

    case 9:
        cout << "nine" << endl;
        break;

    case 10:
        cout << "ten" << endl;
        break;

    case 11:
        cout << "elevent" << endl;
        break;

    case 12:
        cout << "twelve" << endl;
        break;

    case 13:
        cout << "thirteen" << endl;
        break;

    case 14:
        cout << "fourteen" << endl;
        break;

    case 15:
        cout << "fifteen" << endl;
        break;

    case 16:
        cout << "sixteen" << endl;
        break;

    case 17:
        cout << "seventeen" << endl;
        break;

    case 18:
        cout << "eighteen" << endl;
        break;

    case 19:
        cout << "nineteen" << endl;
        break;

    case 20:
        cout << "twenty" << endl;
        break;
        

    }
}