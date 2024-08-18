#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    long long t;
    cin>>t;
    while(t--){
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        if(d>=b and (a-b)>=(c-d)){
        long long res1  = (d-b);
        long long res2 = (((a)+((d)-(b)))-(c));
        long long ans = res1+res2;
        cout<<ans<<endl;
        }else{
            cout<<(-1)<<endl;
        }
    }
    return 0;
}
