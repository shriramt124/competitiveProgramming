

/* Fermat’s Little Theorem helps in finding the modular inverse of a number. If 
𝑝
p is prime and you want to find the modular inverse of 
a mod 𝑝, the inverse can be computed as: 

a ^p−2 (mod p)
*/

#include<iostream>
using namespace std;
int BinaryExpoRec(int a,int b,int m){
    if(b == 0) return 1;

    int temp = BinaryExpoRec(a,b/2,m);
     temp = ((temp%m)+(temp%m)%m);
     if(b%2 == 1){
        temp = ((a%m)  *( temp%m))%m;
     }
     return (temp+m)%m;

}
int BinaryExpo(int a,int b,int m){
    int ans = 1;
    while(b){
        if(b&1){
            ans = (ans * a)%m;
        }
        a = (a*a)%m;
        b = b>>1;
    }
    return (ans+m)%m;
}
int fermatLittleTheoram(int a,int m){
    return BinaryExpoRec(a,m-2,m);
}
int main(int argc, char const *argv[])
{
    int a = 3;
    int m = 100007;
    cout<<fermatLittleTheoram(a,m)<<endl;
    return 0;
}
