#include<bits/stdc++.h>
using namespace std;
/* https://codeforces.com/contest/1606/problem/A */
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        str[str.size()-1] = str[0];
        cout<<str<<endl;

    }
    return 0;
}