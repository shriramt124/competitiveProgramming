#include<iostream>
using namespace std;
#include<vector>
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
       vector<int>arr(n);
       bool isFoundK = false;
       for(int i = 0;i<n;i++){
        cin>>arr[i];
        if(arr[i] == k)
        isFoundK = true;
       }
       
       if(isFoundK){
        cout<<"yes"<<endl;
       }else{
        cout<<"no"<<endl;
       }
      
    
    }
    return 0;
}
