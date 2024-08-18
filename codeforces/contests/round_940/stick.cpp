#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        int maxi = *max_element(arr.begin(),arr.end());
        vector<int>freq(maxi+1,0);
         for(int i = 0;i<n;i++){
            freq[arr[i]]++;
         }
           
            int c = 0;
            for(auto ele:freq){
               c+=ele/3;
            }
        cout<<c<<endl;
        

    }
    return 0;
}
