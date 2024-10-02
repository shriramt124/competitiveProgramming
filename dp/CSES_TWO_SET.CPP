#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<algorithm>
#include<cmath>
#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi 3.141592653589793

#define pii pair<int,int>
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define vpi vector<pair<ll,ll>>
#define vvpi vector<vector<pair<ll,ll>>>
#define vpii vector<pair<int,int>>
#define vvpii vector<vector<pair<int,int>>>

#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()

#define endl '\n'
const int MOD = 1e9+7;
ll Total_sum = 0;

 

ll solv(ll n, ll currSun,vector<vector<ll>>&dp)
{
    if (currSun == 0)
    {
        return 1;
    }
     
     if(n<0 || currSun <0){
        return 0;
     }
    if(dp[n][currSun] != -1){
        return dp[n][currSun];
    }

    return   dp[n][currSun] = (solv(n - 1, currSun - n,dp)%MOD + solv(n - 1, currSun,dp)%MOD) % MOD;
}

ll solvTab(ll n, ll sum) {
    // DP table with n+1 rows and sum+1 columns initialized to 0
    vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1, 0));

    // Base case: there is 1 way to make a sum of 0 (by choosing no elements)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Tabulation: Fill the dp table
    for (int num = 1; num <= n; num++) {
        for (int currSum = 0; currSum <= sum; currSum++) {
            // Case 1: Exclude the current number
            dp[num][currSum] = dp[num - 1][currSum] % MOD;
            
            // Case 2: Include the current number if possible
            if (currSum - num >= 0) {
                dp[num][currSum] = (dp[num][currSum] + dp[num - 1][currSum - num]) % MOD;
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
   
    Total_sum = (n * 1LL * (n + 1) / 2) % MOD;
    if (Total_sum % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    // vector<vector<ll>>dp(n+1,vector<ll>(Total_sum+1,-1));
    
    ll currsum = Total_sum/2;
    // ll ans = solv(n, currsum,dp);
    //  ans =  (ans * 1LL *((MOD+1)/2))%MOD;
    //  cout<<ans<<endl;
    ll ans = solvTab(n,currsum);
    ans = (ans *1LL *(MOD+1)/2)%MOD;
    cout<<ans<<endl;

    return 0;
}