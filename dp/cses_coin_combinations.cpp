#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
const int modu = 1e9+7;
vector<int>dp;

int solv(vector<int>&arr,int target){


    if(target == 0) return 1;
    if(target<0) return 0;
    if(dp[target] != -1){
     
        return dp[target];
    }
    int ans = 0;
    for(int i = 0;i<arr.size();i++){
        ans = (ans + solv(arr,target-arr[i]))%modu;
    }
    return dp[target] = ans;

}
int main(){

  int n,x;
  cin>>n>>x;
  dp.resize(x+1,-1);
 
  vector<int>v(n);
  for(int i = 0;i<n;i++){
    cin>>v[i];
  }
   
  int ans = solv(v,x);
  cout<<ans<<endl;
    return 0;
}