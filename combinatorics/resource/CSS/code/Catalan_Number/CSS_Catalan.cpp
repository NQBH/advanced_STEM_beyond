#include <iostream>
#include <climits>

using namespace std;

const unsigned long long MAX_ULL = ULLONG_MAX;

unsigned long long factorial(int n) {
    if (n < 0) return 0;
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        if (result > MAX_ULL / i) {
            return MAX_ULL;
        }
        result *= i;
    }
    return result;
}

unsigned long long permutation(int n, int k) {
    if (k > n || k < 0 || n < 0) return 0;
    unsigned long long result = 1;
    for (int i = n - k + 1; i <= n; ++i) {
        if (result > MAX_ULL / i) {
            return MAX_ULL;
        }
        result *= i;
    }
    return result;
}

unsigned long long combination(int n, int k) {
    if (k > n || k < 0 || n < 0) return 0;
    k = min(k, n - k);
    unsigned long long result = 1;
    for (int i = 1; i <= k; ++i) {
        if (result > MAX_ULL / (n - i + 1) || result * (n - i + 1) / i > MAX_ULL) {
            return MAX_ULL;
        }
        result = result * (n - i + 1) / i;
    }
    return result;
}

unsigned long long catalan(int n) {
    if (n < 0) return 0;
    unsigned long long result = combination(2 * n, n);
    if (result > MAX_ULL / (n + 1)) {
        return MAX_ULL; 
    }
    return result / (n + 1);
}

void find_overflow() {
    int p_n_overflow = -1;
    for (int n = 1; n <= 100; ++n) {
        if (factorial(n) == MAX_ULL) {
            p_n_overflow = n;
            break;
        }
    }

    int a_n_k_overflow = -1;
    for (int n = 1; n <= 100; ++n) {
        int k = n / 2;
        if (permutation(n, k) == MAX_ULL) {
            a_n_k_overflow = n;
            break;
        }
    }

    int c_n_k_overflow = -1;
    for (int n = 1; n <= 100; ++n) {
        int k = n / 2;
        if (combination(n, k) == MAX_ULL) {
            c_n_k_overflow = n;
            break;
        }
    }

    int catalan_overflow = -1;
    for (int n = 1; n <= 100; ++n) {
        if (catalan(n) == MAX_ULL) {
            catalan_overflow = n;
            break;
        }
    }

    cout << "P_n = n! causes overflow at n = " << p_n_overflow << endl;
    cout << "A_n^k causes overflow at n = " << a_n_k_overflow << " (with k = n/2)" << endl;
    cout << "C_n^k causes overflow at n = " << c_n_k_overflow << " (with k = n/2)" << endl;
    cout << "Catalan number causes overflow at n = " << catalan_overflow << endl;
}

int main() {
    cout << "Calculating and checking for overflow:" << endl;
    find_overflow();
    return 0;
}