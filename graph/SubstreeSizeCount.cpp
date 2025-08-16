#include <bits/stdc++.h>
using namespace std;

vector<int> subtree; // stores subtree size of each node

// DFS function to compute subtree size
int dfs(int node, int parent, vector<vector<int>>& graph) {
    int size = 1; // count itself

    for (int nei : graph[node]) {
        if (nei == parent) continue; // don’t go back to parent
        size += dfs(nei, node, graph); // add child subtree size
    }

    subtree[node] = size; 
    return size;
}

int main() {
   
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{2,4}};

    int n = edges.size() + 1; 
    vector<vector<int>> graph(n);
 
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        graph[u].push_back(v);
        graph[v].push_back(u);  
    }

    subtree.assign(n, 0);
 
    dfs(0, -1, graph);
 
    cout << "Subtree sizes:\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " -> " << subtree[i] << "\n";
    }

    return 0;
}
