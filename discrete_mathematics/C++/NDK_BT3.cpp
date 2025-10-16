#include <iostream>
using namespace std;

int main() {
    int x, y, z;

    // Nhập giá trị từ người dùng
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
    cout << "Nhap z: ";
    cin >> z;

    // Mệnh đề gốc
    cout << "\nMệnh đề (a): x + 1 == 2 => " << ((x + 1 == 2) ? "Dung" : "Sai") << endl;
    cout << "Mệnh đề (b): x + y == z => " << ((x + y == z) ? "Dung" : "Sai") << endl;

    // Đảo (giữ nguyên vì không có hệ quả rõ ràng)
    cout << "\nĐảo của (a): x + 1 == 2 => " << ((x + 1 == 2) ? "Dung" : "Sai") << endl;
    cout << "Đảo của (b): x + y == z => " << ((x + y == z) ? "Dung" : "Sai") << endl;

    // Nghịch đảo
    cout << "\nNghịch đảo của (a): x + 1 != 2 => " << ((x + 1 != 2) ? "Dung" : "Sai") << endl;
    cout << "Nghịch đảo của (b): x + y != z => " << ((x + y != z) ? "Dung" : "Sai") << endl;

    // Phản đảo (giống nghịch đảo vì không có mệnh đề Q)
    cout << "\nPhản đảo của (a): x + 1 != 2 => " << ((x + 1 != 2) ? "Dung" : "Sai") << endl;
    cout << "Phản đảo của (b): x + y != z => " << ((x + y != z) ? "Dung" : "Sai") << endl;

    return 0;
}
