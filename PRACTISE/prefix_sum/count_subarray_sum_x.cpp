#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<climits>
#include<cmath>
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
int main(){
    ll n,x;
    cin>>n>>x;
    vi arr(n+1);
    vi prefix(n+1);
    rep(i,1,n+1){
        cin>>arr[i];
        prefix[i] = prefix[i-1]+arr[i];
    }
    ll count = 0;
    ll start = 0;
    ll end = 1;
    while(end<n+1){
      ll sum = prefix[end]-prefix[start];

      //if sum is equal to the x then just move start++;
      if(sum == x){
        count++;
        start++;
      }
      //if sum is greater than x then just move start++;
      else if(sum>x){
        start++;
      }
      //if sum is less than x then just move end++;
      else{
        end++;
      }

    }
    cout<<count<<endl;
     


}