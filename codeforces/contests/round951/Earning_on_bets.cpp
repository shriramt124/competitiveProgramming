#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
       long long  arr[n];
       
       for(int i = 0;i<n;i++){
        cin>>arr[i];
       }
       long long  lc = arr[0];
       vector<long long>ans(n);
       for(int i = 0;i<n;i++){
        long long numerator = lc*arr[i];
        long long denominator = __gcd(arr[i],lc);
        lc = numerator/denominator;
       }
       long long sum = 0;
       long long mini = 1e12;
       for(int i = 0;i<n;i++){
        ans[i] = lc/arr[i];
       sum+=ans[i];
       mini = min(mini,ans[i]*arr[i]);
       }
       if(sum<mini){
        for(auto ele:ans){
            cout<<ele<<" ";
        }cout<<endl;
       }
       else{
        cout<<"-1"<<endl;
       }
       
       

    }
    return 0;
}
