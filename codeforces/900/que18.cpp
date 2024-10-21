#include<bits/stdc++.h>
using namespace std;

bool solv1(int a,int b,int c){
         if((a+c) % 2 != 0) return false;
         int temp  = (a+c)/2;
         if(b == temp) return true;
         if(b>temp) return false;
         if(temp%b == 0) return true;
         return false;


}
bool solv2(int a,int b,int c){
        int temp = 2*b-c;
        if(temp<0) return false;
        if(a>temp) return false;
        if(temp%a == 0) return true;
        return false;

}

bool solv3(int a,int b,int c){
        int temp = 2*b-a;
        if(temp<0) return false;
        if(c>temp) return false;
        if(temp%c == 0) return true;
        return false;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(solv1(a,b,c) || solv2(a,b,c)||solv3(a,b,c)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}