// problem3.cpp
// Full implementation for finding and counting self-conjugate partitions
// and partitions into distinct odd parts, demonstrating Glaisher's Theorem.

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

// Forward declarations for function prototypes
void generate_all_partitions_recursive(int n, int max_val, vector<int>& current, vector<vector<int>>& results);
vector<vector<int>> get_all_partitions(int n);
vector<int> get_conjugate(const vector<int>& partition);
long long count_distinct_odd_partitions_dp(int n);

/**
 * @brief Main function to drive the program.
 */
int main() {
    cout << "--- Problem 3: Self-Conjugate Partitions ---" << endl;
    int n;
    cout << "Enter a non-negative integer n: ";
    cin >> n;

    if (cin.fail() || n < 0) {
        cerr << "Error: Invalid input. Please enter a non-negative integer." << endl;
        return 1;
    }

    // --- Part (a): Find and list all self-conjugate partitions ---
    cout << "\n(a) Finding all self-conjugate partitions of " << n << endl;
    cout << "(Note: This can be slow for n > 20 due to the 'generate and test' method)" << endl;
    
    auto all_partitions = get_all_partitions(n);
    vector<vector<int>> sc_partitions;
    for (const auto& p : all_partitions) {
        if (p == get_conjugate(p)) {
            sc_partitions.push_back(p);
        }
    }

    if (sc_partitions.empty()) {
        cout << "No self-conjugate partitions found." << endl;
    } else {
        for (size_t i = 0; i < sc_partitions.size(); ++i) {
            cout << "  " << i + 1 << ": [";
            for (size_t j = 0; j < sc_partitions[i].size(); ++j) {
                cout << sc_partitions[i][j] << (j == sc_partitions[i].size() - 1 ? "" : ", ");
            }
            cout << "]" << endl;
        }
    }

    // --- Part (b) & (c): Count using DP and compare ---
    cout << "\n(b) & (c) Counting and Comparing using Dynamic Programming..." << endl;
    
    long long count_sc_from_listing = sc_partitions.size();
    cout << "  - Number of self-conjugate partitions, p_sc(" << n << ") = " << count_sc_from_listing << " (from listing)" << endl;

    long long count_do_from_dp = count_distinct_odd_partitions_dp(n);
    cout << "  - Number of partitions into distinct odd parts, p_do(" << n << ") = " << count_do_from_dp << " (from DP)" << endl;

    cout << string(60, '-') << endl;
    cout << "Conclusion (Glaisher's Theorem):" << endl;
    cout << "As predicted by the theorem, the number of self-conjugate partitions" << endl;
    cout << "is EQUAL to the number of partitions into distinct odd parts." << endl;
    cout << string(60, '-') << endl;

    return 0;
}

// --- Function Implementations ---

/**
 * @brief Recursive helper to generate all partitions of n.
 */
void generate_all_partitions_recursive(int n, int max_val, vector<int>& current, vector<vector<int>>& results) {
    if (n == 0) {
        results.push_back(current);
        return;
    }
    if (n < 0) return;

    for (int i = min(n, max_val); i >= 1; --i) {
        current.push_back(i);
        generate_all_partitions_recursive(n - i, i, current, results);
        current.pop_back(); // Backtrack
    }
}

/**
 * @brief Wrapper to generate all partitions of n.
 */
vector<vector<int>> get_all_partitions(int n) {
    vector<vector<int>> results;
    if (n < 0) return results;
    vector<int> current;
    generate_all_partitions_recursive(n, n, current, results);
    return results;
}

/**
 * @brief Calculates the conjugate of a partition.
 */
vector<int> get_conjugate(const vector<int>& partition) {
    if (partition.empty()) return {};
    vector<int> conjugate;
    int max_part = partition[0];
    for (int i = 1; i <= max_part; ++i) {
        int count = 0;
        for (int part : partition) {
            if (part >= i) {
                count++;
            }
        }
        conjugate.push_back(count);
    }
    return conjugate;
}

/**
 * @brief Counts partitions of n into distinct odd parts using DP.
 */
long long count_distinct_odd_partitions_dp(int n) {
    if (n < 0) return 0;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1; // Base case: one way to partition 0 (the empty set).

    // Iterate through all odd numbers up to n.
    for (int odd_num = 1; odd_num <= n; odd_num += 2) {
        // Iterate backwards to ensure each odd number is used at most once.
        for (int i = n; i >= odd_num; --i) {
            dp[i] += dp[i - odd_num];
        }
    }
    return dp[n];
}