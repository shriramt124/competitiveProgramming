#include<iostream>
#include<vector>
using namespace std;
const int modu = 1e9+7;
 
//count the no of ways to make the sum n by making the dice one or more times

//using recursion
/* int SumRecur(int n){
    if(n == 0) return 1;
    if(n<0) return 0;
    
    int ans = SumRecur(n-1)+SumRecur(n-2)+SumRecur(n-3)+SumRecur(n-4)+SumRecur(n-5)+SumRecur(n-6);
    return ans;
} */
//using dp 
//dp[i] ==> total no of ways to make sum upto 1 
//transition = > dp[i] = sum of dp[i-k] where k = 1 to 6
int sumDp(int n,vector<int>&dp){
     if(n == 0) return 1;
     if(n<0) return 0;
     if(dp[n] != -1) return dp[n];
     
     dp[n] = 0;
     for(int i = 1;i<=6;i++){
        dp[n] =( dp[n] +sumDp(n-i,dp))%modu;
     }
     return dp[n];
}

int sumIterative(int n,vector<int>dp){
    
    dp[0] = 0;
    for(int i = 1;i<=n;i++){
      dp[i] = 0;
      for(int j = 1;j<=6;j++){
         if(i-j >=0 ){
            dp[i] = (dp[i] + dp[i-j])%modu;
         }
      }
    }
    return dp[n];

}

int main(){
    int n;
    cin>>n;
 /*    
    cout<<"USing recursion "<<SumRecur(n)<<endl; 
    
 */
    vector<int>dp(n+1,-1);
    int ans = sumDp(n,dp)%modu;
    cout<<ans<<endl;

    return 0;
    
}
