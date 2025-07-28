#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

namespace core {
    /**
     * @brief Count the number of integer partitions of n with maximum part k (p_max(n, k))
     * @param n The integer to partition
     * @param k The maximum part allowed
     * @return The number of partitions
     */
    int countPartitionsWithMaxPart(int n, int k) {
        if (k > n) return 0;
        if (k == n) return 1;
        if (k == 0) return 0;
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k && j <= i; ++j) {
                for (int prev = 0; prev <= j; ++prev) {
                    if (i - j >= 0) {
                        dp[i][j] += dp[i - j][prev];
                    }
                }
            }
        }
        return dp[n][k];
    }
    /**
     * @brief Count the number of integer partitions of n into exactly k parts (p_k(n))
     * @param n The integer to partition
     * @param k The number of parts
     * @return The number of partitions
     */
    int countPartitionsWithKParts(int n, int k) {
        if (k > n) return 0;
        if (k == 1) return 1;
        if (k == n) return 1;
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k && j <= i; ++j) {
                dp[i][j] += dp[i - 1][j - 1];
                if (i - j >= 0) {
                    dp[i][j] += dp[i - j][j];
                }
            }
        }
        return dp[n][k];
    }
    /**
     * @brief Print all partitions of n with maximum part k
     * @param n The integer to partition
     * @param k The maximum part allowed
     * @param current The current partition (for recursion)
     * @param sum The current sum
     * @param maxUsed The current maximum part used
     */
    void printPartitionsWithMaxPart(int n, int k, std::vector<int>& current, int sum, int maxUsed) {
        if (sum == n) {
            if (maxUsed == k) {
                std::cout << "  ";
                for (std::size_t i = 0; i < current.size(); ++i) {
                    std::cout << current[i];
                    if (i < current.size() - 1) std::cout << " + ";
                }
                std::cout << std::endl;
            }
            return;
        }
        for (int i = 1; i <= k && sum + i <= n; ++i) {
            current.push_back(i);
            printPartitionsWithMaxPart(n, k, current, sum + i, std::max(maxUsed, i));
            current.pop_back();
        }
    }
    /**
     * @brief Print all partitions of n into exactly k parts
     * @param n The integer to partition
     * @param k The number of parts
     * @param current The current partition (for recursion)
     * @param sum The current sum
     * @param parts The current number of parts
     */
    void printPartitionsWithKParts(int n, int k, std::vector<int>& current, int sum, int parts) {
        if (parts == k) {
            if (sum == n) {
                std::cout << "  ";
                for (std::size_t i = 0; i < current.size(); ++i) {
                    std::cout << current[i];
                    if (i < current.size() - 1) std::cout << " + ";
                }
                std::cout << std::endl;
            }
            return;
        }
        int start = (current.empty()) ? 1 : current.back();
        for (int i = start; i <= n - sum && parts + 1 <= k; ++i) {
            if (sum + i <= n) {
                current.push_back(i);
                printPartitionsWithKParts(n, k, current, sum + i, parts + 1);
                current.pop_back();
            }
        }
    }
} // namespace core

namespace utils {
    void processTestCase(int n, int k) {
        std::cout << "\n=== TEST CASE: n = " << n << ", k = " << k << " ===" << std::endl;
        int pMaxNk = core::countPartitionsWithMaxPart(n, k);
        std::cout << "p_max(" << n << "," << k << ") = " << pMaxNk << std::endl;
        int pKN = core::countPartitionsWithKParts(n, k);
        std::cout << "p_" << k << "(" << n << ") = " << pKN << std::endl;
        std::cout << "\n=== COMPARISON ===" << std::endl;
        if (pMaxNk == pKN) {
            std::cout << "p_max(" << n << "," << k << ") = p_" << k << "(" << n << ")" << std::endl;
            std::cout << "p_max(" << n << "," << k << ") = p_" << k << "(" << n << ") = " << pMaxNk << std::endl;
        } else {
            std::cout << "p_max(" << n << "," << k << ") != p_" << k << "(" << n << ")" << std::endl;
            std::cout << "p_max(" << n << "," << k << ") = " << pMaxNk << std::endl;
            std::cout << "p_" << k << "(" << n << ") = " << pKN << std::endl;
        }
        if (n <= 10 && k <= 5) {
            std::cout << "\n=== PARTITION DETAILS ===" << std::endl;
            std::cout << "\nPartitions of " << n << " with maximum part " << k << ":" << std::endl;
            std::vector<int> temp;
            core::printPartitionsWithMaxPart(n, k, temp, 0, 0);
            std::cout << "\nPartitions of " << n << " into exactly " << k << " parts:" << std::endl;
            temp.clear();
            core::printPartitionsWithKParts(n, k, temp, 0, 0);
        }
        std::cout << "\n" << std::string(50, '=') << std::endl;
    }
} // namespace utils

int main() {
    std::cout << "=== PROBLEM 2: INTEGER PARTITION COUNTING ===" << std::endl;
    std::cout << "Reading input from file 'input.txt'..." << std::endl;
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cout << "Error: Cannot open input.txt!" << std::endl;
        std::cout << "Please enter n and k manually: ";
        int n, k;
        std::cin >> n >> k;
        utils::processTestCase(n, k);
        return 1;
    }
    int n, k;
    int testCount = 0;
    while (inputFile >> n >> k) {
        ++testCount;
        utils::processTestCase(n, k);
    }
    inputFile.close();
    std::cout << "\n=== SUMMARY ===" << std::endl;
    std::cout << "Processed " << testCount << " test case(s)." << std::endl;
    return 0;
} 