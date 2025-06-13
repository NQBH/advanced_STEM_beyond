#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Class đại diện cho từng sinh viên
class sv {
protected:
    int id;
    vector<int> friends;

public:
    // Constructor
    sv(int id) : id(id) {}

    // Phương thức thêm bạn bè
    void addFriend(int friendId) {
        friends.push_back(friendId);
    }

    // Getter: để lấy id từ bên ngoài khi cần
    int getId() const { return id; }

    // Getter: để lấy danh sách bạn bè
    vector<int> getFriends() const { return friends; }
};

// Class quản lý toàn bộ hệ thống kết nối sinh viên
class sodoketnoisv {
private:
    map<int, sv*> students;

public:
    void addsv(int id) {
        students[id] = new sv(id);
    }

    void addbanbe(int id, int friendId) {
        students[id]->addFriend(friendId);
        students[friendId]->addFriend(id);
    }

    // Getter để lấy toàn bộ danh sách sinh viên ra
    map<int, sv*> getStudents() {
        return students;
    }
};

// Hàm chia phòng
void chiaphong(sodoketnoisv &sinhvien) {
    // Giả sử tìm được clique sẵn
    vector<int> clique = {203, 204, 205, 206};

    vector<int> roomA, roomB;

    // Chia clique vào 2 phòng
    for (int i = 0; i < static_cast<int>(clique.size()); i++) {
        if (i < static_cast<int>(clique.size() / 2))
            roomA.push_back(clique[i]);
        else
            roomB.push_back(clique[i]);
    }

    // Tìm những sinh viên còn lại (vệ tinh)
    map<int, sv*> allStudents = sinhvien.getStudents();
    vector<int> others;

    for (auto pair : allStudents) {
        int id = pair.first;
        if (find(clique.begin(), clique.end(), id) == clique.end()) {
            others.push_back(id);
        }
    }

    // Phân bổ vệ tinh vào 2 phòng
    for (int id : others) {
        int countA = 0, countB = 0;
        vector<int> friends = sinhvien.getStudents()[id]->getFriends();

        for (int friendId : friends) {
            if (find(roomA.begin(), roomA.end(), friendId) != roomA.end())
                countA++;
            if (find(roomB.begin(), roomB.end(), friendId) != roomB.end())
                countB++;
        }

        if (countA <= countB)
            roomA.push_back(id);
        else
            roomB.push_back(id);
    }

    // In kết quả chia phòng ra màn hình (kiểm tra)
    cout << "Room A: ";
    for (int id : roomA)
        cout << id << " ";
    cout << endl;

    cout << "Room B: ";
    for (int id : roomB)
        cout << id << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);

    sodoketnoisv sinhvien;

    // Thêm sinh viên
    sinhvien.addsv(203);
    sinhvien.addsv(204);
    sinhvien.addsv(205);
    sinhvien.addsv(206);
    sinhvien.addsv(207);
    sinhvien.addsv(208);

    // Thêm các cặp bạn bè (ví dụ)
    sinhvien.addbanbe(203, 204);
    sinhvien.addbanbe(204, 205);
    sinhvien.addbanbe(205, 206);
    sinhvien.addbanbe(203, 205);
    sinhvien.addbanbe(203, 206);
    sinhvien.addbanbe(204, 206);
    sinhvien.addbanbe(207, 203);
    sinhvien.addbanbe(208, 204);

    // Gọi hàm chia phòng
    chiaphong(sinhvien);
}
