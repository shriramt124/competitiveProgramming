#include<iostream>
using namespace std;
#include<vector>
const int N = 1e7+10;
vector<bool>isPrime(N,1);
 

void bruteForce(vector<bool>isPrime,int N,vector<int>arr,int n){
 int count = 0;
        for(int i = 0;i<n-2;i++){
            for(int j = i+1;j<n-1;j++){
                for(int k = j+1;k<n;k++){
                 if(arr[i] == 1 and arr[j] == 1 and isPrime[arr[k]] == true){
                    count++;
                 }
                 else if(arr[i] == 1 and isPrime[arr[j]] == true and arr[k] == 1) count++;

                 else if(isPrime[arr[i]] == true and arr[j] == 1 and arr[k] == 1){
                    count++;
                 }

                }
            }
        }
        cout<<count<<endl;
}

void optimized(vector<bool>isPrime,int N,vector<int>arr,int n){
/* 
ai*aj*ak will be prime if exactly one is prime and others will be 
1. So for each prime in the array the contribution will be  xC2
 where x
 will be number of 1
 in the array. To find primes in the array you can use Sieve of Eratosthenes method.
 */


}
 

int main()
{
    isPrime[0] = isPrime[1] = false;
    for(int i = 2;i<N;i++){
        if(isPrime[i] == true){
            for(int j = 2*i;j<N;j+=i){
                isPrime[j] = false;
            }
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        int onecount = 0;
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            if(arr[i] == 1) onecount++;
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(isPrime[arr[i]]){
              ans += onecount*(onecount-1)/2;
            }
        }
        cout<<ans<<endl;
        
 

    }
}