#include <iostream>
#include <vector>
#include <algorithm>

void print_ferrers(const std::vector<int>& partition) {
    std::cout << "Ferrers diagram:\n";
    for (int row : partition) {
        for (int i = 0; i < row; ++i) std::cout << "*";
        std::cout << "\n";
    }
}

void print_ferrers_transpose(const std::vector<int>& partition) {
    std::cout << "Transpose Ferrers diagram:\n";
    int max_row = *std::max_element(partition.begin(), partition.end());
    for (int i = 0; i < max_row; ++i) {
        for (int part : partition) {
            std::cout << (i < part ? "*" : " ");
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<int> partition = {4, 3, 1};
    print_ferrers(partition);
    std::cout << "\n";
    print_ferrers_transpose(partition);
    return 0;
}