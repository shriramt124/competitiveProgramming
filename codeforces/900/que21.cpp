#include<bits/stdc++.h>
using namespace std;
#define int long long
const vector<string>subseq = {"00","50","25","75"};
int solv(string &str,string &t){
    int i = str.size()-1;
    int count = 0;
    while(i>=0 && str[i]!= t[1]){
        
        count++;
        i--;
    }
    if(i<0) return 1000;
    int j = i-1;
    while(j>=0 && str[j] != t[0]){
         
        count++;
        j--;
    }
    if(j<0) return 1000;
    return count;


}
signed main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int ans = 1000;
        for(auto el:subseq){
             
        ans = min(ans,solv(str,el));
        }
        cout<<ans<<endl;
    }
    return 0;
}