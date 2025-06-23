#include <iostream>
using namespace std;
#define ll long long
#define endl '\n'

/*
Vấn đề:
    quy tắc: ong đực sinh 1 cái, 1 đực mỗi năm rồi chết; ong cái sinh 1 đực mỗi năm rồi chết
    có 1 loài ong cái bất tử, có thể sinh sản vô hạn - mỗi năm 1 ong đực
Diễn biến:
    ban đầu chỉ có queen -> sinh 1 ong đực -> con đực đó sinh ra 1 con cái, 1 con đực khác
    -> con đực khác đó sinh ra 1 cái, 1 đực tiếp -> cứ thế tiếp tục
Giải quyết: Tính số lượng ong đực và tổng số con ong sau n năm.
*/

int main() {
    int n;
    const int queen = 1;

    while (true) {
        cin >> n;
        if (n == -1) break;

        ll female = 0, male = 0;
        for (int i = 1; i <= n; i++) {
            ll new_female = male;
            ll new_male = male + female + queen;
            male = new_male;
            female = new_female;
        }

        cout << male << " " << (male + female + queen) << endl;
    }

    return 0;
}