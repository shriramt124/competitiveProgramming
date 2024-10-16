#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    int a,b,n;
    cin>>a>>b>>n;
    vector<int>arr(n);
    for(int i = 0;i<n;i++) cin>>arr[i];
    int initialValue = b;
    int sum = b-1;
    for(int i = 0;i<n;i++){
        sum = sum + min(a-1,arr[i]);
    }

    cout<<sum+1<<endl;
    }

}