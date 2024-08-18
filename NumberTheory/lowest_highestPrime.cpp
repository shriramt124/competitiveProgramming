#include<iostream>
#include<vector>
using namespace std;
const int N = 1e7+10;
vector<int>isPrime(N,1);
vector<int>lp(N,0),hp(N,0);
int main(int argc, char const *argv[])
{ 
    isPrime[0] = isPrime[1] = false;
    for(int i = 2;i<N;i++){
        
        if(isPrime[i] == true){
             lp[i] = hp[i] = i;
             
            for(int j = 2*i;j<N;j+=i){
                isPrime[j] = false;
                hp[j] = i;
                if(lp[j] == 0){
                    lp[j] = i;
                }
            }
        }
    }
     int k;
     cin>>k;
     long long ans = 0;
     for(int i = 1 ;i<100;i++){
        cout<<lp[i]<<" "<<hp[i]<<" "<<endl;
     
     }
     cout<<ans<<endl;
    return 0;
}
