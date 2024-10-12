#include<bits/stdc++.h>
using namespace std;
static bool cmp(string &a ,string &b){
    return a+b < b+a;
}

int main(){
     int n;
     cin>>n;
     string str = "";
     vector<string>v(n);
     for(int i = 0;i<n;i++){
        cin>>v[i];
     }
     sort(v.begin(),v.end(),cmp);
     for(int i = 0;i<n;i++){
        str+=v[i];
     }
     cout<<str<<endl;

    return 0;
}
