/*
Source: ACM Mid-Central United States 1998.
IDs for online judges: POJ 1316, ZOJ 1180, UVA 640.
Status: Accepted
*/
#include <iostream>
#include <vector>
using namespace std;

const int limit = 10000;

int d(int n) {
    int digit = 0;
    int number = n;
    while(number != 0) {
        digit += number % 10;
        number /= 10;
    }
    return n + digit;
}

int main(){
    vector<bool>selfNumber(limit + 1, true);
    for (int i = 1; i <= limit; i++) {
        int num = i;
        if (selfNumber[num] == true) {
            while(d(num) <= limit) {
                selfNumber[d(num)] = false;
                num = d(num);
            }
        }
    }
    for (int i = 1; i <= limit; i++) {
        if (selfNumber[i] == true) {
            cout << i << endl;
        }
    } 
}