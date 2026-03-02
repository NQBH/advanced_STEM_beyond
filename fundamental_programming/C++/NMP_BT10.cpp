#include <iostream>
using namespace std;

int readNumber(int n) {
    switch (n) {
        case 0:  cout << "zero"; return 0;
        case 1:  cout << "one"; return 0;
        case 2:  cout << "two"; return 0;
        case 3:  cout << "three"; return 0;
        case 4:  cout << "four"; return 0;
        case 5:  cout << "five"; return 0;
        case 6:  cout << "six"; return 0;
        case 7:  cout << "seven"; return 0;
        case 8:  cout << "eight"; return 0;
        case 9:  cout << "nine"; return 0;
        case 10: cout << "ten"; return 0;
        case 11: cout << "eleven"; return 0;
        case 12: cout << "twelve"; return 0;
        case 13: cout << "thirteen"; return 0;
        case 14: cout << "fourteen"; return 0;
        case 15: cout << "fifteen"; return 0;
        case 16: cout << "sixteen"; return 0;
        case 17: cout << "seventeen"; return 0;
        case 18: cout << "eighteen"; return 0;
        case 19: cout << "nineteen"; return 0;
        case 20: cout << "twenty"; return 0;
        default: cout << "khong hop le ";
            return 0;
    }
}

int main() {
    int n;
    cout << "Nhap n : ";
    cin >> n;

    readNumber(n);

    return 0;
}