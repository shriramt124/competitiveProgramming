#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>solv(int a[],int n){
    /* 
       two pointer approach use kiya hai 

       1.backsum and front sum ko compare karo 
       compare karke s aur e ko aage badhao 
       jahan par s aur e aake mil jayenge wahan tak ke dono sum me 
       front aur back sum me jo difference rahega wahi to number add karna hai 
       un s ya e position pe 
     */
     if(n == 1){
          return {a[0],2,2};
      }
         int frontsum = a[0];
         int backsum = a[n-1];
         int subarr = 0;
         int pos = 1;
         int s = 0;
         int e = n-1;
         while(s<e){
            if((backsum-frontsum)>0){
                 s++;
                 if(s == e){
                    pos = s+1;//s ek step already chal chuka hai to only s+1;
                    break;
                 }
                frontsum+=a[s];
                 
            }else{
              e--;
               if(s == e){
                pos = e+2;//e ek step peeche aa gaya to e+2;
                    break;
                   }
                backsum+=a[e];
                 
                   
            }

         }
         if(backsum<frontsum) {
            subarr = 2;
           
         }else{
             subarr = 1;
          
         }
         int res = abs(backsum-frontsum);
         return {res,pos,subarr};
        

}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans = solv(arr,n);
    for(auto ele:ans){
        cout<<ele<<" ";
    }cout<<endl;
    return 0;
}
