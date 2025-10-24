#include <iostream>
using namespace std;

int main() {
    // Bài 11
    cout << "Bai 11:\n";
    cout << "x = 0: " << (0 == 0 * 0) << endl;
    cout << "x = -1: " << (-1 == -1 * -1) << endl;
    cout << "x = 2: " << (2 == 2 * 2) << endl;

    int coDung11 = 0;
    for (int x = -100; x <= 100; x++) {
        if (x == x * x) {
            coDung11 = 1;
        }
    }
    cout << "Co x dung x = x^2: " << coDung11 << endl;

    int tatCaDung11 = 1;
    for (int x = -100; x <= 100; x++) {
        if (x != x * x) {
            tatCaDung11 = 0;
        }
    }
    cout << "Tat ca x dung x = x^2: " << tatCaDung11 << endl;

    // Bài 12
    cout << "\nBai 12:\n";
    cout << "x = 0: " << (0 + 1 >= 2 * 0) << endl;
    cout << "x = 1: " << (1 + 1 >= 2 * 1) << endl;
    cout << "x = 2: " << (2 + 1 >= 2 * 2) << endl;

    int coDung12 = 0;
    for (int x = -100; x <= 100; x++) {
        if (x + 1 >= 2 * x) {
            coDung12 = 1;
        }
    }
    cout << "Co x dung x + 1 >= 2x: " << coDung12 << endl;

    int tatCaDung12 = 1;
    for (int x = -100; x <= 100; x++) {
        if (x + 1 < 2 * x) {
            tatCaDung12 = 0;
        }
    }
    cout << "Tat ca x dung x + 1 >= 2x: " << tatCaDung12 << endl;

    // Bài 13
    cout << "\nBai 13:\n";
    cout << "n + 1 > n: " << 1 << endl;
    cout << "2n = 3n co nghiem n = 0: " << 1 << endl;
    cout << "n^2 < 0 khong co: " << 0 << endl;
    cout << "n^2 >= 0 luon dung: " << 1 << endl;

    // Bài 14
    cout << "\nBai 14:\n";
    cout << "x^2 = 2 co nghiem: " << 1 << endl;
    cout << "x^4 < x^2 co nghiem: " << 1 << endl;
    cout << "(-x)^2 = x^2 luon dung: " << 1 << endl;
    cout << "x^2 + 1 > 0 luon dung: " << 1 << endl;

    // Bài 15
    cout << "\nBai 15:\n";
    cout << "n^2 = 2 khong co nghiem nguyen: " << 0 << endl;
    cout << "n^2 < 0 khong co: " << 0 << endl;
    cout << "n^2 >= 0 luon dung: " << 1 << endl;

    // Bài 16
    cout << "\nBai 16:\n";
    cout << "x^2 + y^2 = 4 co nghiem: " << 1 << endl;
    cout << "Moi x co y sao cho x*y = 1: " << 1 << endl;
    cout << "Co x sao cho moi y x*y = 1: " << 0 << endl;
    cout << "x*y = y*x luon dung: " << 1 << endl;

    // Bài 17
    cout << "\nBai 17:\n";
    int a[4] = {0, 1, 2, 3};
    int tatCaChan = 1;
    int coChan = 0;
    int coLe = 0;
    int tatCaLe = 1;

    for (int i = 0; i < 4; i++) {
        if (a[i] % 2 == 0) coChan = 1;
        else coLe = 1;

        if (a[i] % 2 != 0) tatCaChan = 0;
        if (a[i] % 2 == 0) tatCaLe = 0;
    }

    cout << "Tat ca la so chan: " << tatCaChan << endl;
    cout << "Co so chan: " << coChan << endl;
    cout << "Co so le: " << coLe << endl;
    cout << "Tat ca la so le: " << tatCaLe << endl;
    cout << "Khong phai tat ca la chan: " << (1 - tatCaChan) << endl;
    cout << "Khong co so chan: " << (1 - coChan) << endl;

    return 0;
}

