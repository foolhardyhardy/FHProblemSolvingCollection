#include <iostream>
#include <vector>

using namespace std;

struct Graph {
    static const int INF;
    int nv;
    vector<vector<int>> adj;
};

const int Graph::INF = 32765;

void createGraphFromStdin(Graph &g) {
    cin >> g.nv;
    g.adj = vector<vector<int>>(g.nv, vector<int>(g.nv, Graph::INF));
    int w = 0;
    for(int i = 0; i < g.nv; i++) {
        for(int j = 0; j < g.nv; j++) {
            cin >> w;
            g.adj[i][j] = w;
        }
    }
}

void computeShortestPathsToStdout(Graph &g) {
    vector<vector<int>> dist = g.adj;
    int alt = Graph::INF;
    for(int k = 0; k < g.nv; k++) {
        for(int i = 0; i < g.nv; i++) {
            for(int j = 0; j < g.nv; j++) {
                alt = dist[i][k] + dist[k][j];
                if(alt < Graph::INF && alt < dist[i][j]) {
                    dist[i][j] = alt;
                }
            }
        }
    }
    for(int i = 0; i < g.nv; i++) {
        for(int j = 0; j < g.nv; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n = 0;
    cin >> n;
    Graph g;
    for(int i = 0; i < n; i++) {
        createGraphFromStdin(g);
        computeShortestPathsToStdout(g);
    }
    return 0;
}