#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
bool allSame(vector<int>arr){

     //check if array is sorted or not 
      for(int i = 0;i<arr.size()-1;i++){
        for(int j = i+1;j<arr.size();j++){
            if(arr[i]>arr[j])
            return false;
        }
      }

 return true;

}
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
       if(n == 1 and k == 1) cout<<"YES"<<endl;
       else if(n>1 and k == 1){
        if(allSame(arr)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
       }else{
        cout<<"YES"<<endl;
       }

    }
    return 0;
}
