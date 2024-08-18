#include<iostream>
using namespace std;
#include<algorithm>

/* 
 let a and b are two numbers then 

 a * b
 ------ =  LCM
 gcd




 */
int GCD(int a,int b){
   //base condition
   if(a%b == 0) {
    return b;//when reminder is zero then divisor is the GCD 
   }
    //using long long divison divisor divident ban jata hai and remainder divisor ban jata hai
    //divisor = b
    //divident = a
    return GCD(b,a%b);
}
int main(int argc, char const *argv[])
{
    cout<<GCD(4,12)<<endl;
    cout<<GCD(12,18)<<endl;
    cout<<"LCM is : "<<(4*12 / GCD(4,12))<<endl;
    //we also have built in function in c++ 
    cout<<__gcd(12,18)<<endl;

    //gcd of three numbers a b c is : 
    //gcd(gcd(a,b),c);
    
    return 0;
}
