#include <iostream>
#include <algorithm>
// using  recursion
#include <vector>
#include <math.h>
using namespace std;

int lisRecusion(int i, vector<int> arr,vector<int>&dp)
{
    // initially ans = 1
    if(dp[i]!=-1) return dp[i];
    int ans = 1;
    for (int j = 0; j < i; j++)
    {
        if (arr[i] > arr[j])
        {
           
            ans = max(ans, lisRecusion(j,arr,dp) + 1);
        }
    }
    return dp[i] = ans;
}

//using Dynamic programming approach 

int main()
{
    int n = 8;
    vector<int>dp(n+1,-1);
    vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
    int ans = 0;
    //using recursion
   /*  for(int i = 0;i<n;i++){
    ans = max(ans,lisRecusion(i,v,dp));
    } */

   //using dp
   for(int i = 0;i<n;i++){
    ans = max(ans,lisRecusion(i,v,dp));
    }
    cout<<ans<<endl;
}