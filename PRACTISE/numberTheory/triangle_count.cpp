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
#define int long long
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

/* 
the problem says that a given array [bi,bi+1,bi+2,....bi+n]
so we can take an element x such that after selection bi and bi+1 and x it should form a traingle 
it means sum of two sides > sum of third side 

so i have to tell the different values of  x for all bi and bi+1    in arr

first sort the array 
then for all alternate pair a ,b the x = [b-a+1,b+a-1]
so we will cauculate all the range of x in pair of vectors and then we will sort that and then we will remove the 
overlapping intervals will give me different possible minum values of x  that can form a triangle 
 */


/* 
problem link --> 
https://www.codechef.com/problems/TRICOUNT1

 */

signed main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi arr(n);
        rep(i,0,n) cin>>arr[i];
        sort(arr.begin(),arr.end());
        vector<pair<int,int>>range;
        if(n == 1){
            cout<<0<<endl;
            continue;
        }
        rep(i,0,n-1){
            range.push_back({arr[i+1]-arr[i]+1,arr[i]+arr[i+1]-1});
        }
        sort(range.begin(),range.end());
        int ans = range[0].second-range[0].first+1;
        int mx = range[0].second;
        rep(i,1,n-1){
            int x = range[i].first;
            int y = range[i].second;
            if(x>mx){
                ans+=(y-x+1);
                mx = y;
            } else{
                if(y>mx){
                    ans+=(y-mx);
                    mx = y;
                    
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

