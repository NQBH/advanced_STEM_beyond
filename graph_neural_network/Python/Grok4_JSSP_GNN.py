import torch
import torch.nn as nn
import torch.nn.functional as F
from typing import List, Tuple
from torch.distributions import Categorical

class Operation:
    def __init__(self, job_id: int, machine_id: int, processing_time: int):
        self.job_id = job_id
        self.machine_id = machine_id
        self.processing_time = processing_time
        self.is_scheduled = False
        self.start_time = 0.0
        self.end_time = 0.0

class JSSP:
    def __init__(self, num_jobs: int, num_machines: int):
        self.num_jobs = num_jobs
        self.num_machines = num_machines
        self.operations = [[] for _ in range(num_jobs)]
        self.machine_available = [0.0] * num_machines
        self.job_ready = [0.0] * num_jobs
        self.next_op = [0] * num_jobs
        self.makespan = 0.0

    def add_job(self, job_id: int, ops: List[Operation]):
        self.operations[job_id] = ops

    def get_ready_operations(self) -> List[Tuple[int, int]]:
        ready = []
        for j in range(self.num_jobs):
            if self.next_op[j] < len(self.operations[j]):
                op_idx = self.next_op[j]
                ready.append((j, op_idx))
        return ready

    def schedule_operation(self, job: int, op_idx: int):
        if op_idx != self.next_op[job]:
            return
        op = self.operations[job][op_idx]
        if op.is_scheduled:
            return
        start = max(self.job_ready[job], self.machine_available[op.machine_id])
        op.start_time = start
        op.end_time = start + op.processing_time
        self.machine_available[op.machine_id] = op.end_time
        self.job_ready[job] = op.end_time
        op.is_scheduled = True
        self.next_op[job] += 1
        self.makespan = max(self.makespan, op.end_time)

    def get_graph_state(self) -> Tuple[List[List[float]], List[List[int]]]:
        ready_ops = self.get_ready_operations()
        n_nodes = len(ready_ops)
        node_features = [[0.0] * 4 for _ in range(n_nodes)]
        adj_list = [[] for _ in range(n_nodes)]

        machine_to_nodes = {}
        for i, (j, o_idx) in enumerate(ready_ops):
            op = self.operations[j][o_idx]
            node_features[i] = [float(op.processing_time), float(op.machine_id), float(j), self.job_ready[j]]
            m = op.machine_id
            if m not in machine_to_nodes:
                machine_to_nodes[m] = []
            machine_to_nodes[m].append(i)

        for m_nodes in machine_to_nodes.values():
            for ii in range(len(m_nodes)):
                for jj in range(ii + 1, len(m_nodes)):
                    i1, i2 = m_nodes[ii], m_nodes[jj]
                    adj_list[i1].append(i2)
                    adj_list[i2].append(i1)

        return node_features, adj_list

class GNNLayer(nn.Module):
    def __init__(self, input_dim: int, hidden_dim: int):
        super().__init__()
        self.linear_self = nn.Linear(input_dim, hidden_dim)
        self.linear_neigh = nn.Linear(input_dim, hidden_dim)
        self.linear_combine = nn.Linear(hidden_dim * 2, hidden_dim)

    def forward(self, x: torch.Tensor, adj: torch.Tensor) -> torch.Tensor:
        h_self = F.relu(self.linear_self(x))
        h_neigh_input = F.relu(self.linear_neigh(x))
        h_neigh = torch.mm(adj, h_neigh_input)
        degrees = torch.sum(adj, dim=1, keepdim=True) + 1e-6
        h_neigh = h_neigh / degrees
        h_combined = torch.cat([h_self, h_neigh], dim=1)
        return F.relu(self.linear_combine(h_combined))

class PolicyNetwork(nn.Module):
    def __init__(self, feature_dim: int, hidden_dim: int):
        super().__init__()
        self.gnn = GNNLayer(feature_dim, hidden_dim)
        self.policy_head = nn.Linear(hidden_dim, 1)

    def forward(self, node_features: torch.Tensor, adj: torch.Tensor) -> torch.Tensor:
        embeddings = self.gnn(node_features, adj)
        logits = self.policy_head(embeddings).squeeze(-1)
        return logits

def build_adj_matrix(adj_list: List[List[int]], n_nodes: int) -> torch.Tensor:
    adj = torch.zeros(n_nodes, n_nodes, dtype=torch.float)
    for i, neighs in enumerate(adj_list):
        for j in neighs:
            adj[i, j] = 1.0
    return adj

class RLAgent:
    def __init__(self, feature_dim: int = 4, hidden_dim: int = 8):
        self.policy = PolicyNetwork(feature_dim, hidden_dim)
        self.optimizer = torch.optim.Adam(self.policy.parameters(), lr=0.01)

    def get_action_log_prob(self, node_features: List[List[float]], adj_list: List[List[int]]) -> Tuple[int, torch.Tensor]:
        n_nodes = len(node_features)
        x = torch.FloatTensor(node_features)
        adj = build_adj_matrix(adj_list, n_nodes)
        logits = self.policy(x, adj)
        action_dist = Categorical(logits=logits)
        action = action_dist.sample().item()
        log_prob = action_dist.log_prob(torch.tensor(action))
        return action, log_prob

    def update(self, log_prob: torch.Tensor, reward: float, baseline: float = 0.0):
        advantage = reward - baseline
        loss = -log_prob * advantage
        self.optimizer.zero_grad()
        loss.backward()
        self.optimizer.step()

def solve_jssp(agent: RLAgent, problem: JSSP) -> float:
    total_reward = 0.0
    while True:
        ready_ops = problem.get_ready_operations()
        if not ready_ops:
            break
        node_features, adj_list = problem.get_graph_state()
        action, log_prob = agent.get_action_log_prob(node_features, adj_list)
        job, op_idx = ready_ops[action]
        prev_makespan = problem.makespan
        problem.schedule_operation(job, op_idx)
        reward = -(problem.makespan - prev_makespan)
        agent.update(log_prob, reward)
        total_reward += reward
    return total_reward

# Example usage
if __name__ == "__main__":
    problem = JSSP(2, 2)
    problem.add_job(0, [Operation(0, 0, 3), Operation(0, 1, 2)])
    problem.add_job(1, [Operation(1, 1, 2), Operation(1, 0, 4)])
    agent = RLAgent()
    reward = solve_jssp(agent, problem)
    print(f"Makespan: {problem.makespan}")
    print(f"Total Reward: {reward}")
    for j in range(problem.num_jobs):
        for op in problem.operations[j]:
            if op.is_scheduled:
                print(f"Job {op.job_id} on M{op.machine_id} [{op.start_time:.1f}, {op.end_time:.1f}]")