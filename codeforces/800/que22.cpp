#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    long long t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        long long divisibleCheck;
        if((2+k)%2 == 0) divisibleCheck = 2;
        else divisibleCheck = n;
        if(n%divisibleCheck == 0) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
