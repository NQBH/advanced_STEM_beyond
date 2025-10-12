#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <thread>

using namespace std;

// Simple matrix operations for neural networks (using vectors)
using Matrix = vector<vector<double>>;
using Vector = vector<double>;

// Utility functions for matrix operations
Matrix matrix_multiply(const Matrix& A, const Matrix& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();
    Matrix C(rowsA, vector<double>(colsB, 0.0));
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

Vector matrix_vector_multiply(const Matrix& A, const Vector& v) {
    int rows = A.size();
    int cols = A[0].size();
    Vector result(rows, 0.0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i] += A[i][j] * v[j];
        }
    }
    return result;
}

Matrix matrix_add(const Matrix& A, const Matrix& B) {
    int rows = A.size();
    int cols = A[0].size();
    Matrix C(rows, vector<double>(cols, 0.0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

Vector vector_add(const Vector& a, const Vector& b) {
    int n = a.size();
    Vector c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] + b[i];
    }
    return c;
}

Vector sigmoid(const Vector& x) {
    int n = x.size();
    Vector result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = 1.0 / (1.0 + exp(-x[i]));
    }
    return result;
}

Vector relu(const Vector& x) {
    int n = x.size();
    Vector result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = max(0.0, x[i]);
    }
    return result;
}

double dot_product(const Vector& a, const Vector& b) {
    double sum = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        sum += a[i] * b[i];
    }
    return sum;
}

// Activation function for GNN messages
Vector gnn_aggregate(const vector<Vector>& messages) {
    // Simple mean aggregation
    if (messages.empty()) return {};
    size_t dim = messages[0].size();
    Vector agg(dim, 0.0);
    for (const auto& msg : messages) {
        agg = vector_add(agg, msg);
    }
    for (size_t i = 0; i < dim; ++i) {
        agg[i] /= messages.size();
    }
    return agg;
}

// Simple Graph Neural Network layer
Vector gnn_layer(const Vector& node_features, const vector<Vector>& neighbor_features, const Matrix& W) {
    // Message passing: aggregate neighbor features
    vector<Vector> messages;
    for (const auto& nf : neighbor_features) {
        Matrix nf_mat(1, nf);  // Treat as 1xD matrix
        Matrix msg = matrix_multiply(nf_mat, W);
        messages.push_back(msg[0]);
    }
    Vector agg = gnn_aggregate(messages);
    // Combine with self
    Vector self_msg = matrix_vector_multiply({node_features}, node_features);  // Identity
    Vector combined = vector_add(self_msg, agg);
    // Apply linear transformation
    Matrix W_trans(1, W[0].size());  // Dummy
    return relu(matrix_vector_multiply(W, combined));
}

// Job Shop Scheduling Problem Representation
struct Operation {
    int job_id;
    int machine_id;
    int processing_time;
    bool is_scheduled = false;
    double start_time = 0.0;
    double end_time = 0.0;
};

class JSSP {
public:
    int num_jobs;
    int num_machines;
    vector<vector<Operation>> operations;  // operations[job][op_index]
    vector<double> machine_available;      // available time for each machine
    vector<double> job_ready;              // ready time for next op in job
    double makespan = 0.0;

    JSSP(int nj, int nm) : num_jobs(nj), num_machines(nm),
        machine_available(nm, 0.0), job_ready(nj, 0.0) {
        operations.resize(nj);
    }

    void add_job_operations(int job, const vector<Operation>& ops) {
        operations[job] = ops;
    }

    // Get unscheduled operations that are ready
    vector<int> get_ready_operations() {
        vector<int> ready;
        for (int j = 0; j < num_jobs; ++j) {
            for (int o = 0; o < operations[j].size(); ++o) {
                auto& op = operations[j][o];
                if (!op.is_scheduled && job_ready[j] <= op.start_time) {  // Simplified
                    ready.push_back(j * 100 + o);  // Unique id
                }
            }
        }
        return ready;
    }

    // Schedule an operation
    void schedule_operation(int op_id) {
        int job = op_id / 100;
        int o_idx = op_id % 100;
        auto& op = operations[job][o_idx];
        if (op.is_scheduled) return;

        // Find earliest start time
        double start = max(job_ready[job], machine_available[op.machine_id]);
        op.start_time = start;
        op.end_time = start + op.processing_time;
        machine_available[op.machine_id] = op.end_time;
        job_ready[job] = op.end_time;
        op.is_scheduled = true;
        makespan = max(makespan, op.end_time);
    }

