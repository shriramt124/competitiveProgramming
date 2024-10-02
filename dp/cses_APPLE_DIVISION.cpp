#include<iostream>
using namespace std;
#include<vector>
#define ll long long
 
ll n;
vector<ll>arr(23);
ll TOtalSum = 0;
ll solv(ll index = 0,ll currSum = 0){
 if(index >= n){
     ll other_set_sum = TOtalSum-currSum;
     return abs(currSum-other_set_sum);
 }

 ll take = solv(index+1,currSum+arr[index]);
 ll notTake = solv(index+1,currSum);
 return min(take,notTake);
}
int main()
{
    cin>>n;
   
    
    for(ll i = 0;i<n;i++){
        cin>>arr[i];
        TOtalSum+=arr[i];
    }
    ll ans = solv();
    cout<<ans<<endl;
     

    return 0;
}
