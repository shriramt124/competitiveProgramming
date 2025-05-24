#include<iostream>
#include<vector>
using namespace std;

 void merge(vector<int>&arr,int l,int r,int mid){
 int size1 = mid-l+1;
 int size2 = r-mid;
 vector<int>arr1(size1),arr2(size2);

 for(int i = 0;i<size1;i++) {
 arr1[i] = arr[l+i];
 }
 for(int i = 0;i<size2;i++){
 arr2[i] = arr[mid+1+i];
 }

 int k = l;
 int i  = 0;int j = 0;
 while(i<size1 && j<size2){
 if(arr1[i] <= arr2[j]){
   arr[k++] = arr1[i++];
 }else{
 arr[k++] = arr2[j++];}
 }

 //if somethign is left
 while(i < size1){
  arr[k++] = arr1[i++];
 }
 while(j<size2){
 arr[k++] = arr2[j++];
 }






 }
void mergeSort(vector<int>&arr,int l,int r){
   if(l >= r ) return;

   int mid = l + (r-l)/2;

     mergeSort(arr,l,mid);
     mergeSort(arr,mid+1,r);
     merge(arr,l,r,mid);

}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    mergeSort(arr,0,n-1);
    cout<<"after mergeSort the array is : "<<endl;

    for(auto ele:arr) cout<<ele<<" ";


        return 0;
}