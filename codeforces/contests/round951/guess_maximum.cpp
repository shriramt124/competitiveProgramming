#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
 

int main(int argc, char const *argv[])
{ 
     int t;
     cin>>t;
     while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        int minElement = INT8_MAX;
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            minElement = min(arr[i],minElement);
        }
        int ans = INT8_MAX;
        for(int i = 0;i<n-1;i++){
            int currentMax = max(arr[i],arr[i+1]);
            ans = min(ans,currentMax);
        }
        cout<<(ans-1)<<endl;
     }
}
