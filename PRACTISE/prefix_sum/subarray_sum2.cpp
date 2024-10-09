#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <cmath>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#define ll long long
#define ull unsigned long long
#define cint const int &
#define Pi 3.141592653589793

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
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    ll n, x;
    cin >> n >> x;
    vi arr(n + 1);
    
     ll prefix = 0;
     map<ll, ll> m;
     m[0] =1;
     ll count = 0;
    for(ll i = 1;i<=n;i++)
    {
        cin >> arr[i];
       prefix += arr[i];
       if(m.find(prefix-x) != m.end()){
           count += m[prefix-x];
       }
       m[prefix]++;

    }
    cout<<count<<endl;
   

    return 0;
}