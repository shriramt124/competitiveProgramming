#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n & 1 || n<4){
            cout<<"-1"<<endl;
        }else{
             n = n/2;
             int mini = n/3;
             mini+=(n%3 != 0 ? 1:0);
             cout<<mini<<" "<<n/2<<endl;
        }
    }

    return 0;
}