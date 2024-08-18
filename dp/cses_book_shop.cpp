#include<iostream>
using namespace std;
#include<vector>
//dp[i][j] --> no of pages that you can read from books [0...i] such that you are allowd to sepent j coins 
//dp[i][j] = max(dp[i-1][j],dp[i-1][j-price[i]]+pages[i])-----> transition
//dp[0][j] = 0--> base case


 
//space optimized 
void optimized(vector<int>price,vector<int>pages,int n,int x){
    vector<int>prev(x+1,0);
    for(int i = 1;i<=n;i++){
        vector<int>curr(x+1,0);
        for(int j = 0;j<=x;j++){
         int w = pages[i-1];
         int value = price[i-1];
         int pick = (j>=w ? prev[j-w]+value:0);
         int skip = prev[j];
         curr[j] = max(pick,skip);
        }
        prev = curr;
    }
    cout<<prev[x]<<endl;
}
 
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>price(n);
    vector<int>pages(n);
    for(int i = 0;i<n;i++){
        cin>>pages[i];
    }
    for(int j = 0;j<n;j++){
        cin>>price[j];
    }
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=x;j++){
            
        int w = pages[i-1];
        int value = price[i-1];
         
         int pick = (j>=w ? dp[i-1][j-w]+value:0);
         int skip = dp[i-1][j];
         dp[i][j] = max(pick,skip);
        }
    }
    cout<<dp[n][x]<<endl;
   
     
    return 0;


}