#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#define int long long

signed main(){
int n;
cin>>n;
vector<int>arr(n+1);
map<int,int>mp;
 int sum = 0;
int count = 0;
mp[0] = 1;
for(int i = 1;i<=n;i++){
    cin>>arr[i];
    sum+=arr[i];
    count+=mp[(sum%n+n)%n];
    mp[(sum%n+n)%n]++;

    
}
cout<<count<<endl;
return 0;

}