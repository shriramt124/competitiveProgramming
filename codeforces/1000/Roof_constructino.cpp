#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/* 
https://codeforces.com/problemset/problem/1632/B
*/
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        n--;
        long long msb = log2(n);
        long long num = pow(2,msb)-1;
        vector<long long>ans;
        while(num>=0){
            ans.push_back(num);
            num--;
        }
        num = pow(2,msb);
        while(num<=n){
            ans.push_back(num);
            num++;
        }
        for(auto ele:ans){
            cout<<ele<<" ";
        }cout<<endl;
    }
    return 0;
}