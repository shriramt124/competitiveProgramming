#include<bits/stdc++.h>
using namespace std;
/* https://codeforces.com/problemset/problem/1794/B */


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            if(arr[i] ==1) arr[i] = arr[i]+1;
        }
        //we have to perform the 2n operations
        //ek even ho and ek odd ho 
       for(int i = 0;i<n-1;i++){
        if(arr[i+1]%arr[i] == 0){
            arr[i+1]++;
        }
       }
        for(auto ele:arr){
            cout<<ele<<" ";
        }cout<<endl;
    }
    return 0;
}