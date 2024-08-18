#include<iostream>
using namespace std;
#include<stdlib.h>
#include<algorithm>
#include<vector>
int Recursion(vector<int>arr,int n,vector<int>&dp){
    if(n<0) return 0;
    if(n == 0) return arr[0];
    if(dp[n] != -1) return dp[n];
    int pick = arr[n]+Recursion(arr,n-2,dp);
    int notPick = Recursion(arr,n-1,dp);
    return dp[n] = max(pick,notPick);
}
int Tabulation(vector<int>arr,int n){
    vector<int>dp(n+1,0);
    dp[0] = arr[0];
    for(int i = 1;i<n;i++){
        int pick = arr[i];
        if(i>1){
            pick = pick+dp[i-2];
        }
        int notPick = dp[i-1];
        dp[i] = max(pick,notPick);
    }
    return dp[n-1];
}

int maxSumOfNonAdjecentElement(vector<int>arr,int n){
    if(n == 1) return arr[0];
    if(n == 2) return max(arr[0],arr[1]);
   vector<int>dp(n+1,-1);

   int ans = Recursion(arr,n-1,dp);
  int res = Tabulation(arr,n);
  return res;

    
}
int main(){

   int n;
   cin>>n;
   vector<int>arr(n);
   for(int i = 0;i<n;i++){
    cin>>arr[i];
   }
   int ans = maxSumOfNonAdjecentElement(arr,n);
   cout<<ans<<endl;


    return 0;
}