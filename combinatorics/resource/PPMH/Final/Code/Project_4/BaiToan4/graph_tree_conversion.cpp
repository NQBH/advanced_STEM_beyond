#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>

using namespace std;

struct Edge {
    int to;
    int weight; 
};

vector<vector<Edge>> matrixToList(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<Edge>> adjList(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] != 0)
                adjList[i].push_back({j, matrix[i][j]});
    return adjList;
}

vector<vector<int>> listToMatrix(const vector<vector<Edge>>& adjList) {
    int n = adjList.size();
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int u = 0; u < n; u++)
        for (auto edge : adjList[u])
            matrix[u][edge.to] = edge.weight;
    return matrix;
}

vector<map<int, int>> listToMap(const vector<vector<Edge>>& adjList) {
    vector<map<int, int>> adjMap(adjList.size());
    for (int u = 0; u < adjList.size(); ++u)
        for (auto e : adjList[u])
            adjMap[u][e.to] = e.weight;
    return adjMap;
}

struct TreeNode {
    int id;
    vector<TreeNode*> children;
};

struct FCNSNode {
    int id;
    FCNSNode* firstChild;
    FCNSNode* nextSibling;
};

FCNSNode* buildFCNS(const vector<int>& parent) {
    int n = parent.size();
    vector<FCNSNode*> nodes(n, nullptr);
    for (int i = 0; i < n; i++)
        nodes[i] = new FCNSNode{i, nullptr, nullptr};

    FCNSNode* root = nullptr;
    vector<FCNSNode*> lastChild(n, nullptr);

    for (int i = 0; i < n; i++) {
        int p = parent[i];
        if (p == -1) {
            root = nodes[i];
        } else {
            if (!nodes[p]->firstChild)
                nodes[p]->firstChild = nodes[i];
            else
                lastChild[p]->nextSibling = nodes[i];
            lastChild[p] = nodes[i];
        }
    }

    return root;
}