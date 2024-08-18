#include<iostream>
using namespace std;
#include<vector>
#include<stack>
vector<int>nextSmaller(vector<int>arr,int n){
            //create a stack 
            stack<int>st;
            //for last element there is no smaller so put -1 at top 
            st.push(-1);
            //now traverse from last element to first and find the smaller element 
            vector<int>ans(n);
            for(int i = n-1;i>=0;i--){
            int curr = arr[i];
            //now find the smaller element is stack than it 
            while(st.top()!=-1 and st.top()>=curr){
                st.pop();
            }
            //it will reach here when on top of stack either -1 is present or smaller element than curr is present 
            ans[i] = st.top();
            st.push(curr);

            }
            return ans;
}

vector<int>prevSmallerElement(vector<int>arr,int n){
    //create a stack 
    //as there is no prevsmaller for first element so push  -1 in the stack 
    //traverse array from 0 to n-1 
    //take curr  = arr[i]
    //now check if top of stack is smaller than curr  or -1 othersize pop the top element 
    //push the curr element in stack 
    //return ans; 
    stack<int>st;
    st.push(-1);
    vector<int>ans(n);
    for(int i = 0;i<n;i++){
        int curr =  arr[i];
        while(st.top()!= -1 and st.top()>=curr){
         st.pop();
        }
        ans[i] = st.top();
        st.push(curr);

    }
    return ans;

}
int main(int argc, char const *argv[])
{
      vector<int>arr = {1,3,2};
      int n = arr.size();
      vector<int>ans1 = nextSmaller(arr,n);
      vector<int>ans = prevSmallerElement(arr,n);
      for(int i = 0;i<n;i++){
        cout<<ans[i]<<" ";
      }cout<<endl;
    return 0;
}
