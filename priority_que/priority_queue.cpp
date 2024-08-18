#include<iostream>
using namespace std;
#include<queue>
int main(){
    //this is the max_heap by default
    priority_queue<int>pq;
    pq.push(5);
    pq.push(7);
    pq.push(1);
    pq.push(3);
    cout<<pq.top()<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }cout<<endl;
    //generating the min_heap
    priority_queue<int,vector<int>,greater<int>>pq1;
    pq1.push(9);
    pq1.push(6);
    pq1.push(2);
    pq1.push(8);
    while(!pq1.empty()){
        cout<<pq1.top()<<" ";
        pq1.pop();
    }cout<<endl;

}