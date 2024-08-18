#include<iostream>
using namespace std;
#include<vector>
#include<map>
bool solv(string str,vector<int>v,int n){
    map<char ,int>m;
    if(str.length()!=n){
        return false;
    }
    for(int i = 0;i<str.length();i++){
        if(m.find(str[i])==m.end()){
            m[str[i]] = v[i];
        }
        else {
            if(m[str[i]] != 
            
            v[i]) return false;
        }
    }
    return true;
}
int main(){
 int t;
 cin>>t;
 while(t--){
    int n;
    cin>>n;
    vector<int>num(n);
    for(int i = 0;i<n;i++){
        cin>>num[i];
    }
     int m;
     cin>>m;
     vector<string>str;
     for(int i = 0;i<m;i++){
         string s;
         cin>>s;
         str.push_back(s);
     }
     for(int i = 0;i<str.size();i++){
        bool ans = solv(str[i],num,n);
        if(ans == true){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
     }
 }
}