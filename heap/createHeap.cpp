#include<iostream>
using namespace std;
int N = 1e3;
void insertMinHeap(int arr[],int& size,int val){
         size++;//size will increased to add value at the last
         arr[size] = val;
         int curr = size;
         while(curr/2>0 and arr[curr/2]> arr[curr]){
            swap(arr[curr/2],arr[curr]);//update the curr and it's parent
            curr = curr/2;
         }
}
void insertMaxHeap(int arr[],int &size,int val){
size++;
arr[size] = val;
int curr = size;
while(curr/2>0 and arr[curr/2]<arr[curr]){
    swap(arr[curr],arr[curr/2]);
    curr = curr/2;
}

}
void deleteMinHeap(int arr[],int &size){
    //we can always delete only the root node 
            arr[1] = arr[size];//swapping the first and last node and then we can delete the last node by doing size--
            size--;
            int curr = 1;
            while(curr*2 <= size){
                int leftchild = 2*curr;
                int rightchild = 2*curr+1;
                int minChild = leftchild;
                //check if the right child exist or not 
                if(rightchild <= size and arr[rightchild] < arr[minChild]){
                    minChild = rightchild;
                }
                 if(arr[minChild] >= arr[curr]){
                    return;
                 }
                 swap(arr[minChild],arr[curr]);
                 curr = minChild;
            }
}

void deleteMaxHeap(int arr[],int&size){
    arr[1] = arr[size];
    size--;
    int curr = 1;
    while(curr*2 <= size){
        int leftchild = curr*2;
        int rightchild = curr*2+1;
        int maxchild = leftchild;
        if(rightchild<=size and arr[rightchild] > arr[maxchild]){
            maxchild = rightchild;
        }
          if(arr[curr] >= arr[maxchild]) return;//no need to move becase it is already satisfying the property of maxheap
        swap(arr[curr],arr[maxchild]);
        curr = maxchild;
    }
}
int main(int argc, char const *argv[])
{
    int arr[N] = {-1,10,20,30,40,50};
    int size = 5;
    int val = 5;
    insertMinHeap(arr,size,val);
    for(int i = 0;i<=size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    int maxHeap[N] = {-1,60,50,40,30,20,30,10};
    int sze = 7;
    int value = 100;
    insertMaxHeap(maxHeap,sze,value);
         
    for(int i = 0;i<=sze;i++){
        cout<<maxHeap[i]<<" ";
    }cout<<endl;

    deleteMinHeap(arr,size);

    for(int i = 0;i<=size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    deleteMaxHeap(maxHeap,sze);
      for(int i = 0;i<=sze;i++){
        cout<<maxHeap[i]<<" ";
    }cout<<endl;

    return 0;
}
