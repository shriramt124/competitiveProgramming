#include<iostream>
using namespace std;
int main(){
 int t;
 cin>>t;
 while(t--){
  int x,y;
  cin>>x>>y;
  for(int i = 0;i<=30;i++){
    if(((x>>i)&1)!=((y>>i)&1)){
        cout<<(1LL<<i)<<endl;
        break;
    }
  }
 }
}