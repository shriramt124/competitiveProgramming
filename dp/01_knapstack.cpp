#include<iostream>
using namespace std;
#include<vector>

//using memoization
vector<vector<int>>dp(1000,vector<int>(1000,-1));
int maxProfitMemo(vector<int>weight,vector<int>profit,int bagWeight,int lenOfItems){
    if(lenOfItems == 0 || bagWeight == 0){
        return 0;
    }

    if(dp[lenOfItems][bagWeight] != -1){
        return dp[lenOfItems][bagWeight];
    }
    if(weight[lenOfItems-1]<=bagWeight){
    int profitBySelecting = profit[lenOfItems-1]+maxProfitMemo(weight,profit,bagWeight-weight[lenOfItems-1],lenOfItems-1);
    int profitWithoutSelecting = maxProfitMemo(weight,profit,bagWeight,lenOfItems-1);
    return dp[lenOfItems][bagWeight] = max(profitBySelecting,profitWithoutSelecting);
    }else{
        return dp[lenOfItems][bagWeight] = maxProfitMemo(weight,profit,bagWeight,lenOfItems-1);
    }
}
//using tabulation
int maxProfitTab(vector<int>weight,vector<int>profit,int capacity,int n){
    //1.create the dp
    vector<vector<int>>dp(n,vector<int>(capacity+1,0));
    //2.analyze the base case
     for(int w = 0;w<=capacity;w++){
        if(weight[0]<=w){
            dp[0][w] = profit[0];
        }else{
            dp[0][w] = 0;
        }
     }

     for(int i  = 1;i<n;i++){
        for(int w = 0;w<=capacity;w++){
            int include = 0;
            if(weight[i]<=w){
             include = profit[i]+dp[i-1][w-weight[i]];
            }
            int exclude = dp[i-1][w];
            dp[i][w] = max(include,exclude);
        }
     }

     return dp[n-1][capacity];



}



//using recursion
int maxProfit(vector<int>weight,vector<int>profit,int bagWeight,int lenOfItems){
    if(lenOfItems == 0 || bagWeight == 0){
        return 0;
    }
    //if weight less than bagWeight then we have two choice
    //1. either we can select that and put in our bag 
    //2. or we can reject that 
    //and we want to take the max profile by doing that
    if(weight[lenOfItems-1]<=bagWeight){
    int profitBySelecting = profit[lenOfItems-1]+maxProfit(weight,profit,bagWeight-weight[lenOfItems-1],lenOfItems-1);
    int profitWithoutSelecting = maxProfit(weight,profit,bagWeight,lenOfItems-1);
    return max(profitBySelecting,profitWithoutSelecting);
    }else{
        return maxProfit(weight,profit,bagWeight,lenOfItems-1);
    }
}
int main(){
 cout<<"enter the length of items you want to put in bag :"<<endl;
 int n;
 cin>>n;
 vector<int>profit(n);
 vector<int>weight(n);
 cout<<"enter weight and profit "<<endl;
 for(int i = 0;i<n;i++){
    cin>>weight[i];
    cin>>profit[i];
 }
 cout<<"enter the max capacity of the bag " <<endl;
 int bagWeight;
 cin>>bagWeight;
 //cout<<maxProfit(weight,profit,bagWeight,n);
//  cout<<maxProfitMemo(weight,profit,bagWeight,n);
 int ans = maxProfitTab(weight,profit,bagWeight,n);
 return 0; 

 
}