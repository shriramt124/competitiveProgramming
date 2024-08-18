#include<iostream>
using namespace std;
#include<vector>
const int N = 1e7+10;
vector<bool>isPrime(N,1);
//inititally we have considered that all the numbers are prime
int main(int argc, char const *argv[])
{
    isPrime[0] = isPrime[1] = false;
    for(int i = 2;i<N;i++){
        if(isPrime[i] == true){


            
            for(int j = 2*i;j<N;j+=i){
                isPrime[j] = false;
            }
        }
    }
    //time complexisty = LogLog((N))
    for(int i = 1;i<100;i++){
        cout<<isPrime[i]<<" ";
    }cout<<endl;
    return 0;
}


