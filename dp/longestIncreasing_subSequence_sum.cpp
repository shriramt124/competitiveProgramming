#include<iostream>
using namespace std;
#include<vector>
#include<climits>
/* 
let us say i want to find the longest increasing subsequence sum from 0 to n in array 

//and sumilary from n-to 0
 */

 
vector<int>longIncreSubSeqFromItoN(vector<int>&arr,int n){

//dp[i] represents the longest increasing subsequence sum from n to i
    vector<int>dp(n,0);
     for(int i = n-1;i>=0;i--){
            int sum  = 0;
            for(int j = n-1;j>i;j--){
                if(arr[i]>arr[j])
                sum = max(sum,dp[j]);
            }
            dp[i] = arr[i]+sum;
        }
    return dp;
}
vector<int>longestIncreasingSubsequenceSum(vector<int>&arr,int n){
   
   //dp[i] --> represent the maximum increasing subsequence sum from 0 -->i 

   vector<int>dp(n,0);
   for(int i = 0;i<n;i++){
    int sum = 0;
    for(int j = 0;j<i;j++){
        if(arr[j]<arr[i]){
        sum = max(sum,dp[j]);
        }
    }
    dp[i] = arr[i]+sum;
   }
   return dp;
}


int main(){
      int n;
      cout<<"Enter the size of the array "<<endl;
      cin>>n;
      vector<int>arr(n);
      for(int i = 0;i<n;i++){
        cin>>arr[i];
      }

 
  
  // vector<int>ans = longestIncreasingSubsequenceSum(arr,n);
   vector<int>ans = longIncreSubSeqFromItoN(arr,n);
   for(auto ele:ans){
    cout<<ele<<" ";
   }cout<<endl;

   
    return 0;
}