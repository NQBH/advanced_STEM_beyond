#include <iostream>
#include <utility>

using namespace std;

// Hàm trả về cặp {S_n, S_{n+1}}
// Độ phức tạp: O(log n)
pair<long long, long long> fast_doubling(long long n, long long m) {
    if (n == 0) {
        // Cơ sở: S_0 = 2, S_1 = 4
        return {2 % m, 4 % m}; 
    }

    // Đệ quy tính cặp {S_k, S_{k+1}} với k = n / 2
    pair<long long, long long> half = fast_doubling(n / 2, m);
    long long sk = half.first;       // S_k
    long long sk1 = half.second;     // S_{k+1}

    // Tính S_{2k} và S_{2k+1} dựa trên công thức
    // S_{2k} = (S_k)^2 - 2
    long long s2k = (sk * sk - 2) % m;
    if (s2k < 0) s2k += m;

    // S_{2k+1} = S_k * S_{k+1} - 4
    long long s2k_1 = (sk * sk1 - 4) % m;
    if (s2k_1 < 0) s2k_1 += m;

    if (n % 2 == 0) {
        // Nếu n chẵn (n = 2k), trả về {S_{2k}, S_{2k+1}}
        return {s2k, s2k_1};
    } else {
        // Nếu n lẻ (n = 2k + 1)
        // Ta cần trả về {S_{2k+1}, S_{2k+2}}
        // Tính S_{2k+2} dựa trên S_{2k+2} = 4*S_{2k+1} - S_{2k}
        long long s2k_2 = (4 * s2k_1 - s2k) % m;
        if (s2k_2 < 0) s2k_2 += m;
        
        return {s2k_1, s2k_2};
    }
}

void solve() {
    long long n, m;
    cin >> n >> m;

    // Gọi hàm để lấy cặp {S_n, S_{n+1}}, chỉ cần lấy phần tử đầu tiên
    pair<long long, long long> result = fast_doubling(n, m);
    cout << result.first << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}