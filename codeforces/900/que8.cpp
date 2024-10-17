#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/* 
*/

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str;

        cin>>str;
        int count = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(str[i] == '>'){
                count++;
                ans = max(ans,count);
            }else{
                count = 0;
            }
        }
        count = 0;
        for(int i = 0;i<n;i++){
            if(str[i] == '<'){
                count++;
                ans = max(ans,count);
            }else{
                count = 0;
            }
        }

        cout<<ans+1<<endl;
    }
    return 0;
}