#include "graph.h"
#include <iomanip> // De format output

Graph::Graph(int vertices, bool directed) : V(vertices), adj(vertices), is_directed(directed) {}

int Graph::getV() const { return V; }

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    if (!is_directed) {
        adj[v].push_back({u, w});
    }
    edge_list.push_back({u, v, w});
}

const std::list<std::pair<int, int>>& Graph::getAdj(int u) const {
    return adj[u];
}

void Graph::print() const {
    for (int i = 0; i < V; ++i) {
        std::cout << "  Dinh " << i << ": ";
        for (const auto& edge : adj[i]) {
            std::cout << "-> " << edge.first << "(w:" << edge.second << ") ";
        }
        std::cout << std::endl;
    }
}

// --- Ham BFS duoc viet lai chi tiet ---
void Graph::BFS(int s) {
    std::cout << "\n--- Thuat toan BFS (bat dau tu " << s << ") ---" << std::endl;
    std::vector<int> dist(V, INF);
    std::vector<int> prev(V, -1);
    std::vector<bool> visited(V, false);
    std::queue<int> queue;

    dist[s] = 0;
    visited[s] = true;
    queue.push(s);

    int step = 0;
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        step++;

        std::cout << "\n--- BUOC " << step << ": Duyet dinh " << u << " (khoang cach: " << (dist[u] == INF ? "INF" : std::to_string(dist[u])) << ") ---" << std::endl;
        std::cout << std::left << std::setw(10) << "Dinh"
                  << std::setw(15) << "Trang thai"
                  << std::setw(20) << "Duong di"
                  << std::setw(10) << "Do dai" << std::endl;
        std::cout << std::string(55, '-') << std::endl;

        for (int i = 0; i < V; ++i) {
             std::cout << std::left << std::setw(10) << i
                       << std::setw(15) << (visited[i] ? "Da duyet" : "Chua duyet")
                       << std::setw(20) << getPath(s, i, prev)
                       << std::setw(10) << (dist[i] == INF ? "INF" : std::to_string(dist[i])) << std::endl;
        }


        for (const auto& edge : adj[u]) {
            int v = edge.first;
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                prev[v] = u;
                queue.push(v);
            }
        }
    }
     std::cout << "\n--- KET QUA CUOI CUNG (BFS)---" << std::endl;
    for(int i=0; i<V; ++i){
        std::cout << "Duong di ngan nhat (theo so canh) tu " << s << " toi " << i << " la: " << getPath(s, i, prev) << " (Do dai: " << (dist[i] == INF ? "INF" : std::to_string(dist[i])) << ")" << std::endl;
    }
}

// --- Ham DFS duoc viet lai chi tiet ---
void Graph::DFS_util(int u, std::vector<bool>& visited, std::vector<int>& prev, int& step, int s) {
    visited[u] = true;
    step++;
    std::cout << "\n--- BUOC " << step << ": Duyet dinh " << u << " ---" << std::endl;
    std::cout << std::left << std::setw(10) << "Dinh"
              << std::setw(15) << "Trang thai"
              << std::setw(20) << "Duong di" << std::endl;
    std::cout << std::string(45, '-') << std::endl;

    for (int i = 0; i < V; ++i) {
        std::cout << std::left << std::setw(10) << i
                  << std::setw(15) << (visited[i] ? "Da duyet" : "Chua duyet")
                  << std::setw(20) << getPath(s, i, prev) << std::endl;
    }

    for (const auto& edge : adj[u]) {
        int v = edge.first;
        if (!visited[v]) {
            prev[v] = u;
            DFS_util(v, visited, prev, step, s);
        }
    }
}

