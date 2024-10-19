#include<iostream>
using namespace std;
#include<vector>
/* https://codeforces.com/problemset/problem/1869/A */
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0;i<n;i++) cin>>arr[i];
        if(n&1){
            //if n is odd then 4 operations is required
            cout<<4<<endl;
            cout<<1<<" "<<n-1<<endl;
            cout<<1<<" "<<n-1<<endl;
            cout<<n-1<<" "<<n<<endl;
            cout<<n-1<<" "<<n<<endl;

        }else{
            //in this case we only need two operations 
            cout<<2<<endl;
            cout<<1<<" "<<n<<endl;
            cout<<1<<" "<<n<<endl;
        }
    }
    return 0;
}