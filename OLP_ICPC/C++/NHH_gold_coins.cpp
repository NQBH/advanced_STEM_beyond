#include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    int n; 
    
    while (true){
        cin >> n;

        if (n == 1) {
            cout << n << " " << 1 << endl;
            return 0;
        } 
        if (n == 0) {
            return 0;
        }

        ll sum = 0; 
        int day = 0; // để đếm số ngày đã qua
        int k = 1; // số lượng vàng cho mỗi nhóm ngày, bắt đầu từ 1 (ngày 1 nhận 1 vàng) 
        while (day < n){
            int group = min(k, n - day); // để không vượt quá n; bằng nhau thì break 
            sum += group * k; // số vàng cho nhóm ngày đó 
            day += group; // sau ngày 2 và 3, số ngày đã qua là 3 (+ ngày 1)
            k++; 
        }
        cout << n << " " << sum << endl;  
    }

    return 0; 
}