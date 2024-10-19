#include<bits/stdc++.h>
using namespace std;

void solvByRam(){
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    map<int,int>m;
    for(int i = 0;i<n;i++) {
        cin>>arr[i];
        m[arr[i]] = i+1;
    }
    string str;
    cin>>str;
    while(q--){
        int idx;
        cin>>idx;
        //if element in that array is at the right position then there must be no 
        if(arr[idx] == idx){
            cout<<"NO"<<endl;
            return;
        }
        //if idx == L and element present in the array is less than idx then yes else no 

         if(str[idx] == 'L'){
            if(m[arr[idx]] < idx){
                cout<<"YES"<<endl;
                swap(arr[idx],arr[idx+1]);
                
            }else{
                cout<<"NO"<<endl;
            }
            return;
         }
        //if idx == R and elment present in the array is greater than the idx then yes else no 
        if(str[idx] == 'R'){
            if(m[arr[idx]] > idx){
                cout<<"YES"<<endl;
                swap(arr[idx],arr[idx-1]);
                
            }else{
                cout<<"NO"<<endl;
            }
            return;
        }
    }
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solvByRam();
    }
}