// problem2.cpp
// Full implementation for counting partitions of n where the largest part is k,
// and comparing it to the number of partitions of n into k parts.
// The program uses a Dynamic Programming approach for efficient calculation.

#include <iostream>
#include <vector>
#include <string>

// Use the standard namespace for brevity in this small program.
using namespace std;

/**
 * @brief Counts the number of partitions of n into exactly k parts using Dynamic Programming.
 * 
 * This function implements the recurrence p_k(n) = p_{k-1}(n-1) + p_k(n-k).
 * Based on a theorem in partition theory, this value is also equal to p_max(n, k),
 * which is the number of partitions of n where the largest part is k.
 * 
 * @param n The integer to partition.
 * @param k The number of parts (or the value of the largest part).
 * @return The number of partitions. Returns 0 for invalid inputs.
 */
long long count_partitions_dp(int n, int k) {
    // Input validation.
    if (n < 0 || k < 0 || k > n) {
        if (n == 0 && k == 0) {
            // This case will be handled by the base case.
        } else {
            return 0;
        }
    }

    // dp[i][j] will store the number of partitions of integer 'i' into exactly 'j' parts.
    // Use `long long` to prevent potential integer overflow for larger n and k.
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

    // Base case: There is one way to partition 0 into 0 parts (the empty partition).
    dp[0][0] = 1;

    // Fill the DP table in a bottom-up manner.
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            // An integer 'i' cannot be partitioned into 'j' parts if j > i.
            if (i < j) {
                continue;
            }
            
            // The recurrence relation p_k(n) = p_{k-1}(n-1) + p_k(n-k)
            // translates to: dp[i][j] = dp[i-1][j-1] + dp[i-j][j].
            dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
        }
    }

    return dp[n][k];
}

/**
 * @brief Main function to drive the program.
 */
int main() {
    int n, k;
    cout << "--- Problem 2: Counting Partitions by Largest Part ---" << endl;
    cout << "Enter the integer to partition (n): ";
    cin >> n;
    cout << "Enter the value of the largest part (k): ";
    cin >> k;

    // Input validation
    if (cin.fail() || n < 0 || k < 0) {
        cerr << "Error: Invalid input. Please enter non-negative integers." << endl;
        return 1;
    }

    cout << string(60, '-') << endl;
    cout << "Mathematical Analysis Result:" << endl;
    cout << "The number of partitions of n with the largest part k, p_max(n, k)" << endl;
    cout << "  is EQUAL to" << endl;
    cout << "The number of partitions of n into exactly k parts, p_k(n)." << endl;
    cout << "This program calculates this value using Dynamic Programming." << endl;
    cout << string(60, '-') << endl;

    // Calculate the value using the DP function.
    long long result = count_partitions_dp(n, k);

    // Print the final, unified result.
    cout << "The value for p_max(" << n << ", " << k << ") = p_k(" << n << ") is: " << result << endl;
    cout << string(60, '-') << endl;

    return 0;
}