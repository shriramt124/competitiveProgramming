#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str;
        cin>>str;
        if(n == 1){
            if(str[0] == '?'){
                cout<<'B'<<endl;

            }else{
                cout<<str<<endl;
            }
            continue;
        }
        int startCount = 0;
        int start = 0;
        while(start<n && str[start++] == '?' ) startCount++;
        if(startCount%2 == 0){
          for(int i = 0;i<start;i++){
            if(i%2 == 0) str[i] = 'R';
            else str[i] = 'B';
          }
          
        }else{
               for(int i = 0;i<start;i++){
            if(i%2 == 0) str[i] = 'B';
            else str[i] = 'R';
               }
        }
         for(int i = 0;i<n;i++){
            if(str[i] == 'B' && str[i+1] == '?'){
                str[i+1] = 'R';
            }
            if(str[i] == 'R' && str[i+1] == '?'){
                str[i+1] = 'B';
            }
          }
        cout<<str<<endl;
        
        
    }
}