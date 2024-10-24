#include<bits/stdc++.h>
using namespace std;
#define int long long

const int M = 1e9+7;


signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        n = n%M;
        int a = 0;
        int b = 1%k;
        int count = 1;
        while(b)
        {
        int c = (a+b)%k;
        a = b;
        b = c;
        count++;
        }
        //we have found the first zero and then the same pattern will repeast and we 
        //will find another zero at just 2*count 
        //we will find the nth zero at n*count 
        //0 1 1 --> 0 t t -> 0 b b similarly same pattern will repeat
        cout<<((n*count)%M)<<endl;
    }
    return 0;
}