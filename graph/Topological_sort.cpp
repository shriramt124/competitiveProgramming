#include<bits/stdc++.h>
using namespace std;
vector<list<int>>graph;
set<int>visited;
stack<int>st;

void addEdge(int src,int dest,bool isBidirectional = false){
    graph[src].push_back(dest);
    if(isBidirectional){
        graph[dest].push_back(src);
    }
}

void topoSort(int node){
    visited.insert(node);
    for(auto neighbour:graph[node]){
        if(!visited.count(neighbour)){
            topoSort(neighbour);
        }
    }
    //during the time of return push that node in the stack 
    st.push(node);
}

void topologicalSort(){
    for(int i = 0;i<graph.size();i++){
        if(!visited.count(i)){
       topoSort(i);
        }
    }
    while(!st.empty()){
        cout<<(st.top())<<" ";
        st.pop();
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

   topologicalSort();

}
