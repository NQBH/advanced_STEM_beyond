#ifndef GRAPH_TREE_H
#define GRAPH_TREE_H

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    class Vertex; 

    class Edge {
    private:
        int _id; 
        Vertex* _source; 
        Vertex* _target; 
        double _weight;
    public:
        Edge(int id, Vertex* s, Vertex* t, double w) : _id(id), _source(s), _target(t), _weight(w) {}
        int id() const { return _id; }
        Vertex* source() const { return _source; }
        Vertex* target() const { return _target; }
        Vertex* opposite(Vertex* v) const { return (v == _source) ? _target : _source; }
        double weight() const { return _weight; }
    };

    class Vertex {
    public:
        int _id; 
        int _label; 
        int order = -1; 
        int depth = -1;
        Vertex(int id, int label) : _id(id), _label(label) {}
        int id() const { return _id; }
        int label() const { return _label; }
    };

protected:
    struct AdjacencyInfo { 
        map<Vertex*, vector<Edge*>> incoming; 
        map<Vertex*, vector<Edge*>> outgoing; 
    };
    map<Vertex*, AdjacencyInfo*> _data;
    bool _is_undirected;
    int _next_v_id = 0, _next_e_id = 0;
    vector<Vertex*> _vertex_pool; 
    vector<Edge*> _edge_pool;

public:
    Graph(bool is_undirected = false) : _is_undirected(is_undirected) {}
    virtual ~Graph() { 
        for (Vertex* v : _vertex_pool) delete v; 
        for (Edge* e : _edge_pool) delete e; 
        for (auto const& [v, info] : _data) delete info; 
    }
    bool is_undirected() const { return _is_undirected; }
    vector<Vertex*> vertices() const { return _vertex_pool; }
    vector<Edge*> edges() const { return _edge_pool; }
    Vertex* new_vertex(int label) { 
        Vertex* v = new Vertex(_next_v_id++, label);
        _vertex_pool.push_back(v); 
        _data[v] = new AdjacencyInfo(); 
        return v; 
    }
    Edge* new_edge(Vertex* u, Vertex* v, double weight = 1.0) { 
        Edge* e = new Edge(_next_e_id++, u, v, weight); _edge_pool.push_back(e); 
        _data[u]->outgoing[v].push_back(e); _data[v]->incoming[u].push_back(e);
        if (_is_undirected && u != v) { 
            _data[v]->outgoing[u].push_back(e); 
            _data[u]->incoming[v].push_back(e); 
        }
        return e;
    }
    int indeg(Vertex* v) const { 
        int c = 0; 
        if(_data.count(v)) for(auto const& p : _data.at(v)->incoming) c += p.second.size(); 
        return c; 
    }
    const map<Vertex*, vector<Edge*>>& get_outgoing_map(Vertex* v) const { return _data.at(v)->outgoing; }
    const map<Vertex*, vector<Edge*>>& get_incoming_map(Vertex* v) const { return _data.at(v)->incoming; }
};

class Tree : public Graph {
private:
    Vertex* _root = nullptr;
public:
    int num = 0; // Count for recursive
    Tree() : Graph(false) {}
    Vertex* new_node(int label) { return new_vertex(label); }
    int number_of_nodes() const { return _vertex_pool.size(); }
    bool is_root(Vertex* v) const { return indeg(v) == 0; }
    Vertex* get_root() { 
        if (_root != nullptr) return _root; 
        for (Vertex* v : _vertex_pool) { 
            if (is_root(v)) { 
                _root = v; return v; 
            } 
        } 
        return nullptr; 
    }
    Vertex* get_parent(Vertex* v) const { 
        if (is_root(v)) return nullptr; 
        return _data.at(v)->incoming.begin()->first; 
    }
    vector<Vertex*> get_children(Vertex* v) const {
        vector<Vertex*> children;
        auto out_edges = get_outgoing_map(v);
        for(auto const& pair : out_edges) children.push_back(pair.first);
        sort(children.begin(), children.end(), [](Vertex* a, Vertex* b){ return a->label() < b->label(); });
        return children;
    }
};

#endif // GRAPH_TREE_H