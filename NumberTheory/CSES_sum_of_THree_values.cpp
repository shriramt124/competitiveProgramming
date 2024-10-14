#include<bits/stdc++.h>
using namespace std;

#define int long long
signed main(){
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second = i+1;

    }
    sort(arr.begin(),arr.end());

    for(int i = 0;i<n;i++){
        int target = x-arr[i].first;
        int l = i+1;
        int r = n-1;
        while(l<r){
            if(arr[l].first+arr[r].first==target){
                cout<<arr[i].second<<" "<<arr[l].second<<" "<<arr[r].second<<endl;
                return 0;
            }
            else if(arr[l].first+arr[r].first<target){
                l++;
            }
            else{
                r--;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
   
}