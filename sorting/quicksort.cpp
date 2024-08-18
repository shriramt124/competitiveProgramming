#include<iostream>
using namespace std;

int partition(int arr[],int left,int right){
    int pivot = arr[right];//taking last element as pivot element 

    int i = left-1;
    for(int j = left;j<=right;j++){
        if(arr[j]<pivot){//swap only if it is less than the pivot element
            i++;
            //swap the elements
            swap(arr[i],arr[j]);

        }
    }
     //now i pointing to the last element that is less than pivot 
        swap(arr[i+1],arr[right]);
        return i+1;
}
void quickSort(int arr[],int left,int right){
    if(left>=right){
        return;
    }
    //pivot position
    int pi = partition(arr,left,right);
    quickSort(arr,left,pi-1);
    quickSort(arr,pi+1,right);

}
int main(int argc, char const *argv[])
{
    int arr[] = {2,1,4,3,7,5,10};
    int length = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,length-1);
    for(int i = 0;i<length;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}
