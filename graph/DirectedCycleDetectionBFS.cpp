#include<bits/stdc++.h>
using namespace std;
vector<list<int>>graph;
set<int>visited;
map<int,int>parent;

void addEdge(int src,int dest){
 graph[src].push_back(dest);
 graph[dest].push_back(src);
}

bool bfs(int src){
    queue<int>q;
    q.push(src);
    parent[src] = -1;
    visited.insert(src);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto neighbour:graph[front]){
            if(!visited.count(neighbour)){
              visited.insert(neighbour);
              parent[neighbour]  = front;
              q.push(neighbour);
            }else if(parent[front] != neighbour){
                return true;
            }
        }
    }
 return false;
}

void checkCycleDetectionUsingBFS(){
    for(int i = 0;i<graph.size();i++){
        for(auto neighbour:graph[i]){
            if(!visited.count(neighbour)){
                bool res = bfs(neighbour);
                if(res){
                    cout<<"YES there is a cycle "<<endl;
                    return;
                }
            }
        }
    }

}

void pirntGraph(){
    for(int i = 0;i<graph.size();i++){
        cout<<" Vertex "<<i<<"--> ";
        for(auto neighbour:graph[i]){
            cout<<neighbour<<" ";
        }cout<<endl;
    }

}


int main(){
    int vertex;
    cout<<"Enter the no of vertex in the graph ";
    cin>>vertex;
     graph.resize(vertex,list<int>());
     int edges;
     cout<<"Enter teh no of edges in the graph : ";
     cin>>edges;
     while(edges--){
        int src,dest;
        cin>>src>>dest;
        addEdge(src,dest);
     }
    
      checkCycleDetectionUsingBFS();

}