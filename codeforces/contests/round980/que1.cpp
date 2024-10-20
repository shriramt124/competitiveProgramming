#include<bits/stdc++.h>
using namespace std;
 
#define khatam "\n"
#define bhago return 

void solvByRam(){
   
        int a,b;
        cin>>a>>b;
        if(a>=b){
            cout<<a<<khatam;
            return;
        }
        else if(b>=(a*2)){
            cout<<0<<khatam;
            return;
        }
        else{
            int diff = b-a;
            a = a-diff;
            cout<<a<<khatam;
            bhago;
        }
        bhago;
   
}

int main(){
  int t;
  cin>>t;
  while(t--){
    solvByRam();
  }

    return 0;
}