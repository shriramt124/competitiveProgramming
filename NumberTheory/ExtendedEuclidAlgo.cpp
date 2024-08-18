#include<iostream>
using namespace std;
using ll = long long;
class EuclidTriplet {
    public:
    ll gcd;
    ll x;
    ll y;
};
EuclidTriplet gcdExtendedEuclid(ll a,ll b){
    if(b == 0){
        //something
     //when b ==  0 then gcd = a
     EuclidTriplet ans;
     ans.x = 1;
     ans.y = 0;
     ans.gcd = a;
     return ans;
    }
    EuclidTriplet temp = gcdExtendedEuclid(b,a%b);
    EuclidTriplet myans;
    myans.gcd = temp.gcd;
    myans.x = temp.y;
    myans.y = temp.x - ((a/b)*temp.y);
    return myans;

}
int main(int argc, char const *argv[])
{
    ll a = 30;
    ll b = 20;
    EuclidTriplet ans = gcdExtendedEuclid(a,b);
    cout<<ans.gcd<<endl;
     
    return 0;
}
