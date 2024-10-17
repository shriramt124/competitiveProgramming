#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/* 
https://codeforces.com/problemset/problem/1850/D
 */
int main(){
    int t;
    cin>>t;
    while(t--){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i = 0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    int count = 1;
    int ans = 1;
    for(int i = 1;i<n;i++){
        if(arr[i]-arr[i-1] > k) count = 1;
        else {
            count++;
        }
        ans = max(ans,count);
    }
    cout<<(n-ans)<<endl;

    }
    return 0;
    
}