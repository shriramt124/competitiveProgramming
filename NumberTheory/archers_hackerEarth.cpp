#include <iostream>
using namespace std;
#include<vector>
#include<numeric>
#include<algorithm>
#include<math.h>
const int M = 1e9+7;
/// @return https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/archery-1/
int main() {
	int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>arr(n);
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
         long long ans = 1;
        for(int i = 0;i<n;i++){
              long long gcd_val = __gcd(ans, arr[i]);
                ans = (ans*1LL*arr[i])/(gcd_val);


             
        }
        cout<<ans%M<<endl;


    }
}