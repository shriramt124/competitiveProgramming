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
        if(n<=9){
            cout<<n%10<<endl;
        }else if(n>=10 and n<=99){
            int res = 9;
            res = res+n/10;
            cout<<res<<endl;
        }else if(n>=100 and n<=999){
            int res = 18;
            res = res+n/100;
            cout<<res<<endl;
        }else if(n>=1000 and n<=9999){
            int res = 27;
            res+=(n/1000);
            cout<<res<<endl;
        }else if(n>=10000 and n<=99999){
            int res = 36;
            res+=(n/10000);
            cout<<res<<endl;
        }else if(n>=100000 and n<=999999){
            int res = 45;
            res+=(n/100000);
            cout<<res<<endl;
        }
    }
    return 0;
}
