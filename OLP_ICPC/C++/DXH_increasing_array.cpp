#include <bits/stdc++.h>
#define ll long long
using namespace std;

void Greedy(vector<ll> &arr, int n) {
    ll moves = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            moves += (arr[i - 1] - arr[i]);
            arr[i] = arr[i - 1];  // Cập nhật để tiếp tục kiểm tra đúng
        }
    }
    cout << moves << "\n";
}

int main() {
    int n;
    cin >> n;

    vector<ll> arr(n); // Khởi tạo vector với n phần tử

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Greedy(arr, n);
}