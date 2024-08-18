#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int N = 1e6+10;
vector<int>isPrime(N,1);
vector<int>lp(N,0);
vector<int>hp(N,0);
set<int>PrimeFactors(int num,vector<int>lp,vector<int>hp){
    
     set<int>prime_factors;
     while(num>1){
          int prime_factor = hp[num];
          while(num%prime_factor == 0){
               prime_factors.insert(prime_factor);
               num/=prime_factor;
          }
     }
     return prime_factors;
}
int main()
{
     int n;
      cin>>n;
     
    isPrime[0] = isPrime[1] = false;
    for(int i = 2;i*i<N;i++){
        
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
     
 
int count = 0;
for(int i = 1;i<=n;i++){
  set<int>prime  = PrimeFactors(i,lp,hp);   
  if(prime.size() == 2) count++;
}
cout<<count<<endl;
 
 
 
 
 
    return 0;
}