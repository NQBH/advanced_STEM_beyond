#include <iostream>
#include <string>
using namespace std;
int main() {
    int n; string str;
    cout << "Input n =";
    cin >> n;
    switch (n)
    {
    case 0 : str = "Zero"; break;
    case 1 : str = "One"; break;
    case 2 : str = "Two"; break;
    case 3 : str = "Three"; break;
    case 4 : str = "Four"; break;
    case 5 : str = "Five"; break;
    case 6 : str = "Six"; break;
    case 7 : str = "Seven"; break;
    case 8 : str = "Eight"; break;
    case 9 : str = "Nine"; break;
    case 10 : str = "Ten"; break;
    case 11 : str = "Eleven"; break;
    case 12 : str = "twelve"; break;
    case 13 : str = "thirteen"; break;
    case 14 : str = "fourteen"; break;
    case 15 : str = "fifteen"; break;
    case 16 : str = "sixteen"; break;
    case 17 : str = "seventeen"; break;
    case 18 : str = "eighteen"; break;
    case 19 : str = "nineteen"; break;
    case 20 : str = "twenty"; break;
    default:
        if (n < 0 ) str = " Negative";
        else str = "Greater than twenty";
    }
    cout << "Result:" << str;
    return 1;
}