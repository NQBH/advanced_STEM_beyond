#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string str;

    cout << "n = ";
    cin >> n;

    switch (n)
    {
        case 0: str = "Zero"; break;
        case 1: str = "One"; break;
        case 2: str = "Two"; break;
        case 3: str = "Three"; break;
        case 4: str = "Four"; break;
        case 5: str = "Five"; break;
        case 6: str = "Six"; break;
        case 7: str = "Seven"; break;
        case 8: str = "Eight"; break;
        case 9: str = "Nine"; break;
        case 10: str = "Ten"; break;
        case 11: str = "Eleven"; break;
        case 12: str = "Twelve"; break;
        case 13: str = "Thirteen"; break;
        case 14: str = "Fourteen"; break;
        case 15: str = "Fifteen"; break;
        case 16: str = "Sixteen"; break;
        case 17: str = "Seventeen"; break;
        case 18: str = "Eighteen"; break;
        case 19: str = "Nineteen"; break;
        case 20: str = "Twenty"; break;
        default:
            str = "So khong hop le";
    }

    cout << str;

    return 0;
}
