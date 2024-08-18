#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/* 
given an array of integers and you have to find the pair who have minimum value if xor 
if there are multiple pairs return anyone of them 
*************** solutio**************
 inttution-->the closure the number the minimum will be the xor  so we will have to sort the array 
           
arr ->  3 5 7 8 10 12 13 

in the above array if the array is sorted then the element will come closer 
  
   now in the above array let's take 8 
   now 8 can give minimum xor either with 10 or 7 because they are the only closest element with 8 
   10    can give minimum xor either with 12 or 8 

   so we will apply the loop and we will increment the loop i+=2;

   time complexity -> O(n)






 */
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
   
   //sorting the array 
   
   sort(arr.begin(),arr.end());
     int mini = INT8_MAX;
     for(int i = 1;i<n-1;i++){
      int left = (arr[i]^arr[i-1]);
      int right =(arr[i]^arr[i+1]);
       int res = min(left,right);
       mini = min(mini,res);

     }

     cout<<"minimum xor vlaue is : "<<mini<<endl;
    return 0;
}
