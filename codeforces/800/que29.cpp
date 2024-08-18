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
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        int count = 0;
        int i  = 0;
        while(i<n-1){
            if(arr[i]%2!=0 and arr[i+1]%2!=0  and i<n-1){
            while(arr[i]%2!=0 and arr[i+1]%2!=0 and i<n-1){
                count++;
                i++;
            }
            }
            if(arr[i]%2 == 0 and arr[i+1]%2 == 0 and i<n-1){
            while(arr[i]%2 == 0 and arr[i+1]%2 == 0 and i<n-1){
                count++;
                i++;
            }
            }
            else{
                i++;
            }
           

        }
      cout<<count<<endl;
    }
    return 0;
}
