#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Class đại diện cho từng sinh viên
class sv {
protected:
    int id;
    vector<int> friends;

public:
    sv(int id) : id(id) {}

    void addFriend(int friendId) {
        friends.push_back(friendId);
    }

    int getId() const { return id; }
    vector<int> getFriends() const { return friends; }
};

// Class quản lý hệ thống kết nối sinh viên
class sodoketnoisv {
private:
    map<int, sv*> students;

public:
    void addsv(int id) {
        if (students.find(id) == students.end())
            students[id] = new sv(id);
    }

    void addbanbe(int id, int friendId) {
        students[id]->addFriend(friendId);
        students[friendId]->addFriend(id);
    }

    map<int, sv*> getStudents() {
        return students;
    }
};

// Hàm chia phòng
void chiaphong(sodoketnoisv &sinhvien) {
    // cho trước một clique gồm 4 sinh viên
    vector<int> clique = {1, 2, 3, 4};

    vector<int> roomA, roomB;

    for (int i = 0; i < static_cast<int>(clique.size()); i++) {
        if (i < static_cast<int>(clique.size() / 2))
            roomA.push_back(clique[i]);
        else
            roomB.push_back(clique[i]);
    }

    map<int, sv*> allStudents = sinhvien.getStudents();
    vector<int> others;

    for (auto pair : allStudents) {
        int id = pair.first;
        if (find(clique.begin(), clique.end(), id) == clique.end())
            others.push_back(id);
    }

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
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore(); // bỏ xuống dòng

    sodoketnoisv sinhvien;
    set<int> allIDs;

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        vector<int> group;
        int id;
        while (ss >> id) {
            group.push_back(id);
            allIDs.insert(id);
        }

        // Trước tiên add tất cả sv mới
        for (int id : group)
            sinhvien.addsv(id);

        // Sinh các cặp bạn bè trong nhóm
        for (int j = 0; j < static_cast<int>(group.size()); j++) {
            for (int k = j + 1; k < static_cast<int>(group.size()); k++) {
                sinhvien.addbanbe(group[j], group[k]);
            }
        }
    }

    // Gọi chia phòng
    chiaphong(sinhvien);
}