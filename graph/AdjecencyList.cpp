#include <bits/stdc++.h>
using namespace std;

vector<list<int>> undirectedGraph;
vector<list<pair<int,int>>>weightedGraph;

void addEdge(int src, int dest, bool isBidirectional = true) {
    undirectedGraph[src].push_back(dest);
    if (isBidirectional) {
        undirectedGraph[dest].push_back(src);
    }
}

void addEdgeWeighted(int src,int dest,int weight,bool isBirectional=true){
    weightedGraph[src].push_back({dest,weight});
    if(isBirectional){
        weightedGraph[dest].push_back({src,weight});
    }

}

void printWeightGraph(){
    for(int i = 0;i<weightedGraph.size();i++){
        cout<<i<<"->";
        for(auto j:weightedGraph[i]){
            cout<<"("<<j.first<<","<<j.second<<")";
        }
        cout<<endl;
    }
}

void printUndirectedGraph() {
    for (int i = 0; i < undirectedGraph.size(); i++) {
        cout << i << " -> ";
        for (auto j : undirectedGraph[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void solvUnweightedGraph(int noOfVertex){
 undirectedGraph.resize(noOfVertex, list<int>());
    
    int e;
    cout << "Enter the number of edges in the graph: ";
    cin >> e;

    while (e--) {
        int src, dest;
        cout << "Enter edge (src dest): ";
        cin >> src >> dest;

        // Validate input for src and dest
        if (src < 0 || src >= noOfVertex || dest < 0 || dest >= noOfVertex) {
            cout << "Invalid edge! Please enter vertices between 0 and " << (noOfVertex - 1) << endl;
            continue; // Skip this iteration
        }

        addEdge(src, dest,false);
    }

    cout << "Undirected Graph:" << endl;
    printUndirectedGraph();

}

void solvWeightedGraph(int noOfVertex){
    weightedGraph.resize(noOfVertex, list<pair<int,int>>());

    int e;
    cout << "Enter the number of edges in the graph: ";
    cin >> e;
    while(e--){
        int src,dest,weight;
        cout<<"Enter edge (src dest weight); ";
        cin>>src>>dest>>weight;

        if(src<0 || src>=noOfVertex || dest<0 || dest>=noOfVertex){
            cout<<"Invalid edge!"<<endl;
            continue;
        }

        addEdgeWeighted(src,dest,weight,false);
        
    }
}

int main() {
    int noOfVertex;
    cout << "Enter the number of vertices: ";
    cin >> noOfVertex;
    
    if (noOfVertex <= 0) {
        cout << "Number of vertices must be greater than 0." << endl;
        return 1; // Exit the program with an error
    }

   // solvUnweightedGraph(noOfVertex);
    solvWeightedGraph(noOfVertex);
    printWeightGraph();
    
    
    return 0;
}
