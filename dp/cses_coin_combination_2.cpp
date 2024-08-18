#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> coins(n);
    for(int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(x+1));
   // dp[i][k] = number of ways to make sum k such that all coins before coin[i] are unusable and all coins from i to n-1 are usable 
    //base case
    for(int i = 0;i<=n;i++){
        dp[i][0] = 1;
    }

    for(int i = n-1;i>=0;i--){
        for(int sum =1;sum<=x;sum++){
            int skipping = dp[i+1][sum];
            int picking = 0;
            if(sum >=coins[i]){
                picking = dp[i][sum-coins[i]];
            }
            dp[i][sum] = (skipping+picking)%MOD;
        }

    }
    cout<<dp[0][x]<<endl;
    
    return 0;
}
