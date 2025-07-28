#include <vector>
#include <utility> // For std::pair
#include <iostream> // For std::cout, std::endl
#include <functional> // For std::function (optional, if using lambda for recursion)

// Forward declaration for the recursive helper function
void findPerfectMatchingsRecursive(
    int l_idx,                                    // Current left vertex (absolute ID) to match
    int n,                                        // Size of each partition (p or q)
    std::vector<std::pair<int, int>>& currentMatching, // Edges for the current matching
    std::vector<bool>& usedRightVertices,         // Tracks if right vertices (relative index) are used
    std::vector<std::vector<std::pair<int, int>>>& allMatchings // Stores all found perfect matchings
);

/**
 * @brief Enumerates all perfect matchings in a complete bipartite graph K_p,q.
 * A perfect matching exists only if p == q.
 *
 * @param p Number of vertices in the first partition.
 * @param q Number of vertices in the second partition.
 * @return A vector of vectors, where each inner vector represents a perfect matching
 * as a list of (source, target) edge pairs.
 * Left vertices are 0 to p-1.
 * Right vertices are p to p+q-1.
 */
std::vector<std::vector<std::pair<int, int>>> enumeratePerfectMatchingsKpq(int p, int q) {
    std::vector<std::vector<std::pair<int, int>>> allMatchings;

    // Perfect matching requires equal partition sizes
    if (p != q) {
        return allMatchings; // No perfect matching if p != q
    }

    int n = p; // Since p == q, n represents the size of each partition

    std::vector<std::pair<int, int>> currentMatching;
    // usedRightVertices tracks if a vertex in the RIGHT partition (relative index 0 to n-1) is used
    std::vector<bool> usedRightVertices(n, false); 

    // Start the recursive process from the first vertex in the left partition (index 0)
    findPerfectMatchingsRecursive(0, n, currentMatching, usedRightVertices, allMatchings);
    return allMatchings;
}

/**
 * @brief Recursive helper function to find perfect matchings.
 *
 * @param l_idx Current left vertex (absolute ID) to match.
 * @param n Size of each partition.
 * @param currentMatching Reference to the vector storing the current matching being built.
 * @param usedRightVertices Reference to the boolean vector tracking used right vertices.
 * @param allMatchings Reference to the vector storing all found perfect matchings.
 */
void findPerfectMatchingsRecursive(
    int l_idx, 
    int n, 
    std::vector<std::pair<int, int>>& currentMatching, 
    std::vector<bool>& usedRightVertices, 
    std::vector<std::vector<std::pair<int, int>>>& allMatchings
) {
    // Base case: If all left vertices have been matched, a perfect matching is found
    if (l_idx == n) {
        allMatchings.push_back(currentMatching); // Add a copy of the current matching
        return;
    }

    // Iterate through all vertices in the right partition to find a match for L[l_idx]
    for (int r_relative_idx = 0; r_relative_idx < n; ++r_relative_idx) {
        // If the current right vertex is not yet used
        if (!usedRightVertices[r_relative_idx]) {
            usedRightVertices[r_relative_idx] = true; // Mark as used
            
            // Form the edge using absolute vertex IDs
            // Left vertex ID is l_idx
            // Right vertex ID is (n + r_relative_idx) because right partition starts after left
            std::pair<int, int> edge = {l_idx, n + r_relative_idx}; 
            currentMatching.push_back(edge);

            // Recursively call for the next left vertex
            findPerfectMatchingsRecursive(l_idx + 1, n, currentMatching, usedRightVertices, allMatchings);

            // Backtrack: Undo the choice for the current L[l_idx]
            currentMatching.pop_back();
            usedRightVertices[r_relative_idx] = false;
        }
    }
}

int main() {
    // Example 1: K_3,3 (expect 3! = 6 perfect matchings)
    int p1 = 3;
    int q1 = 3;
    std::cout << "Enumerating perfect matchings for K_" << p1 << "," << q1 << ":" << std::endl;
    std::vector<std::vector<std::pair<int, int>>> matchings1 = enumeratePerfectMatchingsKpq(p1, q1);
    if (matchings1.empty()) {
        std::cout << "No perfect matchings found." << std::endl;
    } else {
        for (size_t i = 0; i < matchings1.size(); ++i) {
            std::cout << "  Matching " << i + 1 << ": {";
            for (size_t j = 0; j < matchings1[i].size(); ++j) {
                std::cout << "(" << matchings1[i][j].first << "," << matchings1[i][j].second << ")";
                if (j < matchings1[i].size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "}" << std::endl;
        }
        std::cout << "Total perfect matchings: " << matchings1.size() << "\n" << std::endl;
    }

    // Example 2: K_2,2 (expect 2! = 2 perfect matchings)
    int p2 = 2;
    int q2 = 2;
    std::cout << "Enumerating perfect matchings for K_" << p2 << "," << q2 << ":" << std::endl;
    std::vector<std::vector<std::pair<int, int>>> matchings2 = enumeratePerfectMatchingsKpq(p2, q2);
    if (matchings2.empty()) {
        std::cout << "No perfect matchings found." << std::endl;
    } else {
        for (size_t i = 0; i < matchings2.size(); ++i) {
            std::cout << "  Matching " << i + 1 << ": {";
            for (size_t j = 0; j < matchings2[i].size(); ++j) {
                std::cout << "(" << matchings2[i][j].first << "," << matchings2[i][j].second << ")";
                if (j < matchings2[i].size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "}" << std::endl;
        }
        std::cout << "Total perfect matchings: " << matchings2.size() << "\n" << std::endl;
    }

    // Example 3: K_2,3 (expect 0 perfect matchings)
    int p3 = 2;
    int q3 = 3;
    std::cout << "Enumerating perfect matchings for K_" << p3 << "," << q3 << ":" << std::endl;
    std::vector<std::vector<std::pair<int, int>>> matchings3 = enumeratePerfectMatchingsKpq(p3, q3);
    if (matchings3.empty()) {
        std::cout << "No perfect matchings found." << std::endl;
    } else {
        for (size_t i = 0; i < matchings3.size(); ++i) {
            std::cout << "  Matching " << i + 1 << ": {";
            for (size_t j = 0; j < matchings3[i].size(); ++j) {
                std::cout << "(" << matchings3[i][j].first << "," << matchings3[i][j].second << ")";
                if (j < matchings3[i].size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "}" << std::endl;
        }
        std::cout << "Total perfect matchings: " << matchings3.size() << "\n" << std::endl;
    }

    // Example 4: K_0,0 (expect 1 perfect matching - empty set)
    int p4 = 0;
    int q4 = 0;
    std::cout << "Enumerating perfect matchings for K_" << p4 << "," << q4 << ":" << std::endl;
    std::vector<std::vector<std::pair<int, int>>> matchings4 = enumeratePerfectMatchingsKpq(p4, q4);
    if (matchings4.empty()) {
        std::cout << "No perfect matchings found." << std::endl;
    } else {
        for (size_t i = 0; i < matchings4.size(); ++i) {
            std::cout << "  Matching " << i + 1 << ": {";
            for (size_t j = 0; j < matchings4[i].size(); ++j) {
                std::cout << "(" << matchings4[i][j].first << "," << matchings4[i][j].second << ")";
                if (j < matchings4[i].size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "}" << std::endl;
        }
        std::cout << "Total perfect matchings: " << matchings4.size() << "\n" << std::endl;
    }

    return 0;
}