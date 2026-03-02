#include <iostream>
#include<string>
using namespace std;
int main () {
    int n; string str;
    cout << "Input n = ";
    cin >> n;
    switch (n) {
    case 0: str = "zero"; break;
    case 1: str = "one"; break;
    case 2: str = "two"; break;
    case 3: str = "three"; break;
    case 4: str = "four"; break;
    case 5: str = "five"; break;
    case 6: str = "six"; break;
    case 7: str = "seven"; break;
    case 8: str = "eight"; break;
    case 9: str = "nine"; break;
    case 10: str = "ten"; break;
    case 11: str = "eleven"; break;
    case 12: str = "twelve"; break;
    case 13: str = "thirteen"; break;
    case 14: str = "fourteen"; break;
    case 15: str = "fifteen"; break;
    case 16: str = "sixteen"; break;
    case 17: str = "seventeen"; break;
    case 18: str = "eighteen"; break;
    case 19: str = "nineteen"; break;
    case 20: str = "twenty"; break;
    default:
        if (n < 0) str = "Negative";
        else str = "Great than twenty";

    }
    cout << "Result: " << str;
    return 0;
}