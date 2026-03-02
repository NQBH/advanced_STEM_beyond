#include <bits/stdc++.h>
using namespace std ;
int main () {
    int n ;
    string str ;
    cout << "nhap n = " ;
    cin >> n ;
    switch (n)
    {
    case 0 : str = "Zero"; break ;
    case 1 : str = "One" ; break ;
    case 2 : str = "two" ; break ;
    case 3 : str = "three" ; break ;
    case 4 : str = "four" ; break ;
    case 5 : str = "five" ; break ;
    case 6 : str = "six" ; break ;
    case 7 : str = "seven" ; break ;
    case 8 : str = "eight" ; break ;
    case 9 : str = "nine" ; break ;
    case 10 : str = "ten" ; break ;
    case 11: str = "eleven" ; break ;
    case 12 : str = "Twelve" ; break ;
    case 13 : str = "Thirteen" ; break ;
    case 14: str = "Fourteen" ; break ;
    case 15: str = " Fifteen" ; break ;
    case 16: str = "Sixteen" ; break ;
    case 17: str = "Seventeen" ; break ;
    case 18: str = "EighteeN" ; break ;
    case 19: str = "Nineteen" ; break ;
    case 20: str = "Twenty" ; break ;

    default:
        if (n < 0) str = "negative";
        else   str = "greater than fifteen";
    }
    cout <<  "Result :" << str ;
    return 1;
}