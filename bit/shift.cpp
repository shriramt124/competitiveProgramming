#include<iostream>
using namespace std;
int main(){
    int a = 3;//11
    int res = a<<1;//a left shift 1 
    //110--> 6
    cout<<a<<endl;
    cout<<res<<endl;
    
    int res1 = a<<2;
    cout<<res1<<endl;
    int res2 = a>>1;
    cout<<"right shift as 1 -> "<<res2<<endl;
   int b = 6;
   int res3 = b>>2;
    cout<<"right shift as 2 -> "<<res3<<endl;
    return 0;
    
}