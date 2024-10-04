#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <limits>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <climits>
#define ll long long
#define ull unsigned long long
#define cint const int &
#define Pi 3.141592653589793
#define int long long

#define pii pair<int, int>
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define vpi vector<pair<ll, ll>>
#define vvpi vector<vector<pair<ll, ll>>>
#define vpii vector<pair<int, int>>
#define vvpii vector<vector<pair<int, int>>>

#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define endl '\n'
const int MOD = 1e9 + 7;

/*

https://codeforces.com/problemset/problem/363/B
 */

// int solv(int index, vector<ll> arr, int k, int sum, bool taken = false)
// {

//      int sum = 0;
//      if(taken and (index+k)<arr.size()){
//         for(int i = index;i<index+k;i++){
//            sum+=arr[i];
//         }
//      }

// }
signed main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n+1);
    rep(i, 1, n+1) cin >> arr[i];
    vi prefix(n+1);
   
    rep(i, 1, n+1) prefix[i] = prefix[i - 1] + arr[i];
    
    // rep(i,0,n+1) cout<<prefix[i]<<" ";
    cout<<endl;
    int start = 1;
    int end = k;
    int ans = prefix[end];
    int len = start;
    rep(end, k, n+1)
    {
        int res = prefix[end] - prefix[start - 1];
        if(ans > res){
            ans = res;
            len = start;
        }
        
        start++;
    }

    cout <<len<<endl;
}