#include<iostream>
using namespace std;
#include<vector>
int main(){
    cout<<"Enter the number of row and columns in the arr "<<endl;
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n+1,vector<int>(m+1));
    for(int i = 1;i<=n;i++){
       for(int j = 1;j<=m;j++){
        cin>>arr[i][j];
       }
    }
    //create the prefix arr
    vector<vector<int>>prefix(n+1,vector<int>(m+1));
    for(int i = 1;i<=n;i++){
        for(int j  =1;j<=m;j++){
            prefix[i][j] = arr[i][j]+prefix[i][j-1]+prefix[i-1][j]-prefix[i-1][j-1];
        }
    }
    //print the prefix array 
    cout<<"Prefix array is : "<<endl;
    for(auto row:prefix){
        for(auto ele:row){
            cout<<ele<<" ";
        }cout<<endl;
    }
    cout<<"Enter the number of queries "<<endl;
    int q;
    cin>>q;
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int ans = prefix[c][d]-prefix[a-1][d]-prefix[c][b-1]+prefix[a-1][b-1];
        
        cout<<ans<<endl;
    }

    return 0;
}