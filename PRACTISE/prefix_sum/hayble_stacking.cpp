#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#define ll long long

int main(){
    int n,k;
    cin>>n>>k;
 
    vector<int>prefix(n+1,0);
     while(k--){
       int a,b;
       cin>>a>>b;
       prefix[a]++;
       prefix[b+1]--;
     }
     for(int i = 1;i<=n;i++){
       prefix[i] += prefix[i-1];
     }
     sort(prefix.begin(),prefix.end());
     cout<<(prefix[n]/2)<<endl;

     return 0;
}