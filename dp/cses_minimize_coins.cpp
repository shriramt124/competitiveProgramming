#include<iostream>
using namespace std;
#include<climits>
#include<vector>

int solv(vector<int>&arr,int target,int idx,int count,vector<int>&dp){
  

     if(idx>=arr.size()){
        if(target== 0)
         return count;

         return -1;
        
     }
    
     if(target == 0){
        return count;
     }
     if(dp[idx]!=INT_MAX){
        return dp[idx];
     }

    //take one and be there 
     
    if(target-arr[idx]>=0)
   dp[idx] = min(dp[idx] ,solv(arr,target-arr[idx],idx,count+1,dp));  
   //this is for taking the coin and mvoe to next
   if(target-arr[idx]>=0)
   dp[idx]  = min(dp[idx] , solv(arr,target-arr[idx],idx+1,count+1,dp));
   //this is for not taking and move to next
    dp[idx]  = min(dp[idx] ,solv(arr,target,idx+1,count,dp));
    if(dp[idx]  == INT_MAX) return -1;
    return dp[idx];
}
int main(){

  int n,x;
   cin>>n>>x;
   vector<int>dp(x+1,INT_MAX);
  
   vector<int>v(n);//coins array
   for(int i  = 0;i<n;i++){
    cin>>v[i];
   }
   if(n == 1){
  //if v[0]<x 
  //cout<<(x/v[0])<<endl;
  //else
  //cout<<(-1)
  if(v[0]<=x){
    cout<<(x/v[0])<<endl;
  }else{
    cout<<(-1)<<endl;
  }
    return 0;
   }
   if(x>0){
   int count = 0;
 
  int res =  solv(v,x,0,count,dp);
  if(res == INT_MAX){
    cout<<(-1)<<endl;
  }else
  cout<<res<<endl;
 
   }else cout<<0<<endl;
    
    return 0;
}