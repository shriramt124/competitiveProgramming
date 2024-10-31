#include<bits/stdc++.h>
using namespace std;
vector<list<int>>graph;
set<int>visited;
set<int>dfsvisited;

void addEdge(int src,int dest,bool isBidirectional = false){
    graph[src].push_back(dest);
    if(isBidirectional){
        graph[dest].push_back(src);
    }
}

bool directedCycleDfs(int node){
    visited.insert(node);
    dfsvisited.insert(node);
    for(auto neighbour:graph[node]){
        if(!visited.count(neighbour)){
            if(directedCycleDfs(neighbour)){
                return true;
            }
        }else if(dfsvisited.count(neighbour)){
             return true;
        }
    }
    dfsvisited.erase(node);
    return false;
   
}
void directedGraphCycledetectionDFS(){
    for(int i=0;i<graph.size();i++){
        if(!visited.count(i)){
            if(directedCycleDfs(i)){
                cout<<"Cycle is present in the graph"<<endl;
                return;
            }
        }
    }
}

int main(){
    int v;
    cout<<"Enter the no of vertex you want to add in the graph ";
    cin>>v;
    cout<<"Enter the no of Edge in the graph ";
    int e;
    cin>>e;
    graph.resize(v);
    for(int i=0;i<e;i++){
        int src,dest;
        cin>>src>>dest;
        addEdge(src,dest);
    }
    directedGraphCycledetectionDFS();

}