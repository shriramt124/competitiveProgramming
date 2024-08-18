#include<iostream>
using namespace std;
int N = 1e3;

//max heapify 
void maxHeapify(int arr[],int size,int curr){
    while(2*curr <= size){
        int leftchild = 2*curr;
        int rightchild = 2*curr+1;
        int maxchild = leftchild;
        if(rightchild <= size and arr[rightchild] > arr[maxchild])
        maxchild = rightchild;

        if(arr[maxchild] <= arr[curr]) return;
        swap(arr[maxchild],arr[curr]);
        curr  = maxchild;
    }
}


//min heapify
void heapify(int arr[],int size,int curr){
         
         while(curr*2 <= size){
            int leftchild = curr*2;
            int rightchild = curr*2+1;
            int minchild = leftchild;
            if(rightchild <=size and arr[rightchild] < arr[minchild]){
                minchild = rightchild;
            }
            if(arr[minchild] >=arr[curr]) return;
            swap(arr[minchild],arr[curr]);
            curr = minchild;
         }
}
int main(int argc, char const *argv[])
{
    int arr[N] = {-1,60,10,80,50,5,20,70};
    int n = 7;
    for(int i = n/2;i>0;i--){
    heapify(arr,n,i);
    }
    for(int i = 0;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}
