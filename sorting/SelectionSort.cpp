#include<iostream>
using namespace std;
//repeatildly find the minimum element and place it at the begining of unsorted array 
void selectionSort(int arr[],int n){
    for(int i = 0;i<n-1;i++){
        int minIndex = i;//take the current element as minimum element
        for(int j = i+1;j<n;j++){//iterate over the left elements in the array
            
            //update the minimum index if we found the smaller element than the current element
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
           

        } 
        if(minIndex != i){
                swap(arr[minIndex],arr[i]);
            }
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
     selectionSort(arr,n);

    return 0;
}
