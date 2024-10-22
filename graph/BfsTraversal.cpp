#include <bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
set<int>visited;

void addEdge(int src, int dest, bool isBidirectional = true)
{
    graph[src].push_back(dest);
    if (isBidirectional)
    {
        graph[dest].push_back(src);
    }
}

void bfsTraversal(int src,vector<int>&distance){
    queue<int>q;
     

    q.push(src);
    visited.insert(src);
    distance[src] = 0;
    while(!q.empty()){
        //take the current 
        int curr = q.front();
        cout<<curr<<" ";
        q.pop();
        for(auto neighbour:graph[curr]){

            if(not visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                distance[neighbour] = distance[curr]+1;

            }
        }
        

    }
     cout<<endl;


}

void printGraph()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << "->";
        for (auto j : graph[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int vertex;
    cout << "ENter the no of vertex in graph : ";
    cin >> vertex;
    graph.resize(vertex, list<int>());
    int edge;
    cout << "Enter the no of Edges in graph : ";
    cin >> edge;
    while (edge--)
    {
        int src, dest;
        cout << "Enter source and destination of edge (src,dest) : ";
        cin >> src >> dest;
        addEdge(src, dest);
    }

    vector<int>v(vertex);
    int src;
    cin>>src;
    bfsTraversal(src,v);
    for(auto i:v){
        cout<<i<<" ";
    }


}