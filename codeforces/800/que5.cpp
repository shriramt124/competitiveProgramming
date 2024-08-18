#include<iostream>
using namespace std;
#include<vector>
 
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
      
        if(arr[0] == 1){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
         

    }
    return 0;
}
