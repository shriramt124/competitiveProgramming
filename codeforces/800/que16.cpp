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
        int evencount = 0;
        int oddcount = 0;
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%2 == 0){
                evencount++;
            }else{
                oddcount++;
            }
        }
        if(evencount == 0 and oddcount!=0){
            if(oddcount%2 == 0)
            cout<<"yes"<<endl;

            else cout<<"no"<<endl;
        }else if(evencount !=0 and oddcount == 0){
            cout<<"yes"<<endl;
        }else if(evencount>0 and oddcount == 1){
            cout<<"no"<<endl;
        }else if(evencount>0 and oddcount%2 == 0){
            cout<<"yes"<<endl;
        }
         else if(evencount>0 and oddcount%2!=0){
            cout<<"no"<<endl;
         }
        
    }
    return 0;
}
