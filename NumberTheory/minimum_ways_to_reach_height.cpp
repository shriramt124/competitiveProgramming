#include <iostream>
using namespace std;
 
 

class EuclidTriplet{
public:
   long long gcd;
   long long x;
   long long y;
};

 

EuclidTriplet gcdExtendedEuclid(long long a, long long b){
    if (b==0){
        EuclidTriplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }

    EuclidTriplet temp = gcdExtendedEuclid(b, a % b);
    EuclidTriplet myans;
    myans.gcd = temp.gcd;
    myans.x = temp.y;
    myans.y = temp.x - ((a / b) * temp.y);
    return myans;

}

long long mInverse(long long a, long long b){
    long long ans = gcdExtendedEuclid(a, b).x;
    return (ans % b + b) % b;
}
 

int main(){
    int t;
    cin>>t;
    while(t--){
   long long a, b, d;
    cin >> a >> b >> d;
    // if gcd(a,b) != 0 then not possible
    long long g = gcdExtendedEuclid(a, b).gcd;   
    if(d%g != 0){
        cout<<0<<endl;
        
    } 
    else if(d == 0){
        cout<<1<<endl;
    }else{
    long long min_y = ((d%a)*mInverse(b,a))%a;
    long long temp = d/b;
    if(d<min_y*b){
        cout<<0<<endl;
        continue;
    }
    long long n = (temp-min_y)/a;
    cout<<(n+1)<<endl;
    }
    }
    return 0;
}
