#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

namespace SelfConjugatePartitions {
    
    /**
     * @brief Check if a partition is self-conjugate (equals its transpose)
     * @param partitionParts Vector of partition parts in non-increasing order
     * @return True if partition is self-conjugate, false otherwise
     */
    bool validateSelfConjugateProperty(const std::vector<int>& partitionParts) {
        int numberOfParts = static_cast<int>(partitionParts.size());
        std::vector<int> conjugateForm;
        int maximumPart = 0;
        
        for (int currentPart : partitionParts) {
            maximumPart = std::max(maximumPart, currentPart);
        }
        
        for (int rowIndex = 1; rowIndex <= maximumPart; ++rowIndex) {
            int columnCount = 0;
            for (int partValue : partitionParts) {
                if (partValue >= rowIndex) {
                    ++columnCount;
                } else {
                    break;
                }
            }
            conjugateForm.push_back(columnCount);
        }
        
        if (static_cast<int>(conjugateForm.size()) != numberOfParts) {
            return false;
        }
        
        for (int index = 0; index < numberOfParts; ++index) {
            if (partitionParts[index] != conjugateForm[index]) {
                return false;
            }
        }
        
        return true;
    }
    
    /**
     * @brief Recursive approach with memoization for counting self-conjugate partitions
     * @param targetNumber Number to partition
     * @param exactParts Exact number of parts required
     * @param memoizationTable Table for storing computed results
     * @return Number of self-conjugate partitions of targetNumber with exactParts parts
     */
    int calculateRecursiveWithMemoization(int targetNumber, 
                                         int exactParts, 
                                         std::map<std::pair<int, int>, int>& memoizationTable) {
        if (targetNumber == 0 && exactParts == 0) {
            return 1;
        }
        if (targetNumber < 0 || exactParts <= 0) {
            return 0;
        }
        if (exactParts > targetNumber) {
            return 0;
        }
        
        std::pair<int, int> memoKey = {targetNumber, exactParts};
        if (memoizationTable.count(memoKey)) {
            return memoizationTable[memoKey];
        }
        
        int validPartitionsCount = 0;
        std::vector<int> currentPartition;
        
        std::function<void(int, int, int)> generatePartitions = 
            [&](int remainingSum, int remainingParts, int maximumValue) {
                if (remainingParts == 0 && remainingSum == 0) {
                    std::vector<int> temporaryPartition = currentPartition;
                    std::sort(temporaryPartition.rbegin(), temporaryPartition.rend());
                    
                    if (static_cast<int>(temporaryPartition.size()) == exactParts && 
                        validateSelfConjugateProperty(temporaryPartition)) {
                        ++validPartitionsCount;
                    }
                    return;
                }
                
                if (remainingParts <= 0 || remainingSum <= 0) {
                    return;
                }
                
                for (int candidateValue = std::min(maximumValue, remainingSum); candidateValue >= 1; --candidateValue) {
                    currentPartition.push_back(candidateValue);
                    generatePartitions(remainingSum - candidateValue, remainingParts - 1, candidateValue);
                    currentPartition.pop_back();
                }
            };
        
        generatePartitions(targetNumber, exactParts, targetNumber);
        return memoizationTable[memoKey] = validPartitionsCount;
    }
    
    /**
     * @brief Dynamic programming approach for counting self-conjugate partitions
     * @param targetNumber Number to partition
     * @param exactParts Exact number of parts required
     * @return Number of self-conjugate partitions of targetNumber with exactParts parts
     */
    int calculateDynamicProgramming(int targetNumber, int exactParts) {
        if (targetNumber == 0 && exactParts == 0) {
            return 1;
        }
        if (targetNumber < 0 || exactParts <= 0) {
            return 0;
        }
        if (exactParts > targetNumber) {
            return 0;
        }
        
        std::vector<std::vector<int>> dpTable(targetNumber + 1, std::vector<int>(exactParts + 1, 0));
        dpTable[0][0] = 1;
        
        for (int currentSum = 1; currentSum <= targetNumber; ++currentSum) {
            for (int currentParts = 1; currentParts <= std::min(currentSum, exactParts); ++currentParts) {
                int validCount = 0;
                std::vector<int> workingPartition;
                
                std::function<void(int, int, int)> generateValidPartitions = 
                    [&](int remainingSum, int remainingPartsCount, int maximumAllowed) {
                        if (remainingPartsCount == 0 && remainingSum == 0) {
                            std::vector<int> partitionCopy = workingPartition;
                            std::sort(partitionCopy.rbegin(), partitionCopy.rend());
                            
                            if (static_cast<int>(partitionCopy.size()) == currentParts && 
                                validateSelfConjugateProperty(partitionCopy)) {
                                ++validCount;
                            }
                            return;
                        }
                        
                        if (remainingPartsCount <= 0 || remainingSum <= 0) {
                            return;
                        }
                        
                        for (int nextValue = std::min(maximumAllowed, remainingSum); nextValue >= 1; --nextValue) {
                            workingPartition.push_back(nextValue);
                            generateValidPartitions(remainingSum - nextValue, remainingPartsCount - 1, nextValue);
                            workingPartition.pop_back();
                        }
                    };
                
                generateValidPartitions(currentSum, currentParts, currentSum);
                dpTable[currentSum][currentParts] = validCount;
            }
        }
        
        return dpTable[targetNumber][exactParts];
    }
    
    /**
     * @brief Read input parameters from file
     * @param fileName Input file name
     * @return Pair of (n, k) values
     */
    std::pair<int, int> loadParametersFromFile(const std::string& fileName) {
        std::ifstream inputFile(fileName);
        if (!inputFile.is_open()) {
            std::cerr << "Error: Cannot open file " << fileName << std::endl;
            exit(1);
        }
        
        int targetNumber, exactParts;
        inputFile >> targetNumber >> exactParts;
        inputFile.close();
        
        return {targetNumber, exactParts};
    }
    
    /**
     * @brief Display computation results with formatted output
     * @param targetNumber The number being partitioned
     * @param exactParts The exact number of parts required
     * @param recursiveResult Result from recursive approach
     * @param dpResult Result from dynamic programming approach
     */
    void presentComputationResults(int targetNumber, 
                                  int exactParts, 
                                  int recursiveResult, 
                                  int dpResult) {
        std::cout << "Self-conjugate partitions of " << targetNumber 
                  << " with " << exactParts << " parts (Recursive): " << recursiveResult << std::endl;
        std::cout << "Self-conjugate partitions of " << targetNumber 
                  << " with " << exactParts << " parts (Dynamic Programming): " << dpResult << std::endl;
    }
    
} // namespace SelfConjugatePartitions

/**
 * @brief Main program entry point
 * @return Program exit status
 */
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    const std::string INPUT_FILE_NAME = "input.txt";
    
    std::pair<int, int> parameters = SelfConjugatePartitions::loadParametersFromFile(INPUT_FILE_NAME);
    int targetNumber = parameters.first;
    int exactParts = parameters.second;
    
    // Clear memoization and compute using recursive approach
    std::map<std::pair<int, int>, int> memoizationCache;
    int recursiveResult = SelfConjugatePartitions::calculateRecursiveWithMemoization(
        targetNumber, exactParts, memoizationCache
    );
    
    // Compute using dynamic programming approach
    int dynamicProgrammingResult = SelfConjugatePartitions::calculateDynamicProgramming(
        targetNumber, exactParts
    );
    
    // Display results
    SelfConjugatePartitions::presentComputationResults(
        targetNumber, exactParts, recursiveResult, dynamicProgrammingResult
    );
    
    return 0;
} 