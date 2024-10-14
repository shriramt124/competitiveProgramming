#include<bits/stdc++.h>
using namespace std;\

#define int long long
 

signed main(){
    int n,t;
    cin>>n>>t;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int ans = 0;
    int start=  0;
    int end = 0;
    int sum = 0;
    while(end<n){
        sum+=arr[end];
        while(sum>t){
            sum-=arr[start];
            start++;
        }
        ans = max(ans,end-start+1);
        end++;

    }
    cout<<ans<<endl;

    

    return 0;
}