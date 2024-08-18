#include<iostream>
using namespace std;
#include<vector>
int main(int argc, char const *argv[])
{
    int n;
    cout<<"enter the number of nodes in your Tree"<<endl;
    cin>>n;
    //initialize the adjecency matrix with all of its element with 0
    vector<vector<int>>adjMatrix(n,vector<int>(n,0));
    
    for(int i = 0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        //adding an edge from u to v
        adjMatrix[u][v] = 1;

    }
    cout<<"our adjecency matrix is : "<<endl;
    for(auto row:adjMatrix){
        for(auto ele:row){
            cout<<ele<<" ";
        }cout<<endl;
    }

    return 0;
}
