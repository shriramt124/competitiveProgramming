#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<climits>
#define int long long

signed main(){
    int n;
    cin>>n;
    int ans = INT_MIN;
    int sum = 0;
    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(int i = 0;i<n;i++){
        sum+=arr[i];
         ans = max(ans,sum);
         if(sum<0){
             sum = 0;
         }
    }
    cout<<ans<<endl;

    return 0;
}