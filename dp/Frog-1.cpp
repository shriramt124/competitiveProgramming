#include <iostream>
using namespace std;
#include<stdlib.h>
#include<climits>
#include <vector>
const int N = 1e5+10;
int arr[N];
vector<int>dp(N,-1);
 
 int fun(int i){
   if(i == 0) return 0;
   if(dp[i] != -1) return dp[i];
    int cost = INT_MAX;
    cost = min(cost,fun(i-1)+abs(arr[i]-arr[i-1]));
    if(i>1){
        cost = min(cost,fun(i-2)+abs(arr[i]-arr[i-2]));
    }
    return dp[i] =  cost;
 }
 int iterative(int n){
     vector<int>dp(N,0);
     for(int i = 1;i<n;i++){
        int cost = dp[i-1]+abs(arr[i]-arr[i-1]);
        if(i>1){
            cost = min(cost,dp[i-2]+abs(arr[i]-arr[i-2]));
        }
        dp[i] = cost;
     }
     return dp[n-1];

 }
int main()
{
     
     int n;
     cin>>n;
    
     for(int i = 0;i<n;i++){
        cin>>arr[i];
     }
    cout<<fun(n-1)<<endl;
   cout<<iterative(n)<<endl;


    return 0;
}
