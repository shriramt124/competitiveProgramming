#include<iostream>
using namespace std;
#include<algorithm>
void rightMini(int arr[],int n){
    int maxi = 0;
    int mini  =arr[0];
    int b[n];
    b[0] = 0;
    for(int i = 1;i<n;i++){
        if(mini<arr[i]){
            if(arr[i] > arr[i-1]){
                mini = arr[i-1];
                b[i] = mini;
            }else{
            b[i] = mini;
            mini = arr[i];
            }
          
        }else{
            b[i] = b[i-1];//purana wala
            mini = arr[i];
        }
    }
    for(int i = 0;i<n;i++){
        cout<<b[i]<<" ";
    }cout<<endl;
}
int solv(int arr[],int n){
    int b[n];
    int k =n-1;
    int maxi = INT8_MIN;
    for(int  i = n-1;i>=0;i--){
        maxi = max(arr[i],maxi);
        b[k--] = maxi;
    }
    for(int i =0;i<n;i++){
        cout<<b[i]<<" ";
    }cout<<endl;
    int res = 0;
    for(int i = 0;i<n;i++){
        res = max(b[i]-arr[i],res);
    }
    return res;
    
}
int main(int argc, char const *argv[])
{
    int n;
    cout<<"no of elements in array"<<endl;
    cin>>n;
    cout<<"enter elements of array"<<endl;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    // int ans = solv(arr,n);
    // cout<<"anser is : "<<ans<<endl;

    rightMini(arr,n);
    return 0;
}
