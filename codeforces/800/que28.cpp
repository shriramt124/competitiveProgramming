#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
bool solv(vector<int>ans){
     int prefix = 0;
     for(int i = 0;i<ans.size();i++){
        if(prefix == ans[i]) return false;
        prefix+=ans[i];
     }
     return true;
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        vector<int> ans(n);
        int s = 0;
        int e = n - 1;
        int i = 0;
        while (s <= e)
        {
            ans[i++] = arr[s++];
            ans[i++] = arr[e--];
        }
        bool isPrefixSame = solv(ans);
        if(isPrefixSame){
            cout<<"YES"<<endl;
            for(auto ele:ans){
                cout<<ele<<" ";
            }cout<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
