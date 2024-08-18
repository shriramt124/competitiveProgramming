#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

void solv(int *arr,int n){
    sort(arr,arr+n);
     for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
     }cout<<endl;
}
int main(int argc, char const *argv[])
{
    int arr[5] = {2,1,3,2,5};
    // int n = 5;
    // solv(arr,n);
    // for(int i = 0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;
    set<int>s;
    for(int i = 0;i<5;i++){
        s.insert(arr[i]);
    }
    cout<<s.size();
    for(auto ele : s){
        cout<<ele<<endl;
    }

    return 0;
}