    // Compute current state graph features (simplified)
    // Nodes: unscheduled operations, features: [processing_time, machine_id, job_id, ready_time]
    pair<vector<Vector>, vector<vector<int>>> get_graph_state() {
        vector<int> ready_ops = get_ready_operations();
        int n_nodes = ready_ops.size();
        vector<Vector> node_features(n_nodes, vector<double>(4, 0.0));
        vector<vector<int>> adj_list(n_nodes);  // Simplified adjacency, e.g., no edges for demo

        for (int i = 0; i < n_nodes; ++i) {
            int op_id = ready_ops[i];
            int job = op_id / 100;
            int o_idx = op_id % 100;
            auto& op = operations[job][o_idx];
            node_features[i][0] = op.processing_time;
            node_features[i][1] = op.machine_id;
            node_features[i][2] = job;
            node_features[i][3] = job_ready[job];  // ready time
        }

        // Add some dummy edges for demonstration (e.g., connect to potential conflicts)
        for (int i = 0; i < n_nodes; ++i) {
            for (int j = i + 1; j < n_nodes; ++j) {
                if (node_features[i][1] == node_features[j][1]) {  // Same machine
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }

        return {node_features, adj_list};
    }
};

// Simple Policy Network using GNN embeddings
class PolicyNetwork {
private:
    Matrix W_gnn;  // GNN weight matrix, say 4x8
    Matrix W_policy;  // Policy head, 8x action_dim
    double learning_rate = 0.01;

public:
    PolicyNetwork(int feature_dim, int hidden_dim, int action_dim) {
        // Initialize weights randomly
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(-1.0, 1.0);

        W_gnn = Matrix(feature_dim, vector<double>(hidden_dim));
        for (auto& row : W_gnn) {
            for (auto& val : row) val = dis(gen);
        }

        W_policy = Matrix(hidden_dim, vector<double>(action_dim));
        for (auto& row : W_policy) {
            for (auto& val : row) val = dis(gen);
        }
    }

    // Get action logits from graph state
    Vector get_action_logits(const vector<Vector>& node_features, const vector<vector<int>>& adj_list) {
        int n_nodes = node_features.size();
        vector<Vector> embeddings(n_nodes, vector<double>(W_gnn[0].size(), 0.0));

        // GNN message passing (1 layer for simplicity)
        for (int i = 0; i < n_nodes; ++i) {
            vector<Vector> neighbor_features;
            for (int neigh : adj_list[i]) {
                neighbor_features.push_back(embeddings[neigh]);  // Use current embeddings (simplified, iterative update needed)
            }
            embeddings[i] = gnn_layer(node_features[i], neighbor_features, W_gnn);
        }

        // Global pooling: mean over all nodes
        Vector global_state(W_gnn[0].size(), 0.0);
        for (const auto& emb : embeddings) {
            global_state = vector_add(global_state, emb);
        }
        for (auto& val : global_state) val /= n_nodes;

        // Policy head
        Vector logits = matrix_vector_multiply(W_policy, global_state);
        return logits;
    }

    // Sample action from logits (softmax)
    int sample_action(const Vector& logits) {
        Vector probs(logits.size());
        double sum_exp = 0.0;
        for (double l : logits) {
            double exp_l = exp(l);
            probs.push_back(exp_l);  // Wait, probs = exp(logits)
            sum_exp += exp_l;
        }
        for (auto& p : probs) p /= sum_exp;

        random_device rd;
        mt19937 gen(rd());
        discrete_distribution<> dist(probs.begin(), probs.end());
        return dist(gen);
    }

    // REINFORCE update (simple policy gradient)
    void update(const Vector& logits, int action, double reward, double baseline = 0.0) {
        // Compute log prob of action
        Vector log_probs(logits.size());
        double max_l = *max_element(logits.begin(), logits.end());
        double sum_exp = 0.0;
        for (size_t i = 0; i < logits.size(); ++i) {
            double exp_l = exp(logits[i] - max_l);
            log_probs[i] = log(exp_l);  // Simplified
            sum_exp += exp_l;
        }
        double log_prob_action = log(exp(logits[action] - max_l) / sum_exp);

        double advantage = reward - baseline;
        // Update weights (gradient ascent on log_prob * advantage)
        // Simplified: adjust W_policy
        for (size_t j = 0; j < W_policy.size(); ++j) {
            for (size_t k = 0; k < W_policy[0].size(); ++k) {
                W_policy[j][k] += learning_rate * advantage * log_prob_action;  // Very rough approximation
            }
        }
    }
};

// Reinforcement Learning Agent
class RLAgent {
private:
    PolicyNetwork policy;
    double gamma = 0.99;  // Discount factor

public:
    RLAgent(int feature_dim, int hidden_dim, int max_actions)
        : policy(feature_dim, hidden_dim, max_actions) {}

    // Solve the JSSP using RL
    double solve(JSSP& problem) {
        vector<int> ready_ops = problem.get_ready_operations();
        int total_ops = 0;
        for (const auto& job_ops : problem.operations) total_ops += job_ops.size();

        double total_reward = 0.0;
        double episode_reward = 0.0;

        while (ready_ops.size() > 0) {
            auto [node_features, adj_list] = problem.get_graph_state();
            int n_actions = node_features.size();

            Vector logits = policy.get_action_logits(node_features, adj_list);
            int action = policy.sample_action(logits);  // action is index in ready_ops

            int op_id = ready_ops[action];
            problem.schedule_operation(op_id);

            // Compute immediate reward (negative delay or something)
            double reward = -problem.makespan;  // Simple, penalize makespan increase

            episode_reward += reward;
            total_reward += episode_reward * pow(gamma, ready_ops.size());

            // Update policy (REINFORCE, but batched here for simplicity)
            policy.update(logits, action, reward);

            ready_ops = problem.get_ready_operations();
            this_thread::sleep_for(chrono::milliseconds(1));  // Simulate time
        }

        return -problem.makespan;  // Negative makespan as reward
    }
};

// Example usage
int main() {
    // Create a small JSSP instance: 2 jobs, 2 machines
    JSSP problem(2, 2);

    // Job 0: Op0 on M0 p=3, Op1 on M1 p=2
    problem.add_job_operations(0, { {0, 0, 3}, {0, 1, 2} });
    // Job 1: Op0 on M1 p=2, Op1 on M0 p=4
    problem.add_job_operations(1, { {1, 1, 2}, {1, 0, 4} });

    RLAgent agent(4, 8, 10);  // feature_dim=4, hidden=8, max_actions=10

    double reward = agent.solve(problem);

    cout << "Makespan: " << problem.makespan << endl;
    cout << "Total Reward: " << reward << endl;

    // Print schedule
    for (int j = 0; j < problem.num_jobs; ++j) {
        for (const auto& op : problem.operations[j]) {
            if (op.is_scheduled) {
                cout << "Job " << op.job_id << " Op on M" << op.machine_id
                     << " from " << op.start_time << " to " << op.end_time << endl;
            }
        }
    }

    return 0;
}