#include <bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
 
vector<vector<int>> result;

void addEdge(int src, int dest, bool bidirectional = true)
{
    graph[src].push_back(dest);
    if (bidirectional)
    {
        graph[dest].push_back(src);
    }
}
 

void dfs(int node,set<int>&visited){
      
      visited.insert(node);
      for(auto neighbour:graph[node]){
        if(not visited.count(neighbour)){
            dfs(neighbour,visited);
        }
      }

}
 int connected_Components(){
    int count = 0;
     set<int> visited;

    for(int i = 0;i<graph.size();i++){
    if(visited.count(i) == 0){
        dfs(i,visited);
        count++;
    }
        
     
    }
    return count;
 }
 

 
 

 

int main()
{
    int nodes;
    cout << "enter no of nodes in graph : ";
    cin >> nodes;
    graph.resize(nodes, list<int>());

    int edges;
    cout << "Enter no of edges in the graph : ";
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        cout << "Enter source and destination of edge (src,dest) : ";
        cin >> src >> dest;
        addEdge(src, dest);
    }
    // int start, end;
    // cout << "Enter the start and end vertes to traverse the graph (start,end ): ";
    // cin >> start >> end;
    // // dfsTraversalGraph(start, end) ;
    // cout << endl;
    // cout << checkIfThereIsAnyPathBetweenTwoVertex(start, end);
    // printAllPaths(start, end);

    // printGraph();
    cout<<"no of connected components in graph : "<<connected_Components()<<endl;
    

    return 0;
}