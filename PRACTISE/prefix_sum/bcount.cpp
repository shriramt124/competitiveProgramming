#include<iostream>
using namespace std;
#include<vector>

/* 

https://usaco.org/index.php?page=viewproblem2&cpid=572
 */

int main(){
    int n,q;
    cin>>n>>q;
    vector<int>arr(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
    }
    vector<int>one(n+1,0);
    vector<int>two(n+1,0);
    vector<int>three(n+1,0);
    for(int i = 1;i<=n;i++){
        if(arr[i] == 1){
            one[i] = one[i-1]+arr[i];
            three[i] = three[i-1];
            two[i] = two[i-1];
            
        }else if(arr[i] == 2){
            two[i] = two[i-1]+1;
              three[i] = three[i-1];
              one[i] = one[i-1];
            
        }else if(arr[i] == 3){
            three[i] = three[i-1]+1;
            two[i] = two[i-1];
            one[i] = one[i-1];
        }
    }
    
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<(one[b]-one[a-1])<<" "<<(two[b]-two[a-1])<<" "<<(three[b]-three[a-1])<<endl;
    }
    
   return 0;
}