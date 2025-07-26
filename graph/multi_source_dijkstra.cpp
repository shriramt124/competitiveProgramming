#include<bits/stdc++.h>
using namespace std;
vector<int>sources;
vector<vector<pair<int,int>>>graph;
int vertices;

vector<int>multiSourceDijkstra(){
    int n = vertices;
    vector<int>dist(n+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    for(int src:sources){
        dist[src] = 0;
      pq.push({0,src});
    }
    while(not pq.empty()){
        auto it = pq.top();
        pq.pop();
        int d = it.first;
        int u= it.second;
        if(d>dist[u]) continue;;
        for(auto [v,w]:graph[u]){
         if(dist[u]+w < dist[v]){
            dist[v] = dist[u]+w;
            pq.push({dist[v],v});
         }
        }
        
    }
    return dist;   //it represents the minimum distrance to reach i from any source node this is what the dist[i] represents 
}
void addEdge(int from,int to,int weight){
    graph[from].push_back({to,weight});
    graph[to].push_back({from,weight});
}
int main(int argc, char const *argv[])
{

    int vertices = 7;
    int edges = 5;
    graph.resize(vertices);
     while(edges--){
        int from,to,weight;
        cin>>from>>to>>weight;
        addEdge(from,to,weight);
     }    
    return 0;
}


