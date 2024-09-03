#include<iostream>
using namespace std;
#include<vector>
int main(){

   int t;
   cin>>t;
   while(t--){
    int a,b;
    cin>>a>>b;
   
    if(a == 0 and b == 0){
        cout<<"YES"<<endl;
    }
    else if(a == 0 and b%2==0){
        cout<<"YES"<<endl;
    }
    else if(a == 0 and b%2!=0){
        cout<<"NO"<<endl;
    }
    else if(b == 0 and a%2== 0){
        cout<<"YES"<<endl;
    }
    else if(b == 0 and a%2!=0){
        cout<<"NO"<<endl;
    }
    else{
        b = b%2;
     a = a-2*b;
    if(a%2 == 0) {
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    }

   }
    return 0;
}