void Graph::DFS(int s) {
    std::cout << "\n--- Thuat toan DFS (bat dau tu " << s << ") ---" << std::endl;
    std::vector<bool> visited(V, false);
    std::vector<int> prev(V, -1);
    int step = 0;
    DFS_util(s, visited, prev, step, s);

    std::cout << "\n--- KET QUA CUOI CUNG (DFS)---" << std::endl;
    std::cout << "Thu tu duyet: ";
    std::vector<int> path;
    int curr = -1;
    for(int i=0; i<V; ++i) {
        if(visited[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    for(int i=0; i<V; ++i){
         std::cout << "Duong di tim thay tu " << s << " toi " << i << " la: " << getPath(s, i, prev) << std::endl;
    }
}


// --- Cac ham phan tich moi ---
void Graph::isConnected_util(int u, std::vector<bool>& visited) {
    visited[u] = true;
    for (const auto& edge : adj[u]) {
        if (!visited[edge.first]) {
            isConnected_util(edge.first, visited);
        }
    }
}

bool Graph::isConnected() {
    if (V == 0) return true;
    std::vector<bool> visited(V, false);
    isConnected_util(0, visited);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

void Graph::analyzeGraph() {
    std::cout << "\n--- Phan tich do thi ---" << std::endl;
    std::cout << "So dinh: " << V << std::endl;
    std::cout << "So canh: " << edge_list.size() << std::endl;
    std::cout << "Tinh lien thong: " << (isConnected() ? "Lien thong" : "Khong lien thong") << std::endl;

    bool has_parallel = false;
    std::map<std::pair<int, int>, int> edge_counts;
    for (const auto& edge : edge_list) {
        int u = std::min(edge.u, edge.v);
        int v = std::max(edge.u, edge.v);
        edge_counts[{u, v}]++;
        if (edge_counts[{u, v}] > 1) {
            has_parallel = true;
        }
    }
    std::cout << "Canh song song: " << (has_parallel ? "Co" : "Khong") << std::endl;

    bool has_loop = false;
    for (const auto& edge : edge_list) {
        if (edge.u == edge.v) {
            has_loop = true;
            break;
        }
    }
    std::cout << "Canh khuyen: " << (has_loop ? "Co" : "Khong") << std::endl;
}

// --- Ham Dijkstra duoc viet lai ---
std::string Graph::getPath(int src, int dest, const std::vector<int>& prev) {
    if (prev[dest] == -1 && dest != src) return "N/A";
    std::string path_str = "";
    int current = dest;
    while (current != -1) {
        path_str = std::to_string(current) + (path_str.empty() ? "" : " <- ") + path_str;
        current = prev[current];
    }
    return path_str;
}

void Graph::dijkstra(int src) {
    std::cout << "\n--- Thuat toan Dijkstra (bat dau tu " << src << ") ---" << std::endl;
    std::vector<int> dist(V, INF);
    std::vector<int> prev(V, -1);
    std::vector<bool> visited(V, false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    int step = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        step++;

        std::cout << "\n--- BUOC " << step << ": Duyet dinh " << u << " (khoang cach: " << dist[u] << ") ---" << std::endl;
        std::cout << std::left << std::setw(10) << "Dinh ke"
                  << std::setw(30) << "Canh di toi dinh dang xet"
                  << std::setw(15) << "Trang thai"
                  << std::setw(20) << "Duong di"
                  << std::setw(10) << "Do dai" << std::endl;
        std::cout << std::string(85, '-') << std::endl;
        
        for (int i = 0; i < V; ++i) {
             std::cout << std::left << std::setw(10) << i
                       << std::setw(30) << (prev[i] != -1 ? (std::to_string(prev[i]) + " -> " + std::to_string(i)) : "N/A")
                       << std::setw(15) << (visited[i] ? "Da duyet" : "Chua duyet")
                       << std::setw(20) << getPath(src, i, prev)
                       << std::setw(10) << (dist[i] == INF ? "INF" : std::to_string(dist[i])) << std::endl;
        }

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    std::cout << "\n--- KET QUA CUOI CUNG ---" << std::endl;
    for(int i=0; i<V; ++i){
        std::cout << "Duong di ngan nhat tu " << src << " toi " << i << " la: " << getPath(src, i, prev) << " (Do dai: " << (dist[i] == INF ? "INF" : std::to_string(dist[i])) << ")" << std::endl;
    }
}