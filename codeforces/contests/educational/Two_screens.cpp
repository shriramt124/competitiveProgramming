#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    string t;
    cin>>t;
    string minString;
    string maxString;
    if(s.size()>t.size()){
    maxString = s;
    minString =t;
    }else{
      maxString = t;
      minString = s;
    }
    int count = 0;
    //find the longest common prefix 
    for(int i = 0;i<minString.size();i++){
      if(minString[i]==maxString[i]){
        count++;
      }else{
        break;
      }
    }
    count  =count>0?count-1:count;
    int ans = maxString.size()+minString.size()-count;
    cout<<ans<<endl;

  }
  return 0;
  
}