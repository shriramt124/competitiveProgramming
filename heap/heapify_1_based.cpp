#include<iostream>
using namespace std;
void heapify(int arr[],int&size,int curr){
        while(2*curr+1 < size){
        int leftchild = 2*curr+1;
        int rightchild = 2*curr+2;
        int minchild = leftchild;
      //  if(leftchild<size and arr[leftchild]<arr[minchild]) minchild = leftchild;
        if(rightchild<size and arr[rightchild]<arr[minchild]) minchild = rightchild;
            if(arr[curr]<arr[minchild]) return;
            swap(arr[minchild],arr[curr]);
            curr = minchild;
          } 
}

int main(int argc, char const *argv[])
{
    int arr[5] = {9,3,2,6,7};
    int size = 5;
     for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    for(int i = size/2-1;i>=0 ;i--){
        heapify(arr,size,i);
    }
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}
