#include<bits/stdc++.h>
using namespace std;
#define int long long

int TraverseByRamFromTOpLeftTOBottomRIght(vector<vector<int>>&arr){
    int n = arr.size();
    
    int count  = 0;
    for(int diagonal = 0;diagonal<n;diagonal++){
        int i = 0;
        int j = diagonal;
         int mini = 0;
        
        while(i<n and j<n){
           mini = min(mini,arr[i][j]);
           i++;
           j++;
        }

        if(mini<0){
            count+=abs(mini);
        }

    }
    return count;

}

int TraverseFromBottomToTOp(vector<vector<int>>&arr){
    int n = arr.size();
    int count = 0;
    
    for(int diagonal = 1;diagonal<n;diagonal++){
        int i = diagonal;
        int j = 0;
         int mini = 0;
         while(i< n and j<n){
            mini = min(mini,arr[i][j]);
            i++;
            j++;
         }
         if(mini < 0){
            count+=abs(mini);
         }
    }
    return count;


}

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>arr(n,vector<int>(n));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin>>arr[i][j];
            }
        }

        int operation1 =  TraverseByRamFromTOpLeftTOBottomRIght(arr);
        int operation2 = TraverseFromBottomToTOp(arr);
        cout<<(operation1+operation2)<<endl;
    }
    return 0;
}