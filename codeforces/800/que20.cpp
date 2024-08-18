#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
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
        int maxi = *max_element(arr.begin(),arr.end());
       
          //1 2 4 5 3
          //4 3 1 0 2 
          //5 4 2 1 3 
 
          //2 3 1 5 4
          //3 2 4 0 1
          //4 3 5 1 2

          //3 2  1
          //1 2  3
 
          //1   (2-prev+1)=1  (4-prev(3)+1)=2  abs(5-prev(6))+1 = 2 abs(3-prev(7))+1
          vector<int>ans(n);
          
         
 
          for(int i = 0;i<n;i++){
             ans[i] = (maxi-arr[i])+1;
          }
          
           
 
          for(auto x:ans){
            cout<<x<<" ";
          }cout<<endl;
 
    }
    return 0;
}