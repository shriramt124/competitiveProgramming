#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#define int long long
const int N = 1e5+5;

vector<int>pref(N,0);
vector<int>suffix(N,0);


/* 

Key Point: The GCD of a set depends on the common divisors among the elements. Replacing an element with a higher value wouldn't increase the GCD because the higher value may not share any common divisors with the rest of the elements.

The prefix and suffix GCD arrays allow us to check what happens when each element is removed and compute the GCD for the rest of the array efficiently.



 */

signed main(){
    int n;
    cin>>n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
     
    for(int i = 1;i<=n;i++){
        pref[i] = __gcd(pref[i-1],v[i]);
    }
    for(int i = n;i>=1;i--){
        suffix[i] = __gcd(suffix[i+1],v[i]);
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        ans =  max(ans,__gcd(pref[i-1],suffix[i+1]));
    }
    cout<<ans<<endl;

   
}