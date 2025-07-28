#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

namespace PartitionAnalysis {
    
    /**
     * @brief Structure to hold partition analysis results
     */
    struct PartitionResults {
        std::vector<std::vector<int>> selfConjugateList;
        std::vector<std::vector<int>> oddPartsOnlyList;
        std::vector<std::vector<int>> distinctOddPartsList;
        int totalSelfConjugate;
        int totalOddParts;
        int totalDistinctOdd;
    };
    
    /**
     * @brief Check if a given partition equals its conjugate (transpose)
     * @param partitionElements Vector containing partition elements
     * @return True if partition is self-conjugate, false otherwise
     */
    bool checkIfPartitionIsSelfConjugate(const std::vector<int>& partitionElements) {
        int numberOfParts = static_cast<int>(partitionElements.size());
        std::vector<int> conjugateForm(numberOfParts, 0);
        
        for (int i = 0; i < numberOfParts; ++i) {
            for (int j = 0; j < numberOfParts && partitionElements[j] >= i + 1; ++j) {
                ++conjugateForm[i];
            }
        }
        
        for (int index = 0; index < numberOfParts; ++index) {
            if (partitionElements[index] != conjugateForm[index]) {
                return false;
            }
        }
        return true;
    }
    
    /**
     * @brief Generate partitions of specified number with exact part count
     * @param targetSum Sum to achieve
     * @param requiredParts Number of parts needed
     * @param maxAllowedValue Maximum value for next part
     * @param workingPartition Current partition being constructed
     * @param foundPartitions Container for valid partitions
     */
    void findPartitionsWithFixedSize(int targetSum, 
                                    int requiredParts, 
                                    int maxAllowedValue,
                                    std::vector<int>& workingPartition,
                                    std::vector<std::vector<int>>& foundPartitions) {
        if (requiredParts == 0 && targetSum == 0) {
            if (checkIfPartitionIsSelfConjugate(workingPartition)) {
                foundPartitions.push_back(workingPartition);
            }
            return;
        }
        if (requiredParts <= 0 || targetSum <= 0) {
            return;
        }
        
        for (int candidateValue = std::min(maxAllowedValue, targetSum); candidateValue >= 1; --candidateValue) {
            workingPartition.push_back(candidateValue);
            findPartitionsWithFixedSize(targetSum - candidateValue, requiredParts - 1, candidateValue, workingPartition, foundPartitions);
            workingPartition.pop_back();
        }
    }
    
    /**
     * @brief Discover all self-conjugate partitions for given number
     * @param inputNumber Number to partition
     * @return Vector containing all self-conjugate partitions
     */
    std::vector<std::vector<int>> discoverSelfConjugatePartitions(int inputNumber) {
        std::vector<std::vector<int>> resultCollection;
        std::vector<int> temporaryPartition;
        
        for (int sizeLimit = 1; sizeLimit <= inputNumber; ++sizeLimit) {
            findPartitionsWithFixedSize(inputNumber, sizeLimit, inputNumber, temporaryPartition, resultCollection);
        }
        
        return resultCollection;
    }
    
    /**
     * @brief Generate partitions using only odd numbers (repetition allowed)
     * @param remainingValue Remaining sum to partition
     * @param minimumOdd Smallest odd number to use
     * @param buildingPartition Partition under construction
     * @param collectedPartitions Storage for valid partitions
     */
    void constructOddNumberPartitions(int remainingValue,
                                     int minimumOdd,
                                     std::vector<int>& buildingPartition,
                                     std::vector<std::vector<int>>& collectedPartitions) {
        if (remainingValue == 0) {
            collectedPartitions.push_back(buildingPartition);
            return;
        }
        if (remainingValue < 0) {
            return;
        }
        
        for (int oddCandidate = minimumOdd; oddCandidate <= remainingValue; oddCandidate += 2) {
            buildingPartition.push_back(oddCandidate);
            constructOddNumberPartitions(remainingValue - oddCandidate, oddCandidate, buildingPartition, collectedPartitions);
            buildingPartition.pop_back();
        }
    }
    
    /**
     * @brief Create partitions using distinct odd numbers only
     * @param remainingSum Sum left to achieve
     * @param nextOddStart Next odd number to consider
     * @param currentPartition Partition being built
     * @param resultStorage Container for completed partitions
     */
    void buildDistinctOddPartitions(int remainingSum,
                                   int nextOddStart,
                                   std::vector<int>& currentPartition,
                                   std::vector<std::vector<int>>& resultStorage) {
        if (remainingSum == 0) {
            resultStorage.push_back(currentPartition);
            return;
        }
        if (remainingSum < 0) {
            return;
        }
        
        for (int oddValue = nextOddStart; oddValue <= remainingSum; oddValue += 2) {
            currentPartition.push_back(oddValue);
            buildDistinctOddPartitions(remainingSum - oddValue, oddValue + 2, currentPartition, resultStorage);
            currentPartition.pop_back();
        }
    }
    
