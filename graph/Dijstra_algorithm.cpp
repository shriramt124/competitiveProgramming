#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
#include<set>
#include<climits>

void dijkstra(unordered_map<int,list<pair<int,int>>>&graph,int src){
    unordered_map<int,int>dist;
    for(auto &[node,_]:graph){
     dist[node] = INT_MAX;
    }
    dist[src] = 0;

   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
   //it represents the node ,distance
   pq.push({0,src});
   while(not pq.empty()){
     pair<int,int>p = pq.top();
     pq.pop();
     int currDistance = p.first;
     int node = p.second;
      for(auto [neighbour,weight]:graph[node]){
        if(currDistance+weight < dist[neighbour]){
            dist[neighbour] = currDistance+weight;
            pq.push({dist[neighbour],neighbour});
        }
        
      }
   }
for(auto [neighbour,dist]:dist){
    cout<<"distance from source " <<src<<" node " <<neighbour << "is --> "<<dist<<endl;
}

}

int main(){

    unordered_map<int,list<pair<int,int>>>graph;
      // Example graph:
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[2].push_back({1, 2});
    graph[1].push_back({3, 1});
    graph[2].push_back({3, 5});
    graph[3].push_back({4, 3});
      int source = 0;
    dijkstra(graph, source);

    return 0;



}



