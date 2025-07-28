/**
 * @file ferreries_diagram.cpp
 * @brief Generates and displays Ferrers diagrams for integer partitions
 * @details Implements partition generation and Ferrers diagram visualization
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Represents a partition of an integer with associated operations
 */
class Partition {
private:
    vector<int> partitionElements;
    
public:
    /**
     * @brief Constructs an empty partition
     */
    Partition() = default;
    
    /**
     * @brief Constructs a partition from vector of integers
     * @param elements Vector containing partition elements
     */
    explicit Partition(const vector<int>& elements) : partitionElements(elements) {}
    
    /**
     * @brief Adds an element to the partition
     * @param value Value to add
     */
    void addElement(int value) {
        partitionElements.push_back(value);
    }
    
    /**
     * @brief Removes the last element from partition
     */
    void removeLastElement() {
        if (!partitionElements.empty()) {
            partitionElements.pop_back();
        }
    }
    
    /**
     * @brief Gets the partition elements
     * @return Const reference to partition elements
     */
    const vector<int>& getElements() const {
        return partitionElements;
    }
    
    /**
     * @brief Gets the size of the partition
     * @return Number of elements in partition
     */
    size_t getSize() const {
        return partitionElements.size();
    }
    
    /**
     * @brief Checks if partition is empty
     * @return True if partition has no elements
     */
    bool isEmpty() const {
        return partitionElements.empty();
    }
    
    /**
     * @brief Finds the maximum value in the partition
     * @return Maximum value, or 0 if empty
     */
    int findMaximumValue() const {
        if (partitionElements.empty()) {
            return 0;
        }
        return *max_element(partitionElements.begin(), partitionElements.end());
    }
    
    /**
     * @brief Calculates the sum of all partition elements
     * @return Sum of elements
     */
    int calculateSum() const {
        return accumulate(partitionElements.begin(), partitionElements.end(), 0);
    }
};

/**
 * @brief Handles input operations for partition generation
 */
class FileInputHandler {
private:
    string fileName;
    
public:
    /**
     * @brief Constructs input handler with file name
     * @param inputFileName Name of input file
     */
    explicit FileInputHandler(const string& inputFileName) : fileName(inputFileName) {}
    
    /**
     * @brief Reads partition parameters from file
     * @param targetSum Reference to store target sum
     * @param numberOfParts Reference to store number of parts
     * @return True if reading was successful
     */
    bool readPartitionParameters(int& targetSum, int& numberOfParts) const {
        ifstream inputFile(fileName);
        if (!inputFile.is_open()) {
            cerr << "Error: Cannot open " << fileName << " file\n";
            return false;
        }
        
        inputFile >> targetSum >> numberOfParts;
        
        if (inputFile.fail()) {
            cerr << "Error: Failed to read parameters from " << fileName << "\n";
            return false;
        }
        
        return true;
    }
};

/**
 * @brief Handles display operations for Ferrers diagrams
 */
class FerrersDisplay {
private:
    ostream& outputStream;
    
    /**
     * @brief Displays a single row of the Ferrers diagram
     * @param rowLength Number of stars in the row
     * @param totalWidth Total width for alignment
     */
    void displayFerrersRow(int rowLength, int totalWidth) const {
        for (int i = 0; i < rowLength; ++i) {
            outputStream << '*';
        }
        for (int i = 0; i < totalWidth - rowLength; ++i) {
            outputStream << ' ';
        }
        outputStream << ' ' << rowLength << '\n';
    }
    
    /**
     * @brief Displays a single row of the transposed Ferrers diagram
     * @param rowIndex Current row index
     * @param partition Partition to display
     */
    void displayTransposeRow(int rowIndex, const Partition& partition) const {
        const auto& elements = partition.getElements();
        for (size_t i = 0; i < elements.size(); ++i) {
            if (elements[i] > rowIndex) {
                outputStream << '*';
            } else {
                outputStream << ' ';
            }
            if (i < elements.size() - 1) {
                outputStream << ' ';
            }
        }
        outputStream << '\n';
    }
    
    /**
     * @brief Displays the partition values as footer
     * @param partition Partition to display
     */
    void displayPartitionValues(const Partition& partition) const {
        const auto& elements = partition.getElements();
        for (size_t i = 0; i < elements.size(); ++i) {
            outputStream << elements[i];
            if (i < elements.size() - 1) {
                outputStream << ' ';
            }
        }
        outputStream << '\n';
    }
    
public:
    /**
     * @brief Constructs display handler with output stream
     * @param output Output stream for display
     */
    explicit FerrersDisplay(ostream& output) : outputStream(output) {}
    
