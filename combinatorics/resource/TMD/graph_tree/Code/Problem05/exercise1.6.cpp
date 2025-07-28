#include <iostream>
#include <vector>
#include <numeric>     // For std::iota
#include <algorithm>   // For std::next_permutation
#include <string>

// A type alias for a matching, which is a vector of pairs.
// Each pair represents a matched edge, e.g., {(x_vertex, y_vertex), ...}.
using Matching = std::vector<std::pair<int, int>>;

/**
 * @brief Exercise 1.6: Enumerates all perfect matchings in a complete bipartite graph K_p,p.
 *
 * A perfect matching in K_p,p pairs every vertex from one partition (say, X of size p)
 * with a unique vertex from the other partition (Y of size p). The number of such
 * matchings is p!, which corresponds to the number of permutations of the vertices in Y.
 *
 * This function generates all these permutations to list every possible perfect matching.
 * It returns an empty list if p != q, as perfect matchings do not exist.
 *
 * @param p The size of the first partition.
 * @param q The size of the second partition.
 * @return A vector containing all possible perfect matchings.
 */
std::vector<Matching> enumerate_perfect_matchings_cpp(int p, int q) {
    // A perfect matching can only exist if the partitions have the same size.
    if (p != q || p <= 0) {
        return {};
    }
    
    std::vector<Matching> all_matchings;
    
    // Create a vector representing the vertices in partition Y: {0, 1, ..., p-1}.
    std::vector<int> partition_Y(p);
    std::iota(partition_Y.begin(), partition_Y.end(), 0);

    // Use std::next_permutation to generate all possible pairings for partition Y.
    // The vertices in partition X are implicitly {0, 1, ..., p-1}.
    do {
        Matching current_matching;
        // For each permutation of Y, create the corresponding matching.
        for (int i = 0; i < p; ++i) {
            // Match vertex i from partition X with vertex partition_Y[i] from partition Y.
            current_matching.push_back({i, partition_Y[i]});
        }
        all_matchings.push_back(current_matching);
    } while (std::next_permutation(partition_Y.begin(), partition_Y.end()));

    return all_matchings;
}

/**
 * @brief Helper function to print the list of matchings.
 */
void print_matchings(const std::vector<Matching>& all_matchings, int p, int q) {
    std::cout << "--- Found " << all_matchings.size() << " perfect matchings for K_" 
              << p << "," << q << " ---" << std::endl;
    if (all_matchings.empty() && p != q) {
        std::cout << "  (As expected, no perfect matching exists since p != q)" << std::endl;
    } else {
        int count = 1;
        for (const auto& matching : all_matchings) {
            std::cout << "  Matching " << count++ << ": { ";
            for (const auto& edge : matching) {
                std::cout << "(x" << edge.first << ", y" << edge.second << ") ";
            }
            std::cout << "}" << std::endl;
        }
    }
    std::cout << "------------------------------------------" << std::endl;
}

// =================================================================================
// MAIN FUNCTION - DEMONSTRATION FOR EXERCISE 1.6
// =================================================================================
int main() {
    std::cout << "=====================================================" << std::endl;
    std::cout << " Perfect Matching Enumeration Demo (Exercise 1.6)    " << std::endl;
    std::cout << "=====================================================" << std::endl;

    // --- Case 1: p = q, perfect matchings exist ---
    int p1 = 3, q1 = 3;
    std::vector<Matching> matchings1 = enumerate_perfect_matchings_cpp(p1, q1);
    print_matchings(matchings1, p1, q1);

    // --- Case 2: p != q, no perfect matchings ---
    int p2 = 3, q2 = 2;
    std::vector<Matching> matchings2 = enumerate_perfect_matchings_cpp(p2, q2);
    print_matchings(matchings2, p2, q2);
    
    // --- Case 3: p = q = 0, edge case ---
    int p3 = 0, q3 = 0;
    std::vector<Matching> matchings3 = enumerate_perfect_matchings_cpp(p3, q3);
    print_matchings(matchings3, p3, q3);

    std::cout << "=====================================================" << std::endl;

    return 0;
}