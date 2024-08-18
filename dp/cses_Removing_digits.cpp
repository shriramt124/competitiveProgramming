#include<iostream>
using namespace std;
#include<vector>
#include<climits>

//dp[i] --> it represents the min number of steps to make i --> 0

//dp[i] = 1+min(dp[i-digits of x])

//base case
//dp[0] = 0;

//final solution dp[n]
int solv(int n,vector<int>&dp){
  if(n == 0){
    return 0;
  }
  if(dp[n] != INT_MAX){
    
    return dp[n];
  }

 
 int k = n;
 while(k!=0){
    int last_digit = k%10;
  
    if(last_digit!=0){
        dp[n] = min(dp[n],1+solv(n-last_digit,dp));;
    }
  
       k = k/10;
 }
 return dp[n];
}

int Recursive(int n,vector<int>&dp){
    dp[0] = 0;
    for(int i  = 1;i<=n;i++){
        int k = i;
        while(k!=0){
            int lastdigit = k%10;
            if(lastdigit != 0){
                dp[i] = min(dp[i],1+dp[i-lastdigit]);
            }
            k = k/10;
        }
    }
    return dp[n];
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int>dp(n+1,INT_MAX);
    dp.resize(n+1,0);
    dp[0] = 0;
//    int ans =  solv(n,dp);
int ans = Recursive(n,dp);
   cout<<ans<<endl;

    return 0;
}
