// problem1.cpp
// Full implementation for finding partitions of n into k parts
// and drawing their Ferrers and transposed Ferrers diagrams.

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

// Use the standard namespace for brevity in this small program.
using namespace std;

/**
 * @brief Draws the Ferrers diagram (F) for a given partition.
 * @param partition A vector of integers representing a partition.
 */
void draw_ferrers(const vector<int>& partition) {
    cout << "  Ferrers Diagram (F):" << endl;
    for (int part : partition) {
        cout << "    ";
        for (int i = 0; i < part; ++i) {
            cout << "* ";
        }
        cout << endl;
    }
}

/**
 * @brief Draws the transposed Ferrers diagram (F^T).
 * @param partition A vector of integers representing a partition.
 */
void draw_transpose(const vector<int>& partition) {
    cout << "  Transposed Ferrers Diagram (F^T):" << endl;
    if (partition.empty()) {
        return;
    }

    int max_part = partition[0];
    for (int i = 1; i <= max_part; ++i) {
        int count = 0;
        // The length of row i is the number of parts in the original partition >= i.
        for (int part : partition) {
            if (part >= i) {
                count++;
            }
        }
        cout << "    ";
        for (int j = 0; j < count; ++j) {
            cout << "* ";
        }
        cout << endl;
    }
}

/**
 * @brief Core recursive function using backtracking to find partitions.
 * @param target_sum The remaining sum to be partitioned.
 * @param num_parts The number of remaining parts to find.
 * @param max_val The maximum value for the next part (to ensure non-increasing order).
 * @param current_partition The partition being built in the current recursive path. Passed by reference.
 * @param results A vector to store all found partitions. Passed by reference.
 */
void find_partitions_recursive(int target_sum, int num_parts, int max_val,
                               vector<int>& current_partition,
                               vector<vector<int>>& results) {
    // Base Case: If only one part remains, it must equal the entire remaining sum.
    if (num_parts == 1) {
        if (target_sum >= 1 && target_sum <= max_val) {
            current_partition.push_back(target_sum);
            results.push_back(current_partition);
            current_partition.pop_back(); // Backtrack for the next exploration.
        }
        return;
    }

    // Recursive Step: Try all possible values for the current part.
    for (int i = max_val; i >= 1; --i) {
        int remaining_sum = target_sum - i;
        int remaining_parts = num_parts - 1;

        // Pruning: Check if a valid partition is still possible.
        if (remaining_sum >= remaining_parts && remaining_sum <= remaining_parts * i) {
            current_partition.push_back(i);
            find_partitions_recursive(remaining_sum, remaining_parts, i, current_partition, results);
            current_partition.pop_back(); // Backtrack after exploring this branch.
        }
    }
}

/**
 * @brief Wrapper function to initialize and start the recursive process.
 * @param n The integer to partition.
 * @param k The number of parts.
 * @return A vector of vectors, containing all valid partitions.
 */
vector<vector<int>> generate_all_partitions(int n, int k) {
    vector<vector<int>> results;
    if (n < k || k <= 0) {
        return results;
    }
    
    vector<int> current_partition;
    // The initial max_val is n - (k-1) because k-1 parts must be at least 1.
    int initial_max_val = n - (k - 1);
    find_partitions_recursive(n, k, initial_max_val, current_partition, results);
    return results;
}

/**
 * @brief Main function to drive the program.
 */
int main() {
    int n, k;
    cout << "--- Problem 1: Ferrers Diagrams & Partitions ---" << endl;
    cout << "Enter the integer to partition (n): ";
    cin >> n;
    cout << "Enter the number of parts (k): ";
    cin >> k;

    // Input validation
    if (cin.fail() || n <= 0 || k <= 0) {
        cerr << "Error: Invalid input. Please enter positive integers." << endl;
        return 1;
    }

    // Generate all partitions.
    auto partitions = generate_all_partitions(n, k);
    cout << string(50, '-') << endl;
    
    if (partitions.empty()) {
        cout << "There are no partitions of " << n << " into " << k << " parts (p_" << k << "(" << n << ") = 0)." << endl;
    } else {
        cout << "Found " << partitions.size() << " partitions of " << n << " into " << k << " parts (p_" << k << "(" << n << ") = " << partitions.size() << ")." << endl;
        
        for (size_t i = 0; i < partitions.size(); ++i) {
            // Print the partition itself
            cout << "\n[" << i + 1 << "] Partition: [";
            for (size_t j = 0; j < partitions[i].size(); ++j) {
                cout << partitions[i][j] << (j == partitions[i].size() - 1 ? "" : ", ");
            }
            cout << "]" << endl;

            // Draw the diagrams
            draw_ferrers(partitions[i]);
            draw_transpose(partitions[i]);
            cout << string(50, '-') << endl;
        }
    }

    return 0;
}