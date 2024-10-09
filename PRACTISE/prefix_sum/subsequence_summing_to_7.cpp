#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<fstream>
#define ll long long
int main(){
    freopen("div7.in","r",stdin);
    freopen("div7.out","w",stdout);
    ll n;
    cin>>n;
    vector<ll>v(n+1);
    vector<ll>prefix(n+1,0);
    unordered_map<int,int>m;
    
    ll maxi = -1;
    for(ll i = 1;i<=n;i++){
        cin>>v[i];
        prefix[i] = (prefix[i-1]+v[i])%7;
        if(m.find(prefix[i]) == m.end()){
            m[prefix[i]] = i;
        }else{
            maxi = max(maxi,i-m[prefix[i]]);
        }
    }
    //just keep the remainder 
    //if the same remainder is present in two places then it means that between these two elements are divisible by 7
     cout<<maxi<<endl;
     
    return 0;
    

}