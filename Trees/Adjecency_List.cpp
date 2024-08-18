#include<iostream>
using namespace std;
#include<vector>
int main(int argc, char const *argv[])
{
    int n;
    cout<<"enter no of nodes in the tree"<<endl;
    cin>>n;
    vector<int>tree[n];
    for(int i = 0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
    }
cout<<"adjecency list is :"<<endl;
    for(auto row:tree){
        for(auto ele:row){
            cout<<ele<<" ";
        }cout<<endl;
    }
    return 0;
}
