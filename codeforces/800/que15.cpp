#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
     int a,b,c;
     cin>>a>>b>>c;
     string turn = "First";
     if(c%2!=0){
        turn = "Second";
        if(a == b){
            cout<<"First"<<endl;
        }
        else if(a>b){
            cout<<"First"<<endl;
        }else if(a<b){
            cout<<"Second"<<endl;
        }
     }else{
        turn = "First";
        if(a<=b){
            cout<<"Second"<<endl;
        }else {
            cout<<"First"<<endl;
        }
     }


    }
    return 0;
}
