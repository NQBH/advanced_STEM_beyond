#include <iostream>
using namespace std;

void readNumber(int n) {
    switch (n) {
        case 0:  cout << "zero"; break;
        case 1:  cout << "one"; break;
        case 2:  cout << "two"; break;
        case 3:  cout << "three"; break;
        case 4:  cout << "four"; break;
        case 5:  cout << "five"; break;
        case 6:  cout << "six"; break;
        case 7:  cout << "seven"; break;
        case 8:  cout << "eight"; break;
        case 9:  cout << "nine"; break;
        case 10: cout << "ten"; break;
        case 11: cout << "eleven"; break;
        case 12: cout << "twelve"; break;
        case 13: cout << "thirteen"; break;
        case 14: cout << "fourteen"; break;
        case 15: cout << "fifteen"; break;
        case 16: cout << "sixteen"; break;
        case 17: cout << "seventeen"; break;
        case 18: cout << "eighteen"; break;
        case 19: cout << "nineteen"; break;
        case 20: cout << "twenty"; break;
        default:
            cout << "Number out of range (0-20)";
    }
}

int main() {
    int n;
    cout << "Nhap n (0-20): ";
    cin >> n;

    readNumber(n);

    return 0;
}