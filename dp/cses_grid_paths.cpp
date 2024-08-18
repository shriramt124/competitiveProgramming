#include<iostream>
using namespace std;
#include<vector>
const int modu = 1e9+7;

//dp[i][j] --> it represents the min number of steps to make i,j to-> n-1,n-1
//transition

//dp[i][j] = dp[i][j]+solv(i+1,j,arr,n)+solv(i,j+1,arr,n)

//ans
//dp[n-1][n-1] = 0

  int solv(int i,int j,int n,vector<vector<char>>&arr,vector<vector<int>>&dp){
   
    if(i>=n || j>=n){
        return 0;
    }
     
    if(i == n-1 && j == n-1){
        return 1;
    }
    if(dp[i][j] != 0){
       
        return dp[i][j];
    }
        
    if(i+1< n and j < n and arr[i+1][j]!='*'){
      dp[i][j] = (dp[i][j]+solv(i+1,j,n,arr,dp))%modu;
    }
    if(i < n and j+1< n and arr[i][j+1] != '*'){
      dp[i][j] = (dp[i][j]+solv(i,j+1,n,arr,dp))%modu;
    }
   return( dp[i][j])%modu;
  }
  int recursive(int n,vector<vector<char>>&arr){
    vector<vector<int>>dp(n,vector<int>(n,0));
    dp[0][0] = (arr[0][0]) == '.' ? 1:0;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(arr[i][j] == '*'){
                dp[i][j] = 0;
            }else{
                if(i>0) dp[i][j] = (dp[i-1][j]+dp[i][j])%modu;
                if(j>0) dp[i][j] = (dp[i][j-1]+dp[i][j])%modu;

            }
        }
    }
    return dp[n-1][n-1];

  }

int main(){

   int n;
   cin>>n;
   vector<vector<char>>arr(n,vector<char>(n));
   for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
        cin>>arr[i][j];
    }
   }
   vector<vector<int>>dp(n,vector<int>(n,0));
   int ans = recursive(n,arr);
   cout<<ans<<endl;

    return 0;
}