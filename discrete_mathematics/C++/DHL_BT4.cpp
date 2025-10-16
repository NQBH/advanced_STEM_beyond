#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n;
    std::cout << "Nhap so n: ";
    std::cin >> n;

    if (pow(2, n) >= 100) 
        std::cout << "2^n >= 100 la Ð." << std::endl;
    else 
        std::cout << "2^n >= 100 la S." << std::endl;
    

    return 0;
}