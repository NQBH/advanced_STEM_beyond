#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        // Kiểm tra xem ký tự ở giữa có xuất hiện ở đầu hoặc cuối không
        bool found = false;
        for (int i = 1; i < n - 1; ++i) {
            string a = s.substr(0, i);
            string b = s.substr(i, 1);
            string c = s.substr(i + 1);
            string ac = a + c;
            if (ac.find(b) != string::npos) {
                found = true;
                break;
            }
        }

        cout << (found ? "Yes" : "No") << endl;
    }
    return 0;
}
