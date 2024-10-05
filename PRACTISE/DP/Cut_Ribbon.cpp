
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
#include<climits>
#include<cmath>
#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi 3.141592653589793
#define int long long

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
vi dp(1e5,-1);


/* 

https://codeforces.com/problemset/problem/189/A

 */

int solv(int n,int a ,int b,int c){
   if(n == 0){
    return 0;
   }
   if(n<0){
    return 0;
   }
   if(dp[n] != -1){
  //  cout<<"it is running "<<endl;
    return dp[n];
   }
    //each piece will have the three options

    int one = INT_MIN,two = INT_MIN,three = INT_MIN;
    if(n>=a)
    one = 1+solv(n-a,a,b,c);
    if(n>=b)
    two= 1+solv(n-b,a,b,c);
    if(n>=c)
    three= 1+solv(n-c,a,b,c);
   // cout<<one<<" "<<two<<" "<<three<<"-->"<<n<<endl;
    dp[n] =  max(one,max(two,three));
    return dp[n];
}
signed main(){

   int n,a,b,c;
   cin>>n>>a>>b>>c;
   int ans = solv(n,a,b,c);
   cout<<ans<<endl;

    return 0;
}