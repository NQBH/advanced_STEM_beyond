#include <bits/stdc++.h>
using namespace std;

bool findPair(const vector<long long>& S, long long a, long long b, char setName) {
    for (long long i = 0; i < S.size(); ++i)
        for (long long j = i + 1; j < S.size(); ++j) {
            long long d = abs(S[i] - S[j]);
            if (d == a || d == b) {
                cout << "Tim thay cap x, y trong tap " << setName << ": (" << S[i] << ", " << S[j] << "), |x - y| = " << d << '\n';
                return true;
            }
        }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, b;
    do cin >> a >> b; while ((a + b) % 2 == 0);

    // tạo dãy để chứng minh phản chứng
    vector<long long> A, B;
    long long x = 1; // x0 = 1
    int max_steps = 10000;
    A.push_back(x); // x0 vào A
    bool is_A = false; // x1 vào B
    for (int i = 0; i < max_steps; ++i) {
        x += (i % 2 == 0) ? a : b; // x_{n+1} = x_n + a (n chẵn) hoặc + b (n lẻ)
        if (is_A) A.push_back(x);
        else B.push_back(x);
        is_A = !is_A;
    }

    // kiểm tra cặp trong A & B
    bool res = findPair(A, a, b, 'A') || findPair(B, a, b, 'B');
    if (!res) {
        cout << "Khong tim thay cap trong " << max_steps + 1 << " phan tu dau tien.\n";
        cout << "Nhung do gcd(a,b) = 1 & N* vo han, luon ton tai cap thoa man.\n";
    }
    return 0;
}