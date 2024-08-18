#include<iostream>
using namespace std;
#include<vector>
#include<set>
const int N = 1e6+10;
vector<bool>isPrime(N,1);
vector<int>lp(N,0);
vector<int>pref(N,0);
long long solv(){
     long long k;
     cin>>k;
     if(isPrime[k]){
       
         return  pref[k]*1LL*k;
     }
     else{
        
        long long x = lp[k];
      
      return pref[x]*k;
     }
}
int main(int argc, char const *argv[])
{
    isPrime[0] = isPrime[1] = false;
    for(long long i = 2;i*i<N;i++){
        
        if(isPrime[i]){
             lp[i] = i;
        for(long long j = 2*i;j<N;j+=i){
              isPrime[j] = false;
              if(lp[j] == 0) lp[j] = i;

        }
        }
    }
    long long prefsum = 0;
    for(long long i = 2;i<N;i++){
        if(isPrime[i]){
            prefsum+=i;
        }
        pref[i] = prefsum;
    }
    int t;
    cin>>t;
    while(t--){
      long long ans = solv();
      cout<<ans<<endl;
    }
    return 0;
}
