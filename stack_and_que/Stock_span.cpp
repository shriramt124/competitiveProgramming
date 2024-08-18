#include<iostream>
using namespace std;
#include<stack>
#include<vector>

class StockSpanner {
    vector<int>arr;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        arr.push_back(price);
        if(arr.size() == 1){
            return 1;
        }
          int size = arr.size();
          int i = size-1;
             int curr = arr[i];
             stack<int>st;
             st.push(curr);
             for(int j = i-1;j>=0;j--){
                if(arr[j]<=curr){
                    st.push(arr[j]);
                }else{
                    break;
                }
          
             ans =st.size();
        }
        return ans;
        
    }
};
int main(int argc, char const *argv[])
{
     StockSpanner* obj = new StockSpanner();
     cout<<obj->next(100)<<endl;
     cout<<obj->next(80)<<endl;
     cout<<obj->next(60)<<endl;
     cout<<obj->next(70)<<endl;
    return 0;
}

/* 
int main(int argc, char const *argv[])
{
      vector<int>arr = {100,80,60,70,60,75,85};
      int n = arr.size();
      vector<int>ans(n,0);
           for(int i = arr.size()-1;i>=1;i--){
            int curr = arr[i];
            stack<int>st;
            st.push(curr);
            for(int j = i-1;j>=0;j--){
                if(arr[j]<=curr){
                    st.push(arr[j]);
                }else{
                    break;
                }
            }
            ans[i] = st.size();
              
           }
           ans[0] = 1;
           for(auto ele:ans){
            cout<<ele<<" ";
           }
    return 0;
}
 */