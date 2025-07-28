#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map> // For memoization in recursive DP

// Use a map for memoization in the recursive self-conjugate partition count
// Key: pair<n, k>, Value: count
std::map<std::pair<int, int>, long long> memo_selfcjg_rec;

// (c)(i) Recursive implementation for p_k^selfcjg(n) (partitions into k distinct odd parts)
// n: the number to partition
// k: the number of distinct odd parts (hooks)
long long p_selfcjg_recursive(int n, int k) {
    // Base cases
    if (k < 0 || n < 0) {
        return 0; // Invalid input, no partitions possible
    }
    if (k == 0) {
        return (n == 0) ? 1 : 0; // p_0^selfcjg(0) = 1 (empty partition), otherwise 0
    }
    // Smallest sum for k distinct odd parts is k^2 (1 + 3 + ... + (2k-1))
    if (n < k * k) {
        return 0; // Not enough sum to form k distinct odd parts
    }

    // Check memoization table to avoid redundant calculations
    if (memo_selfcjg_rec.count({n, k})) {
        return memo_selfcjg_rec[{n, k}];
    }

    // Recurrence relation: p_k^selfcjg(n) = p_k^selfcjg(n-2k) + p_{k-1}^selfcjg(n-1)
    // Term 1: Corresponds to partitions where all parts are >= 3. We subtract 2 from each of the k parts.
    // Term 2: Corresponds to partitions where the smallest part is 1. We remove 1.
    long long result = p_selfcjg_recursive(n - 2 * k, k) + p_selfcjg_recursive(n - 1, k - 1);

    // Store result in memoization table
    memo_selfcjg_rec[{n, k}] = result;
    return result;
}

// (c)(ii) Dynamic Programming implementation for p_k^selfcjg(n) (partitions into k distinct odd parts)
// n: the number to partition
// k: the number of distinct odd parts (hooks)
long long p_selfcjg_dp_impl(int n, int k) {
    // dp[i][j] stores p_j^selfcjg(i)
    // Initialize a 2D vector (DP table) with zeros
    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(k + 1, 0));

    // Base case: p_0^selfcjg(0) = 1 (empty partition)
    dp[0][0] = 1;

    // Fill the DP table using the recurrence relation
    for (int i = 0; i <= n; ++i) { // Iterate through sums from 0 to n
        for (int j = 0; j <= k; ++j) { // Iterate through number of parts (hooks) from 0 to k
            if (i == 0 && j == 0) continue; // Already handled dp[0][0]

            // Pruning: Smallest sum for j distinct odd parts is j*j
            if (i < j * j) {
                dp[i][j] = 0;
                continue;
            }

            // Term 1: p_j^selfcjg(i-2j)
            // This term is valid if i-2j is non-negative
            if (i >= 2 * j) {
                dp[i][j] += dp[i - 2 * j][j];
            }
            // Term 2: p_{j-1}^selfcjg(i-1)
            // This term is valid if i-1 and j-1 are non-negative
            if (i >= 1 && j >= 1) {
                dp[i][j] += dp[i - 1][j - 1];
            }
        }
    }
    return dp[n][k]; // Return the desired value
}

// Global vector to store distinct odd partitions found for part (a)
std::vector<std::vector<int>> distinct_odd_partitions_found;

// Helper function for (a) to generate distinct odd partitions using backtracking
// target_sum: the remaining sum that needs to be partitioned
// remaining_parts: the number of parts (elements) still needed in the partition
// max_val: the maximum odd value that can be chosen for the current part
// current_partition: the partition being built (passed by reference)
void generate_distinct_odd_partitions(int target_sum, int remaining_parts, int max_val, std::vector<int>& current_partition) {
    // Base case: if no more parts are needed
    if (remaining_parts == 0) {
        if (target_sum == 0) { // If the sum is also zero, a valid partition is found
            distinct_odd_partitions_found.push_back(current_partition);
        }
        return;
    }

    // Pruning: if the target_sum is too small to form 'remaining_parts' distinct odd integers
    // The smallest sum for 'remaining_parts' distinct odd integers is 1+3+...+(2*remaining_parts-1) = remaining_parts^2
    if (target_sum < remaining_parts * remaining_parts) {
        return;
    }

    // Iterate through possible odd values for the current part in decreasing order
    // 'val' must be odd and less than or equal to 'max_val' and 'target_sum'
    for (int val = std::min(max_val, target_sum); val >= 1; val -= 2) {
        // Ensure the part is odd (already handled by val -= 2 if max_val is odd)
        // if (val % 2 == 0) continue; // This check is redundant if max_val is initialized correctly and decremented by 2

        // If the current value can be added without exceeding the target_sum
        if (val <= target_sum) {
            current_partition.push_back(val); // Add the current value to the partition
            // Recursively call for the remaining sum and parts,
            // setting the new max_val to 'val - 2' to ensure distinctness and decreasing order
            generate_distinct_odd_partitions(target_sum - val, remaining_parts - 1, val - 2, current_partition);
            current_partition.pop_back(); // Backtrack: remove the current value for other possibilities
        }
    }
}

