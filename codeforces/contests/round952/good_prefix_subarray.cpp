#include<iostream>
using namespace std;
#include<vector>
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>arr(n);
        for(long long i = 0;i<n;i++){
            cin>>arr[i];
        }
        vector<long long>prefix(n+1,0);
        prefix[0] = arr[0];
        for(long long i = 1;i<n;i++){
            prefix[i] = prefix[i-1]+arr[i];
        }
        long long count = 0;
        for(long long i = 0;i<n;i++){
            if(i>0 and prefix[i] !=prefix[i-1]){
            if(prefix[i]%2 == 0){
            for(long long j = 0;j<=i;j++){
                if(arr[j] == prefix[i]/2) count++;               
            }
            }
            }
        }
        cout<<count<<endl;

    }
    return 0;
}