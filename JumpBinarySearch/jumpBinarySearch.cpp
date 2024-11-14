#include<iostream>
#include<vector>
using namespace std;
void JumpBinarySearch(vector<int>arr,int target){
    int n = arr.size();
    int low = 0;
    for(int jump = n/2;jump >= 1 ;jump--){
        
        while(low+jump < n and arr[low+jump]<=target){
         low+=jump;
        }
    }
    if(arr[low] == target){
        cout<<"target is present in the array "<<target<<endl;
        return ;
    }
    //otherwise we will get after the low 
    //otherwise it will guarantee that either the target is present after the low or not present 
    for(int i= low;i<n;i++){
        if(arr[i] == target){
            cout<<"We found the elment at position : "<<i<<endl;
            return;
        }
    }
    cout<<"Element is not present in the array "<<endl;
    return;
    
   
}
int main(){
int n;
cin>>n;
vector<int>arr(n);
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
int target;
cout<<"Enter the value you want to find in the array "<<endl;
cin>>target;
 JumpBinarySearch(arr,target);
 
return 0;
}