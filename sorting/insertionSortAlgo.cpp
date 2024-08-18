#include<iostream>
using namespace std;
void insertinSort(int arr[],int n){
/* 
1.consider first element is sorted
2.outer loop i = 1 to n-1 
3.take currEle = arr[i]
4.take j = i-1 //go one step backward
5.if the arr[j] is greater then currElement the move one step ahead to right 
6.if loop breaks then fill the element 
7.break out of outer loop
8.exit
 */
 
 for(int i = 1;i<n;i++){
    int currEle = arr[i];
     int j = i-1;
     while(j>=0 && arr[j]>currEle){
        //shift the arr[j] to one step ahead
        arr[j+1] = arr[j];
        j--;
     }
     arr[j+1] = currEle;
 }
    
      for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main(int argc, char const *argv[])
{
    
     int n;
     cout<<"enter the length of array"<<endl;
     cin>>n;
     int arr[n];
     for(int i = 0;i<n;i++){
        cin>>arr[i];
     }
        cout<<"original array is : ";
        for(int i = 0;i<n;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
     insertinSort(arr,n);
    return 0;
}
