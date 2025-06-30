#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int solv(int i,int j,string &s,string &t,vector<vector<int>>&dp){
   if(i<0 || j<0 ) return 0;
   if(dp[i][j] != -1) return dp[i][j];

   if(s[i] == t[j]){
      return  dp[i][j] = 1+solv(i-1,j-1,s,t,dp);
   } 

      return dp[i][j] =  max(solv(i-1,j,s,t,dp),solv(i,j-1,s,t,dp));
  

} 

void  solvTabulation(string &s,string &t){
   int n = s.size();
   int m = t.size();
   vector<vector<int>>dp(n+1,vector<int>(m+1,0));
   for(int i = 1;i<=n;i++){
      for(int j = 1;j<=m;j++){
         if(s[i-1] == t[j-1]){
            dp[i][j] = 1+dp[i-1][j-1];
         }else{
            dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
         }
      }
   }
      //pirnt the lcs 
      int i = n;
      int j = m;
      string str = "";
      while(i>0 and j>0){

         if(s[i-1] == t[j-1]){
         str+=s[i-1];
         i--;
         j--;
         }else if(dp[i-1][j] > dp[i][j-1]){
            //you are moving up in the dp array
            str+=s[i-1];
            i--;
           
         }else{
            str+=t[j-1];
            j--;
         }
      }
      while(j>0){
         str+=t[j-1];
         j--;
      }
      while(i>0){
         str+=s[i-1];
         i--;
      }
      reverse(str.begin(),str.end());
      cout<<"The Common supersubsequence is : "<<str<<endl;
}






void lcs(string &s,string &t){
      int n = s.size();
      int m = t.size();

      cout<<"max lcs length is : ";
      vector<vector<int>>dp(n,vector<int>(m+1,-1));

     // cout<<solv(n-1,m-1,s,t,dp)<<endl;;

    solvTabulation(s,t);

}


int main(){
   string s,t;
   cout<<"Enter string 1"<<endl;
   cin>>s;
   cout<<"Enter string 2"<<endl;
   cin>>t;
   lcs(s,t);


    
}