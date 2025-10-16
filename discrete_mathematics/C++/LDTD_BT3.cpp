#include <iostream>
using namespace std;

int main() {
    int x, y, z;

    cout << "=== KIEM TRA CAC MENH DE LOGIC ===\n";

    // ----- Mệnh đề (a) -----
    cout << "\nNhap gia tri x: ";
    cin >> x;

    bool p_a = (x + 1 == 2);  // mệnh đề p
    bool q_a = true;          // mệnh đề q (luôn đúng)

    cout << "\nMenh de (a): Neu x + 1 = 2 thi menh de dung.\n";
    cout << "Ket qua: " << (p_a ? "Dung" : "Sai") << endl;

    // Kiểm tra phản đảo, đảo, nghịch đảo
    cout << "Dao: Neu menh de dung thi x + 1 = 2 → " << (q_a ? (p_a ? "Dung" : "Sai") : "Khong xac dinh") << endl;
    cout << "Phan dao: Neu x + 1 != 2 thi menh de sai → " << ((!p_a) ? "Dung" : "Sai") << endl;
    cout << "Nghich dao: Neu menh de sai thi x + 1 != 2 → " << ((!q_a) ? ((!p_a) ? "Dung" : "Sai") : "Khong xac dinh") << endl;

    // ----- Mệnh đề (b) -----
    cout << "\nNhap x, y, z: ";
    cin >> x >> y >> z;

    bool p_b = (x + y == z);
    bool q_b = true;

    cout << "\nMenh de (b): Neu x + y = z thi menh de dung.\n";
    cout << "Ket qua: " << (p_b ? "Dung" : "Sai") << endl;

    cout << "Dao: Neu menh de dung thi x + y = z → " << (q_b ? (p_b ? "Dung" : "Sai") : "Khong xac dinh") << endl;
    cout << "Phan dao: Neu x + y != z thi menh de sai → " << ((!p_b) ? "Dung" : "Sai") << endl;
    cout << "Nghich dao: Neu menh de sai thi x + y != z → " << ((!q_b) ? ((!p_b) ? "Dung" : "Sai") : "Khong xac dinh") << endl;

    cout << "\n=== Ket thuc chuong trinh ===\n";
    return 0;
}
