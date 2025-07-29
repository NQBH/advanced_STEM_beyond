#include "problems.h"
#include <iostream>

void print_menu() {
    std::cout << "\n\n==============================================" << std::endl;
    std::cout << "            DO AN MON HOC C++" << std::endl;
    std::cout << "==============================================" << std::endl;
    std::cout << "Do an 4: Phan Hoach So Nguyen" << std::endl;
    std::cout << "  1. Bai toan 1" << std::endl;
    std::cout << "  2. Bai toan 2" << std::endl;
    std::cout << "  3. Bai toan 3" << std::endl;
    std::cout << "Do an 5: Duyet Do Thi & Cay" << std::endl;
    std::cout << "  4. Bai toan 4" << std::endl;
    std::cout << "  5. Bai toan 5" << std::endl;
    std::cout << "  6. Bai toan 6" << std::endl;
    std::cout << "  7. Bai toan 7" << std::endl;
    std::cout << "  8. Bai toan 8" << std::endl;
    std::cout << "  9. Bai toan 9" << std::endl;
    std::cout << "  10. Bai toan 10" << std::endl;
    std::cout << "  11. Bai toan 11" << std::endl;
    std::cout << "  12. Bai toan 12" << std::endl;
    std::cout << "  13. Bai toan 13" << std::endl;
    std::cout << "  14. Bai toan 14" << std::endl;
    std::cout << "  15. Bai toan 15" << std::endl;
    std::cout << "  16. Bai toan 16" << std::endl;
    std::cout << "  0. Thoat" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Vui long chon mot bai toan: ";
}

int main() {
    int choice;
    do {
        print_menu();
        std::cin >> choice;
        switch (choice) {
            case 1: solve_problem_1(); break;
            case 2: solve_problem_2(); break;
            case 3: solve_problem_3(); break;
            case 4: solve_problem_4(); break;
            case 5: solve_problem_5(); break;
            case 6: solve_problem_6(); break;
            case 7: solve_problem_7(); break;
            case 8: solve_problem_8(); break;
            case 9: solve_problem_9(); break;
            case 10: solve_problem_10(); break;
            case 11: solve_problem_11(); break;
            case 12: solve_problem_12(); break;
            case 13: solve_problem_13(); break;
            case 14: solve_problem_14(); break;
            case 15: solve_problem_15(); break;
            case 16: solve_problem_16(); break;
            case 0: std::cout << "Thanks!" << std::endl; break;
            default: std::cout << "Lua chon khong hop le. Vui long chon lai." << std::endl; break;
        }
    } while (choice != 0);

    return 0;
}