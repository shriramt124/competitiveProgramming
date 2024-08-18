#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int xoro = 0;
        for(int i = 0;i<n;i++){
            cin>>arr[i];
         xoro^=arr[i];
        }
        if(xoro == 0){
            cout<<0<<endl;
        }else{
            if(n%2 == 1){
                cout<<xoro<<endl;
            }else{
                cout<<(-1)<<endl;
            }
        }

    }
    return 0;
}
