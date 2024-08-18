#include<iostream>
using namespace std;
const int N = 1e3;
void heapify(int arr[],int n,int curr){
    while(2*curr<=n){
        int leftchild = 2*curr;
        int rightchild = 2*curr+1;
        int maxchild = leftchild;
        if(rightchild<=n and arr[rightchild]>arr[maxchild]){
            maxchild = rightchild;
        }
        if(arr[maxchild]<arr[curr]) return;
        swap(arr[maxchild],arr[curr]);
        curr = maxchild;
    }
}
void remove(int arr[],int &size){
    if(size == 0) return;
    swap(arr[1],arr[size]);
    size--;
    heapify(arr,size,1);
}
void heapSort(int arr[],int n){
          //1.heapify all parents node into maxheap
          for(int i = n/2;i>0;i--){
            heapify(arr,i,n);
          }
          //2.extract max element from heap and put it at end of array
          while(n>0){
            remove(arr,n);
          }
}
int main(){
  int arr[N] = {-1,60,10,80,50,5,20,70};
  int n = 7;;
  heapSort(arr,n);
   for(int i = 1;i<=n;i++){
    cout<<arr[i]<<" ";
   }cout<<endl;

}