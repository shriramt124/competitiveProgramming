#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0;i<n;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        int MaxEle = arr.back();
        arr.pop_back();
        arr.insert(arr.begin(),MaxEle);
        vector<int>b(n);
        vector<int>c(n);
        b[0] = arr[0];
        c[0] = arr[0];
        for(int i = 1;i<n;i++){
          b[i]  = min(b[i-1],arr[i]);
          c[i] = max(c[i-1],arr[i]);
        }
        // for(auto ele:b) cout<<ele<<" ";
        // cout<<endl;
        // for(auto ele:c) cout<<ele<<" ";
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+=(c[i]-b[i]);
        }
        cout<<sum<<endl;

    
    }
    return 0;
}