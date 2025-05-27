#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform list scheduling and return the makespan
double listScheduling(int m, int n, vector<double>& processingTimes, vector<vector<int>>& machineJobs) {
    // Vector to store the current load (completion time) of each machine
    vector<double> machineLoad(m, 0.0);
    
    // Clear the machineJobs vector to store job assignments
    for (int i = 0; i < m; i++) {
        machineJobs[i].clear();
    }
    
    // Assign each job to the machine with the minimum current load
    for (int j = 0; j < n; j++) {
        // Find the machine with the minimum load
        int minLoadMachine = 0;
        double minLoad = machineLoad[0];
        for (int i = 1; i < m; i++) {
            if (machineLoad[i] < minLoad) {
                minLoad = machineLoad[i];
                minLoadMachine = i;
            }
        }
        
        // Assign job j to the machine with minimum load
        machineJobs[minLoadMachine].push_back(j);
        machineLoad[minLoadMachine] += processingTimes[j];
    }
    
    // Find the makespan (maximum load across all machines)
    double makespan = *max_element(machineLoad.begin(), machineLoad.end());
    return makespan;
}

int main() {
    int m, n;
    
    // Input number of machines and jobs
    cout << "Enter number of machines (m): ";
    cin >> m;
    cout << "Enter number of jobs (n): ";
    cin >> n;
    
    // Input processing times for each job
    vector<double> processingTimes(n);
    cout << "Enter processing times for " << n << " jobs:\n";
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << ": ";
        cin >> processingTimes[i];
    }
    
    // Vector to store which jobs are assigned to each machine
    vector<vector<int>> machineJobs(m);
    
    // Run list scheduling algorithm
    double makespan = listScheduling(m, n, processingTimes, machineJobs);
    
    // Output the job assignments
    cout << "\nJob assignments:\n";
    for (int i = 0; i < m; i++) {
        cout << "Machine " << i + 1 << ": ";
        for (int job : machineJobs[i]) {
            cout << "Job " << job + 1 << " (" << processingTimes[job] << ") ";
        }
        cout << "\n";
    }
    
    // Output the makespan
    cout << "\nMakespan: " << makespan << "\n";
    
    return 0;
}