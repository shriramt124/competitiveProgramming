#include<iostream>
using namespace std;
#include<vector>

int main(int argc, char const *argv[])
{
     int n,q;
     cin>>n>>q;
     vector<int>arr(n+2,0);
     while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        arr[l] +=k;
        arr[r+1]-=k;
     }
     for(int i = 1;i<=n;i++){
        arr[i] = arr[i-1]+arr[i];
     }
     for(auto ele:arr){
        cout<<ele<<" ";
     }cout<<endl;
    return 0;
}
