#include<iostream>
using namespace std;

/* 
 XOR 
  
0 1 --> 1
1 0 --> 1
0 0 --> 0
1 1 --> 0

xor of same numbers is always zero because their binary is same 
6^6 = 0
5^5 = 0

if we perform xor of any number with zero then we will get the same number again 
6-> 110
    000
   ------
    110 --> by doing xor with zero we got the same number 

we can say that 
x^x --> 0
x^0 -> x
x^y^z = y^x^z = z^y^x --> xor property is associative 


//swapping of two numbers using xor 
int a = 4 
int b = 6

a = a^b;
b = b^a ==> b^(a^b) ==> b^b^a ==> 0^a ==> a
a = a^b ==> (a^b)^a ==> a^a^b ==> 0^b ==> b

this is how we can swap two values using xor operator 

 */
int main(int argc, char const *argv[])
{
    int a  =4;int b = 6;
    a = a^b;
    b = b^a;
    a = a^b;
    cout<<a<<" "<<b<<endl;

    return 0;
}
