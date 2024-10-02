#include<iostream>
using namespace std;
#include<vector>
const int MOD = 1e9+7;


/* 
https://codeforces.com/problemset/problem/474/D
 */
#define int long long
vector<int>dp(100013,-1);
//dp[i] --> no of ways she can eat i flowers
int solvRec(int n,int k){
 if(n == 0){
    return 1;
 }
 if(n<0) return 0;
 return solvRec(n-k,k)+solvRec(n-1,k);

 //its time complexity is O(2^n *b)
}
int solvMemo(int n,int k){
    if(n<k) return 1;
   if(dp[n] != -1){//it means it has been calculated already
    return dp[n];
   }
    return dp[n] = (solvMemo(n-k,k)+solvMemo(n-1,k))%MOD;

    //TIME complexity is O(b^2)
}


signed main(){
      int t,k;
      cin>>t>>k;
      vector<int>prefix(100013);
      prefix[0] =  1;
      for(int i = 1;i<100013;i++){
        prefix[i] = ((prefix[i-1])+solvMemo(i,k))%MOD;
      }

      while(t--){
        int a,b;
        cin>>a>>b;
        // int sum = 0;
      //  for(int i = a;i<=b;i++){
          // sum+=solvRec(i,k);
         // sum = (sum + solvMemo(i,k))%MOD;
         cout<<((prefix[b]-prefix[a-1]+MOD)%MOD)<<endl;
       // }
    
      }
    return 0;
}
