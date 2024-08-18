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
        string str;
        cin>>str;
        int s = 0;
        int ans = 0;
      while(s<n){
        if(str[s] == '.'){
           int i = s;
           while(str[i]!='#' and i<n){
            i++;
           }
           if(i == n){
             ans += i-s-1;
             break;
           }else{
         
            if(i-s >=3){
            ans+=(s-i-1);
            }else{
                ans+=(i-s);
            }
            s = i-1;
           }
           s++;
        }
      }
      cout<<ans<<endl;


    }
    return 0;
}
