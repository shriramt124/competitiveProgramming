#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x = 0;
        int sum = 0;
        for(int i = 2;i<=n;i++){
            int k = n/i;
            int currSum = ((i+(i*1LL*k))*k)/2;
            if(currSum>=sum){
                x = i;
                sum = currSum;
            }
        }
        cout<<x<<endl;
    }
    return 0;
}