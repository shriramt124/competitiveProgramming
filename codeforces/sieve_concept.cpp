#include<iostream>
using namespace std;
#include<vector>
#include<set>
using ll = long long;
const int N  = 1e7+10;
 vector<bool>isPrime(N,1);
//t prime is a number which have exactly 3 positive different divisors
//square of a prime number is t-prime number
//2*2-_>4 --> 1 2 4

//alternat approach is to find all the factors of a number and if it have only 3 factors then it is a t-prime otherwise not
//but this approach is not good for large test cases 


//step 1 precompute all the prime numbers

//step 2 do the square of those prime numbers and store them in the set 

//now from the array check of any number is the square of the prime number and found in set then it is a t-prime otherwise not


int main(int argc, char const *argv[])
{
     long long n;
     cin>>n;
     vector<long long>arr(n);
     for(int i = 0;i<n;i++){
        cin>>arr[i];
     }
     isPrime[0] = isPrime[1] = false;
     set<long long>st;
     for(int i = 2;i<N;i++){
         if(isPrime[i]){
            for(int j = 2*i;j<N;j+=i){
                isPrime[j] =false;
            }
            st.insert(i*1LL*i);

         }
     }
     for(auto ele:arr){
        if(st.find(ele)!=st.end()){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
     }

     


    return 0;
}
