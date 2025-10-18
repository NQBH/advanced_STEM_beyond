#include <iostream>

int main() {
    float a, b, c, d;
    float dinhThuc;

    std::cout << "Ctrinh tinh dinh thuc ma tran 2x2\n";
    std::cout << "Mtran co dang:\n";
    std::cout << "[ a  b ]\n";
    std::cout << "[ c  d ]\n\n";

    std::cout << "Nhap a: ";
    std::cin >> a;

    std::cout << "Nhap b: ";
    std::cin >> b;

    std::cout << "Nhap c: ";
    std::cin >> c;

    std::cout << "Nhap d: ";
    std::cin >> d;

    dinhThuc = (a * d) - (b * c);

    std::cout << "\nDinh thuc cua mtran la: " << dinhThuc << std::endl;

    return 0;
}