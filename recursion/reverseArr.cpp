#include<iostream>
using namespace std;
void reverse(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    swap(arr[l],arr[r]);
    reverse(arr,l+1,r-1);
}
void solv(int arr[],int i,int n){
    if(i>=n/2){
        return;
    }
    swap(arr[i],arr[n-i-1]);

    solv(arr,i+1,n);
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    // reverse(arr,0,n-1);
    solv(arr,0,n);
        for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}
