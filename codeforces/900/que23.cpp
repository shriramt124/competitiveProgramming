#include<iostream>
using namespace std;
/* https://codeforces.com/contest/1582/problem/B */
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int ans  = 1*a+2*b+3*c;
        if(ans%2 == 0){
            cout<<0<<endl;
            continue;
        }else{
            cout<<1<<endl;
           
        }
        
    }
    return 0;
}