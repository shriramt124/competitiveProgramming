#include <iostream>
#include <vector>
#include<queue>
#include<map>
using namespace std;
int solv(int n,int index,int ans,int &prev){
     
     if(index>n) return ans;
   
     int res = 1;
     for( int i = prev;i<prev+index;i++){
        
         res = res*i;
     }
       prev = prev+index;
     
     
     return solv(n,index+1,ans+res,prev);
     
  

}
 
int main() {
    
     int n = 4;
    int i = 1;
    int ans = 0;
    int prev = 1;
    int res = solv(n,i,ans, prev);
    cout<<res<<endl;

          


    return 0;
}
