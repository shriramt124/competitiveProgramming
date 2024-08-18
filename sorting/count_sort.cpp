#include<iostream>
using namespace std;
#include<vector>
void countSort(vector<int>&arr){
    /* 
     1. find max element 
     2.create the freq array of size max+1
     3.calculate the cumulative freq of freq array 
     4.now create the ans array of size n 
     5.traverse the original array from end and do arr[--freq[arr[i]]] = arr[i];
     6.copy the ans array to orignal array 

     */
    int n = arr.size();
    int maxi= INT16_MIN;

    for(int i = 0;i<n;i++){
        maxi = max(maxi,arr[i]);
    }
  
    vector<int> freq(maxi+1,0);
    for(int i = 0;i<n;i++){
        freq[arr[i]]++;
    }
  
    //calculating the cumulative freq of freq array 
    for(int i = 1;i<=maxi;i++){
        freq[i] = freq[i]+ freq[i-1];
    }
  
   vector<int>ans(n);
    for(int i = n-1;i>=0;i--){
         ans[--freq[arr[i]]] = arr[i];
    }
    for(int i = 0;i<n;i++){
        arr[i] = ans[i];
    }


}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"original array is : "<<endl;
    for(auto ele:arr){
        cout<<ele<<" ";
    }cout<<endl;
     countSort(arr);
     cout<<"array after count sort is : "<<endl;
     for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
     }cout<<endl;
    return 0;
}
