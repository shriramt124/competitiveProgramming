#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5+10;
vector<int>divisors[N];

//we have to find all the divisors using sieve algorithm

int main(int argc, char const *argv[])
{
    for(int i = 2;i<N;i++){
        for(int j = i;j<N;j+=i){
             divisors[j].push_back(i);
        }
    }
    for(int i = 1;i<50;i++){
        for(auto divisor:divisors[i]){
            cout<<divisor<<" ";
        }cout<<endl;
    }
    
    return 0;
}
