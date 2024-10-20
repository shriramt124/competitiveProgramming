#include<bits/stdc++.h>
using namespace std;

#define khatam "\n"
#define bhago return
#define int long long

void solvByRam(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    int arrSum = 0;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        arrSum+=arr[i]; 
    }
    
    sort(arr.begin(),arr.end());
    if(arr[0]>=k) {
        cout<<k<<endl;
        return;
    }
    int extra = 0;
    int sum = 0;
    for(int i = 0;i<n;i++){
      int TotalAfterTakenaiOnly = arr[i]*(n-i);
      if(TotalAfterTakenaiOnly>=k){
         sum+=k;
         sum+=extra;
         cout<<sum<<endl;
         return;
      }
      else{
        sum+=arr[i];
        extra++;//on extra have to enter 
        k = k-arr[i];
      }

    }
    
    return;


}
signed main(){
  int t;
  cin>>t;
  while(t--){
    solvByRam();
  }

    return 0;
}