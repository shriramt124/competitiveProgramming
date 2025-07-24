#include<iostream>
using namespace std;
#include<vector>
void factors(int n){
    //TC --> O(N)
    for(int i = 1;i<=n;i++){
        if(n%i == 0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
void factorsOptimize(int n){
    //TC--> O(squr(N))
    int countOfFactors = 0;
    int sumOfFactors = 0;
    for(int i = 1;i*i<=n;i++){
        if(n%i == 0){
        cout<<i<<" "<<n/i<<" ";
        countOfFactors+=1;
        sumOfFactors+=i;
        if(n/i != i){//in case of perfect squares we will have one common factor
        countOfFactors+=1;
        sumOfFactors+=n/i;
        }
        }
    }
    cout<<endl;
    cout<<sumOfFactors<<" "<<countOfFactors<<endl;
}

int primeFactors(int n){
    //TC --> O(N)

    vector<int>prime_fact;
    for(int i = 2;i<=n;i++){
         while(n%i == 0){
            prime_fact.push_back(i);
            n = n/i;
         }
    }
    for(auto ele:prime_fact){
        cout<<ele<<" ";
    }cout<<endl;
}
int primeFactorsOptimized(int n){
    //TC --> O(sqrt(N))
    vector<int>prime_fact;
    for(int i = 2;i*i<=n;i++){//square root se pahle kam se kam ek to prime factor hoga hi sahi
     //agar nahi hoga to wahi prime factor hoga
         while(n%i == 0){
            prime_fact.push_back(i);
            n = n/i;
         }                      
    } 

    if(n>1){
        prime_fact.push_back(n);
    }             
    for(auto ele:prime_fact){
        cout<<ele<<" ";
    }cout<<endl;
}
int main(int argc, char const *argv[])
{
    int n = 24;
    factors(n);
    factorsOptimize(36);
    primeFactors(36);
    primeFactorsOptimized(36);
    return 0;
}
