#include<iostream>
using namespace std;
#include<bits/stdc++.h>
vector<list<int>>graph;
int vertex;
int edges;

void addEdge(int src,int dest,bool bidirectional = true){
    graph[src].push_back(dest);
    if(bidirectional){
        graph[dest].push_back(src);
    }

}

void bfs(int src){
    set<int>visited;
    vector<int>dist(vertex);
    queue<int>q;
    q.push(src);
    visited.insert(src);
    dist[src] = 0;
    while(not q.empty()){
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";
        for(auto neighbour:graph[curr]){
            if(not visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }
}

void dfs(set<int>&visited,int src){
    visited.insert(src);
      cout<<src<<" ";
    for(auto neighbour:graph[src]){
        if(not visited.count(neighbour)){
            dfs(visited,neighbour);
        }
    }


}

bool iscycle(set<int>&visited,int src){
    unordered_map<int,int>parent;
    parent[src] = -1;
    queue<int>q;
    q.push(src);
    while(not q.empty()){
        auto front  = q.front();
        q.pop();
        for(auto neighbour:graph[front]){
            if(not visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                parent[neighbour] = front;
            }
            else if(neighbour!=parent[front]){
                return true;
            }
        }
    }
}


void printGraph(){
    for(int i = 0;i<graph.size();i++){
        cout<<i<<"--> ";
        for(auto next:graph[i]){
            cout<<next<<" ";
        }cout<<endl;
    }
    return;
}

int main(){
cout<<"Etner the no of vertex in the graph "<<endl;
cin>>vertex;
cout<<"Etner teh no of edges in teh graph "<<endl;
cin>>edges;

graph.resize(vertex,list<int>());

while(edges--){
    int src,vertex;
    cin>>src>>vertex;
    addEdge(src,vertex);
}

printGraph();

// bfs(0);
set<int>visited;
// int src = 0;
// dfs(visited,src);

for(int i = 0;i<graph.size();i++){
    if(not visited.count(i)){
        bool ans = iscycle(visited,i);
        if(ans){
            cout<<"YES"<<endl;
        }
    }
}


return  0;

}