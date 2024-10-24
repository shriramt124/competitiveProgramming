#include<bits/stdc++.h>
using namespace std;
#define int long long 
int t;


signed main(){
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n+1);
        unordered_map<int,int>m;
        for(int i = 1;i<=n;i++){
            cin>>arr[i];
            m[arr[i]] = i;
        }
        int count = 0;
        for(int i = 1;i<=n;i++){
             if(arr[i] == i){
                continue;
             } 
             if(arr[i]!= i){
                if(arr[arr[i]]!=i){
                  //  cout<<"swapping : "<<arr[arr[i]]<<" "<<arr[m[i]]<<endl;
                    int arrarrivalue = arr[arr[i]];
                    int mi = m[i];
                   swap(arr[arr[i]],arr[m[i]]);
                    int prevIdx = mi;
                    m[i] = arr[arr[i]];
                    m[arrarrivalue] = prevIdx;
                   count++;
                }
                else {
                    continue;
                }
             }
        }
        cout<<count<<endl;


    }
    return 0;
}