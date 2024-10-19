#include<bits/stdc++.h>
using namespace std;
/* https://codeforces.com/contest/1726/problem/A */

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<int>arr(n);
      
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        int maxDiff = 0;
      for(int i = 0;i<n;i++){
        maxDiff = max(maxDiff,(arr[(i-1+n)%n]-arr[i]));

      }
       for(int i = 1;i<n;i++){
        maxDiff = max(maxDiff,(arr[i]-arr[0]));
       }
       for(int i = 0;i<n-1;i++){
        maxDiff = max(maxDiff,(maxDiff,(arr[n-1]-arr[i])));
       }
       cout<<maxDiff<<endl;


    }
    return 0;
}

/* 
There are four candidates of the maximum value of an−a1
 achievable, each of which can be found in O(n)
 time.

No subarray is chosen: Answer would be an−a1
 in this case.
Chosen subarray contains an
 and a1
 : Answer would be maxi=1n{a(i−1)−ai}
 where a0
 is same as an
 (notice that the previous case is included in this case as well).
Chosen subarray doesn't contain an
 : Answer would be maxi=1n−1{an−ai}
.
Chosen subarray doesn't contain a1
 : Answer would be maxi=2n{ai−a1}
.
Finally we report the maximum of all of these four values in total time O(n)
.

 */