#include<bits/stdc++.h>
using namespace std;

void solvByRam(){
 int n;
        cin>>n;
        vector<int>arr(n+1);
        for(int i = 1;i<=n;i++){
            cin>>arr[i];
        }
        int count = 0;
        for(int i = 2;i<=n/2;i++){
            if(arr[i] == arr[i-1] || arr[n-i+1] == arr[n-i+2]){
                swap(arr[i],arr[n-i+1]);
              
            }
        }
        
        for(int i = 2;i<=n;i++){
            if(arr[i] == arr[i-1]) count++;
        }
        cout<<count<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solvByRam();

    }
}