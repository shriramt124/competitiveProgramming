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
        vector<int>a;
        vector<int>b;
        sort(arr.begin(),arr.end());
        int curr = arr[0];
        int i = 0;
        while(arr[i] == curr){
             a.push_back(arr[i]);
             i++;
        }
        while(i<n){
            b.push_back(arr[i]);
            i++;
        }
        if(b.empty()){
            cout<<(-1)<<endl;
        }else{
        cout<<a.size()<<" "<<b.size()<<endl;
        for(auto ele:a){
            cout<<ele<<" ";
        }cout<<endl;
        for(auto ele:b){
            cout<<ele<<" ";
        }cout<<endl;


        }


        

    }
    return 0;
}
