#include<iostream>
using namespace std;

void BubbleSort(int arr[],int length){
    for(int i = 0;i<length-1;i++){
        bool flag = true;
        for(int j = 0;j<length-1-i;j++){
               if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = false;//if swapping then it will become false

               }
               if(flag){//if no swapping break the loop and our array is sorted
                break;
               }
        }
    }

  for(int i = 0;i<length;i++){
    cout<<arr[i]<<" ";
  }cout<<endl;
}
void printArray(int arr[],int length){
    for(int i = 0;i<length;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main(){
    int arr[] = {23,12,21,10,5,67};
    int length = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original array: ";
    printArray(arr,length);

    BubbleSort(arr,length);
}