    /**
     * @brief Displays the standard Ferrers diagram
     * @param partition Partition to display
     */
    void displayFerrers(const Partition& partition) const {
        outputStream << "F:\n";
        int maximumValue = partition.findMaximumValue();
        const auto& elements = partition.getElements();
        
        for (int rowLength : elements) {
            displayFerrersRow(rowLength, maximumValue);
        }
    }
    
    /**
     * @brief Displays the transposed Ferrers diagram
     * @param partition Partition to display
     */
    void displayFerrersTranspose(const Partition& partition) const {
        outputStream << "FT:\n";
        int maximumValue = partition.findMaximumValue();
        
        for (int rowIndex = 0; rowIndex < maximumValue; ++rowIndex) {
            displayTransposeRow(rowIndex, partition);
        }
        displayPartitionValues(partition);
    }
    
    /**
     * @brief Displays separator between partitions
     */
    void displaySeparator() const {
        outputStream << "====================\n";
    }
    
    /**
     * @brief Displays program header
     * @param targetSum Target sum for partitions
     * @param numberOfParts Number of parts in each partition
     */
    void displayHeader(int targetSum, int numberOfParts) const {
        outputStream << "Generating all partitions of " << targetSum 
                    << " into exactly " << numberOfParts << " parts:\n";
        displaySeparator();
    }
    
    /**
     * @brief Displays program completion message
     */
    void displayCompletion() const {
        outputStream << "Done.\n";
    }
};

/**
 * @brief Generates integer partitions with specified constraints
 */
class PartitionGenerator {
private:
    unique_ptr<FerrersDisplay> displayHandler;
    
    /**
     * @brief Recursively generates partitions
     * @param remainingSum Remaining sum to partition
     * @param remainingParts Remaining parts to generate
     * @param currentPartition Current partition being built
     * @param maximumValue Maximum value allowed for next part
     */
    void generatePartitionsRecursive(int remainingSum, int remainingParts, 
                                   Partition& currentPartition, int maximumValue) {
        if (remainingParts == 0) {
            if (remainingSum == 0) {
                displayCompletePartition(currentPartition);
            }
            return;
        }
        
        int upperLimit = min(remainingSum, maximumValue);
        for (int value = upperLimit; value >= 1; --value) {
            currentPartition.addElement(value);
            generatePartitionsRecursive(remainingSum - value, remainingParts - 1, 
                                      currentPartition, value);
            currentPartition.removeLastElement();
        }
    }
    
    /**
     * @brief Displays a complete partition with both diagrams
     * @param partition Complete partition to display
     */
    void displayCompletePartition(const Partition& partition) const {
        displayHandler->displayFerrers(partition);
        displayHandler->displayFerrersTranspose(partition);
        displayHandler->displaySeparator();
    }
    
public:
    /**
     * @brief Constructs partition generator with display handler
     * @param handler Display handler for output
     */
    explicit PartitionGenerator(unique_ptr<FerrersDisplay> handler) 
        : displayHandler(move(handler)) {}
    
    /**
     * @brief Generates all partitions with specified parameters
     * @param targetSum Target sum for partitions
     * @param numberOfParts Number of parts in each partition
     */
    void generateAllPartitions(int targetSum, int numberOfParts) {
        displayHandler->displayHeader(targetSum, numberOfParts);
        
        Partition currentPartition;
        generatePartitionsRecursive(targetSum, numberOfParts, currentPartition, targetSum);
        
        displayHandler->displayCompletion();
    }
};

/**
 * @brief Coordinates the Ferrers diagram application workflow
 */
class FerrersApplication {
private:
    unique_ptr<FileInputHandler> inputHandler;
    unique_ptr<PartitionGenerator> partitionGenerator;
    
public:
    /**
     * @brief Constructs the application with necessary components
     * @param inputFileName Name of input file
     * @param outputStream Output stream for results
     */
    FerrersApplication(const string& inputFileName, ostream& outputStream) {
        inputHandler = make_unique<FileInputHandler>(inputFileName);
        auto displayHandler = make_unique<FerrersDisplay>(outputStream);
        partitionGenerator = make_unique<PartitionGenerator>(move(displayHandler));
    }
    
    /**
     * @brief Executes the complete application workflow
     * @return Exit status (0 for success, 1 for error)
     */
    int executeApplication() {
        int targetSum, numberOfParts;
        
        if (!inputHandler->readPartitionParameters(targetSum, numberOfParts)) {
            return 1;
        }
        
        partitionGenerator->generateAllPartitions(targetSum, numberOfParts);
        return 0;
    }
};

/**
 * @brief Main program entry point
 * @return Program exit status
 */
int main() {
    try {
        FerrersApplication application("input.txt", cout);
        return application.executeApplication();
    } catch (const exception& error) {
        cerr << "Error occurred: " << error.what() << "\n";
        return 1;
    }
}