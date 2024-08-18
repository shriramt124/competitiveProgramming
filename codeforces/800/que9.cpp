#include<iostream>
using namespace std;
#include<vector>
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        int minusSum = 0;
        int posSum = 0;
        for(int i = 0;i<n-1;i++){
            cin>>arr[i];
            if(arr[i]<=0){
                minusSum+=arr[i];
            }else{
                posSum+=arr[i];
            }

        }
        minusSum = -minusSum;
         if(posSum>minusSum){
            int res = -(posSum-minusSum);
            cout<<res<<endl;
         }else{
           cout<<abs(minusSum-posSum)<<endl;
         }
       

    }
    return 0;
}
