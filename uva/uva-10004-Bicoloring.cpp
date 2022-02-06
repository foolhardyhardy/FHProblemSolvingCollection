#include <iostream>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;
};

bool readInGraph(Graph &g) {
    int nv = 0, ne = 0;
    cin >> nv;
    if(nv == 0) {
        return false;
    }
    cin >> ne;
    g.V = nv;
    g.adj.clear();
    g.adj.resize(nv);
    int u = 0, v = 0;
    for(int i = 0; i < ne; i++) {
        cin >> u >> v;
        g.adj[u].push_back(v);
        g.adj[v].push_back(u);
    }
    return true;
}

void determineBipartiteness(Graph &g) {
    vector<bool> visited(g.V, false), color(g.V);
    vector<pair<int, bool>> stack;
    int node = 0;
    bool coloring = 0;
    for(int i = 0; i < g.V; i++) {
        if(!visited[i]) {
            stack.push_back({i, true});
        }
        while(!stack.empty()) {
            tie(node, coloring) = stack.back();
            stack.pop_back();
            //cout << "access:" << node << " color:" << coloring << "\n";
            visited[node] = true;
            color[node] = coloring;
            for(int near: g.adj[node]) {
                if(!visited[near]) {
                    stack.push_back({near, !coloring});
                }
            }
        }
    }
    for(int i = 0; i < g.V; i++) {
        for(int j: g.adj[i]) {
            if(color[i] == color[j]) {
                cout << "NOT BICOLORABLE.\n";
                return;
            }
        }
    }
    cout << "BICOLORABLE.\n";
}

int main() {
    Graph g;
    while(readInGraph(g)) {
        determineBipartiteness(g);
    }
}