// C++ code for graph neural network for job shop scheduling problem
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
using namespace std;

// Simple matrix multiplication function
vector<vector<double>> matrix_multiply(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int rows = A.size();
    int cols = B[0].size();
    int inner = B.size();
    vector<vector<double>> C(rows, vector<double>(cols, 0.0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < inner; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// ReLU activation
void relu(vector<vector<double>>& mat) {
    for (auto& row : mat) {
        for (auto& val : row) {
            val = max(0.0, val);
        }
    }
}

// Class for Graph representation
class Graph {
public:
    int num_nodes;
    vector<vector<int>> adj; // Adjacency list
    vector<vector<double>> features; // Node features (n x f)

    Graph(int n, int f) : num_nodes(n), adj(n), features(n, vector<double>(f, 0.0)) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected for simplicity
    }
};

// Simple GNN Layer (Graph Convolution)
vector<vector<double>> gnn_layer(const Graph& graph, const vector<vector<double>>& weights) {
    // Assume weights is f x f' (feature transformation)
    int n = graph.num_nodes;
    int f_new = weights[0].size();

    vector<vector<double>> new_features(n, vector<double>(f_new, 0.0));

    // Message passing: aggregate from neighbors and self
    for (int i = 0; i < n; ++i) {
        vector<double> agg(graph.features[0].size(), 0.0);

        // Self
        for (size_t d = 0; d < graph.features[0].size(); ++d) {
            agg[d] += graph.features[i][d];
        }

        // Neighbors
        for (int neigh : graph.adj[i]) {
            for (size_t d = 0; d < graph.features[0].size(); ++d) {
                agg[d] += graph.features[neigh][d];
            }
        }

        // Normalize by degree +1 (self-loop)
        int degree = graph.adj[i].size() + 1;
        for (auto& val : agg) {
            val /= degree;
        }

        // Transform with weights
        vector<vector<double>> agg_mat(1, agg); // 1 x f
        auto transformed = matrix_multiply(agg_mat, weights); // 1 x f'

        new_features[i] = transformed[0];
    }

    relu(new_features);
    return new_features;
}

// Function to create a disjunctive graph for a small JSSP instance
Graph create_jssp_graph() {
    // Example: 2 jobs, 2 machines
    // Operations: 0: Job1 Op1 on M1 p=3, 1: Job1 Op2 on M2 p=2
    //             2: Job2 Op1 on M2 p=4, 3: Job2 Op2 on M1 p=1
    // Features: [processing_time, job_id, machine_id]

    Graph g(4, 3); // 4 nodes, 3 features

    // Set features
    g.features[0] = {3.0, 1.0, 1.0};
    g.features[1] = {2.0, 1.0, 2.0};
    g.features[2] = {4.0, 2.0, 2.0};
    g.features[3] = {1.0, 2.0, 1.0};

    // Conjunctive edges (job sequence)
    g.add_edge(0, 1); // Job1: Op1 -> Op2
    g.add_edge(2, 3); // Job2: Op1 -> Op2

    // Disjunctive edges (machine conflicts, bidirectional)
    g.add_edge(0, 3); // M1: Op1 Job1 and Op2 Job2
    g.add_edge(1, 2); // M2: Op2 Job1 and Op1 Job2

    return g;
}

int main() {
    // Create graph for JSSP
    Graph jssp_graph = create_jssp_graph();

    // Random weights for GNN layer (3 input features to 2 output features)
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(-0.1, 0.1);

    vector<vector<double>> weights(3, vector<double>(2));
    for (auto& row : weights) {
        for (auto& val : row) {
            val = dis(gen);
        }
    }

    // Apply GNN layer
    auto embeddings = gnn_layer(jssp_graph, weights);

    // Output embeddings (could be used for scheduling decisions, e.g., predict priorities)
    cout << "Operation Embeddings after GNN:\n";
    for (int i = 0; i < embeddings.size(); ++i) {
        cout << "Op " << i << ": ";
        for (double val : embeddings[i]) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}