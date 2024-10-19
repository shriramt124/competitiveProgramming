#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

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
    
    int count = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] == i+1) count++;
    }
    if(count <= 1) cout<<count<<endl;
    else
    {
        if(count%2 == 0){
            cout<<count/2<<endl;
        }else{
             cout<<(count/2+1)<<endl;
        }
    }
    }
    return 0;
    

}