// Function for (b) to count partitions of n with an odd number of parts
// n: the number to partition
long long count_partitions_odd_num_parts(int n) {
    // dp_p[i][j] stores the number of partitions of i into j parts
    // Initialize a 2D vector (DP table) for standard partition function p(n,k)
    std::vector<std::vector<long long>> dp_p(n + 1, std::vector<long long>(n + 1, 0));

    // Base case: partition of 0 into 0 parts is 1 (empty partition)
    dp_p[0][0] = 1;

    // Fill the DP table using the standard recurrence relation for p(n,k)
    for (int i = 1; i <= n; ++i) { // Iterate through sums from 1 to n
        for (int j = 1; j <= i; ++j) { // Iterate through number of parts from 1 to i
            // p(i,j) = p(i-1, j-1) + p(i-j, j)
            // Term 1: p(i-1, j-1) - corresponds to partitions including at least one '1'
            dp_p[i][j] = dp_p[i - 1][j - 1];
            // Term 2: p(i-j, j) - corresponds to partitions where all parts are >= 2
            if (i >= j) { // Ensure i-j is non-negative
                dp_p[i][j] += dp_p[i - j][j];
            }
        }
    }

    long long total_odd_parts_count = 0;
    // Sum up p(n,j) for all odd j (number of parts)
    for (int j = 1; j <= n; ++j) {
        if (j % 2 != 0) { // If the number of parts (j) is odd
            total_odd_parts_count += dp_p[n][j];
        }
    }
    return total_odd_parts_count;
}

// Function to print a partition in (p1,p2,...) format
void print_partition(const std::vector<int>& p) {
    std::cout << "(";
    for (size_t i = 0; i < p.size(); ++i) {
        std::cout << p[i];
        if (i < p.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << ")";
}

int main() {
    std::cout << "Nhap n: ";
    int n;
    std::cin >> n;

    std::cout << "Nhap k: ";
    int k;
    std::cin >> k;

    std::cout << "\n--- (a) Dem va liet ke so phan hoach tu lien hop cua " << n << " co " << k << " phan (hook) ---\n";
    distinct_odd_partitions_found.clear(); // Clear previous results before generating

    std::vector<int> current_partition;
    // Initial call for generating distinct odd partitions.
    // max_val is set to 'n' if n is odd, or 'n-1' if n is even, to ensure the largest possible part is odd.
    generate_distinct_odd_partitions(n, k, n % 2 == 0 ? n - 1 : n, current_partition);

    long long count_selfcjg_a = distinct_odd_partitions_found.size();
    std::cout << "So phan hoach tu lien hop cua " << n << " co " << k << " phan (hook) la: " << count_selfcjg_a << "\n";
    std::cout << "Cac phan hoach tu lien hop (duoi dang phan hoach le phan biet tuong ung):\n";
    if (count_selfcjg_a == 0) {
        std::cout << "Khong co phan hoach nao.\n";
    } else {
        for (const auto& p : distinct_odd_partitions_found) {
            print_partition(p);
            std::cout << " (tong = " << std::accumulate(p.begin(), p.end(), 0) << ")\n";
        }
    }

    std::cout << "\n--- (b) Dem so phan hoach cua " << n << " co le phan, va so sanh ---\n";
    long long count_odd_num_parts = count_partitions_odd_num_parts(n);
    std::cout << "So phan hoach cua " << n << " co le phan la: " << count_odd_num_parts << "\n";
    std::cout << "So sanh voi p_k^selfcjg(" << n << ") voi k=" << k << " (tu phan a): " << count_selfcjg_a << "\n";
    if (count_odd_num_parts == count_selfcjg_a) {
        std::cout << "Hai so nay BANG NHAU.\n";
    } else {
        std::cout << "Hai so nay KHAC NHAU.\n";
    }

    std::cout << "\n--- (c) Thiet lap cong thuc truy hoi cho p_k^selfcjg(n) va implementation ---\n";

    // (c)(i) Recursive implementation with memoization
    memo_selfcjg_rec.clear(); // Clear memoization table before recursive call
    long long rec_result = p_selfcjg_recursive(n, k);
    std::cout << "\n(i) Ket qua bang de quy (co nho): p_" << k << "^selfcjg(" << n << ") = " << rec_result << "\n";

    // (c)(ii) Dynamic Programming implementation
    long long dp_result = p_selfcjg_dp_impl(n, k);
    std::cout << "(ii) Ket qua bang quy hoach dong: p_" << k << "^selfcjg(" << n << ") = " << dp_result << "\n";

    return 0;
}
