#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
     
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            
        }
        int mini = arr[0];
       for(int i = 0;i<n;i++){
          mini = min(mini,mini&arr[i]);
       }
       cout<<mini<<endl;
    }
    return 0;
}