#include<bits/stdc++.h>
using namespace std;
#define int long long 

void solvByPalher(){
     int n;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        int sum = 0;
        int ram = 0;
        set<int>st;
        st.insert(0);
        for(int i = 0;i<n;i++){
         sum+=arr[i];
         if(st.count(sum)){
            ram++;
            st.clear();
            st.insert(0);
            sum = 0;
         }
         st.insert(sum);
        }
        cout<<ram<<endl;

}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solvByPalher();

    }
    return 0;
}