    /**
     * @brief Load target number from input file
     * @param fileName Name of input file
     * @return Integer value from file
     */
    int loadNumberFromFile(const std::string& fileName) {
        std::ifstream dataFile(fileName);
        if (!dataFile.is_open()) {
            std::cerr << "Error: Unable to open file " << fileName << std::endl;
            exit(1);
        }
        
        int targetValue;
        dataFile >> targetValue;
        dataFile.close();
        
        return targetValue;
    }
    
    /**
     * @brief Display a partition in readable format
     * @param partitionData The partition to display
     */
    void displayFormattedPartition(const std::vector<int>& partitionData) {
        for (int position = 0; position < static_cast<int>(partitionData.size()); ++position) {
            std::cout << partitionData[position];
            if (position < static_cast<int>(partitionData.size()) - 1) {
                std::cout << " + ";
            }
        }
        std::cout << std::endl;
    }
    
    /**
     * @brief Organize partitions for consistent display
     * @param partitionsList Collection of partitions to sort
     */
    void organizePartitionsForDisplay(std::vector<std::vector<int>>& partitionsList) {
        for (auto& singlePartition : partitionsList) {
            std::sort(singlePartition.rbegin(), singlePartition.rend());
        }
        std::sort(partitionsList.begin(), partitionsList.end());
    }
    
    /**
     * @brief Perform comprehensive partition analysis
     * @param analysisNumber Number to analyze
     * @return Complete analysis results
     */
    PartitionResults executeCompleteAnalysis(int analysisNumber) {
        PartitionResults analysisResults;
        std::vector<int> helperPartition;
        
        // Analyze self-conjugate partitions
        analysisResults.selfConjugateList = discoverSelfConjugatePartitions(analysisNumber);
        analysisResults.totalSelfConjugate = static_cast<int>(analysisResults.selfConjugateList.size());
        
        // Analyze odd-only partitions
        constructOddNumberPartitions(analysisNumber, 1, helperPartition, analysisResults.oddPartsOnlyList);
        organizePartitionsForDisplay(analysisResults.oddPartsOnlyList);
        analysisResults.totalOddParts = static_cast<int>(analysisResults.oddPartsOnlyList.size());
        
        // Analyze distinct odd partitions
        helperPartition.clear();
        buildDistinctOddPartitions(analysisNumber, 1, helperPartition, analysisResults.distinctOddPartsList);
        organizePartitionsForDisplay(analysisResults.distinctOddPartsList);
        analysisResults.totalDistinctOdd = static_cast<int>(analysisResults.distinctOddPartsList.size());
        
        return analysisResults;
    }
    
    /**
     * @brief Present analysis results to user
     * @param targetNumber Number being analyzed
     * @param results Complete analysis results
     */
    void presentAnalysisResults(int targetNumber, const PartitionResults& results) {
        std::cout << targetNumber << std::endl << std::endl;
        
        // Display self-conjugate partitions
        std::cout << "Total self-conjugate partitions of " << targetNumber 
                  << ": " << results.totalSelfConjugate << std::endl;
        for (const auto& partition : results.selfConjugateList) {
            displayFormattedPartition(partition);
        }
        std::cout << std::endl;
        
        // Display odd-parts partitions
        std::cout << "Partitions of " << targetNumber 
                  << " using odd parts: " << results.totalOddParts << std::endl;
        for (const auto& partition : results.oddPartsOnlyList) {
            displayFormattedPartition(partition);
        }
        std::cout << std::endl;
        
        // Display distinct odd partitions
        std::cout << "Partitions of " << targetNumber 
                  << " into distinct odd parts: " << results.totalDistinctOdd << std::endl;
        for (const auto& partition : results.distinctOddPartsList) {
            displayFormattedPartition(partition);
        }
        std::cout << std::endl;
        
    
        if (results.totalSelfConjugate == results.totalDistinctOdd) {
            std::cout << "Self-conjugate partitions count = Distinct odd parts count" << std::endl;
        } else {
            std::cout << "=> Counts are DIFFERENT" << std::endl;
        }
    }
    
} // namespace PartitionAnalysis

/**
 * @brief Main program entry point
 * @return Program exit status
 */
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    const std::string INPUT_FILE_NAME = "input.txt";
    
    int numberToAnalyze = PartitionAnalysis::loadNumberFromFile(INPUT_FILE_NAME);
    
    if (numberToAnalyze < 0) {
        std::cout << "Input must be a non-negative integer." << std::endl;
        return 1;
    }
    
    PartitionAnalysis::PartitionResults analysisOutcome = 
        PartitionAnalysis::executeCompleteAnalysis(numberToAnalyze);
    
    PartitionAnalysis::presentAnalysisResults(numberToAnalyze, analysisOutcome);
    
    return 0;
} 