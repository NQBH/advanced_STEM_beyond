#include <iostream>

int main() {
    int n;
    std::cout << "kich thuoc : ";
    std::cin >> n;

    std::cout << "\nMa tran 0 kthuoc:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << 0 << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nMa tran don vi kthuoc:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                std::cout << 1 << " ";
            } else {
                std::cout << 0 << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}