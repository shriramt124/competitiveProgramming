#include<bits/stdc++.h>
using namespace std;
vector<list<int>>graph;
set<int>visited;
unordered_map<int,int>parent;

void addEdge(int src,int dest){
    graph[src].push_back(dest);
    graph[dest].push_back(src);
}

bool isCyclicBfs(int src){
    parent[src] = -1;
    visited.insert(src);
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int front = q.front();
        q.pop();
       for (auto neighbour : graph[front]) {
                if (!visited.count(neighbour)) { // If neighbor is unvisited
                    visited.insert(neighbour);
                    parent[neighbour] = front;
                    q.push(neighbour);
                } else if (neighbour != parent[front]) { // If visited and not parent, it's a cycle
                    return true;
                }
            }
    }
}

void DetectCycleInUndirectedGraph(){
    //as graph can have disconnected graph then we have to go to every node 
    for(int i = 0;i<graph.size();i++){
        if(!visited.count(i)){
            if(isCyclicBfs(i)){
                cout<<"Graph is cyclic"<<endl;
                return;
            }
        }
    }
}


bool DetectCycleDfs(int src,int parent){

    visited.insert(src);

    for(auto neighbour:graph[src]){
        if(!visited.count(neighbour)){
            if(DetectCycleDfs(neighbour,src)) return true;;
        }else if(neighbour != parent){
             
            return true;
        }
}
}

void DetectCycleDfs(){
visited.clear();
for(int i = 0;i<graph.size();i++){
    if(!visited.count(i)){
        if(DetectCycleDfs(i,-1)){
            cout<<"Graph is cyclic"<<endl;
            return;
        }
    }
}
}


void printGraph(){
   for(int i = 0;i<graph.size();i++){
    cout<<i<<" --> ";
    for(auto neighbour:graph[i]){
        cout<<neighbour<<" ";
    }cout<<endl;

   } 


}

int main(){
    int v;
    cout<<"Enter the no of Vertex in the graph : ";
    cin>>v;
    graph.resize(v,list<int>());
    cout<<"Enter the no Of Edges in the graph : ";
    int e;
    cin>>e;
    while(e--){
        int src,dest;
        cout<<"Enter the src and dest of edge (src,dest) : ";
        cin>>src>>dest;
        addEdge(src,dest);
    }
    printGraph();
    // DetectCycleInUndirectedGraph();
    DetectCycleDfs();
    return 0;
}