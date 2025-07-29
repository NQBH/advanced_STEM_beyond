#include "utils.h"

std::vector<int> get_transpose(const std::vector<int>& p) {
    if (p.empty()) return {};
    std::vector<int> transpose;
    if (!p.empty()) {
        int max_part = p[0];
        for (int i = 1; i <= max_part; ++i) {
            int count = 0;
            for (int part : p) {
                if (part >= i) {
                    count++;
                }
            }
            transpose.push_back(count);
        }
    }
    return transpose;
}

void print_diagram(const std::vector<int>& p, const std::string& title) {
    std::cout << "  " << title << ":" << std::endl;
    if (p.empty()) return;
    for (int part : p) {
        std::cout << "    " << std::string(part, '*') << std::endl;
    }
}