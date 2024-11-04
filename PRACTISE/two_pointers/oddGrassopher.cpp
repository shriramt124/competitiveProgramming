#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;
    while(t--){
        int x,n;
        cin>>x>>n;
        int rem = n%4;
        if(rem == 0){
            cout<<x<<endl;
            continue;
        }
        int i = n-rem+1;
       

        while(i<=n){
            if(x%2 == 0){
            x = (x)-(i);
           
            }else{
                x =(x)+(i);
               

            }
            i++;
        }

        cout<<x<<endl;
    }
    return 0;
}