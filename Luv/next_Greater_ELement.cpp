#include<iostream>
#include<stack>
using namespace std;
#include<algorithm>
#include<vector>
void solv(vector<int>arr,int n){
    stack<int>st;
    vector<int>v(n,-1);
    st.push(-1);
    st.push(arr[n-1]);
    for(int i = n-1;i>=0;i--){
        
        while(st.top()<=arr[i] and st.top()!=-1){
            st.pop();
        }
        v[i] = st.top();
        st.push(arr[i]);
    }
    // print the array
    for(int i = 0;i<n;i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
     vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    solv(arr,n);
    return 0;
}
