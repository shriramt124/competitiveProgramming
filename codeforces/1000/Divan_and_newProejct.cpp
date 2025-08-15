#include<bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1614/B


/* 

Obviously, the more often we have to go to the i
 building, the closer it should be to the main office.

This implies a greedy algorithm. Let's put the main office at 0
 and sort the rest by ai
. Then we put the most visited building at a point with a coordinate of 1
, the second at −1
, the third at 2
, etc.

The resulting asymptotics in time is O(nlogn)
.
*/

int  main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>a(n);
        for(long long i = 0;i<n;i++){
            cin>>a[i];
        }
        vector<pair<long long,long long>>m;
        for(long long i = 0;i<n;i++){
            m.push_back({a[i],i});
        }
        sort(m.rbegin(),m.rend());
        vector<long long>ans(n+1,0);
        ans[0] = 0;
        long long coordinate = 1;
        long long cost = 0;
        
        for(long long i = 0;i<n;i++){
          ans[m[i].second+1] = coordinate;
          cost+= 2*abs(coordinate)*m[i].first;
          if(coordinate < 0){
            coordinate = abs(coordinate)+1;
          }else{
            coordinate = -coordinate;
          }
        }
        cout<<cost<<endl;
        for(auto ele:ans){
            cout<<ele<<" ";
        }cout<<endl;
    }
    return 0;
}