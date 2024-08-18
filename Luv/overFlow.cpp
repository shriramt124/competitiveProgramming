#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
   // cout<<3/2<<endl;//output --> 1
    //cout<<3/2.0<<endl;//output --> 1.5 becase calculations will be based on higher data type that is double 
   // int a = 3/2;//integer me calculation hui aur phir a ko assign hui 
   // cout<<a<<endl;
    
   // int b = 3/2.0;//double me calculation hui but b can only store integer so integer part is assigned to b as 1
    //cout<<b<<endl;
     
    // double c = 3/2.0;//double me calculation hui as 1.5 aur phir c ko assign hui as c = 1.5
     //cout<<c<<endl;
     //concept is that pahle calculation ho rahi hai according to higher data type present and then assignment is happening
    // int a = 1000000;
    // int b = 1000000;
    // int c = a*b;//but an integer can only hold upto 10^9  so it will give overflow error
    // cout<<c<<endl;
    

    //if i use long int in place of int 
    // long int a = 100000;
    // long int b = 100000;
    // long int c = a*b;//it will not overflow because long int can store upto 10^12 degits

    // cout<<c<<endl;//no overflow here
      
       
       //now insetead of using everywhere as long int we can take help of higher data types
       int a = 100000;
       int b = 100000;
       long long int c = a*1LL*b; //now 1 will be treated as long int so calculation will based on long int data type 

       cout<<c<<endl;//so there will be no overflow here
       
    
        return 0;
}
