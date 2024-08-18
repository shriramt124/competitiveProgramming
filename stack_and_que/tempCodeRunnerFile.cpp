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
                if(arr[i]<=curr){
                    st.push(arr[i]);
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
    return 0;
}