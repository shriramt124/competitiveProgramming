#include<iostream>
using namespace std;
/* 
0th bit of every even number is always zero 
0th bit of every odd number is always 1 

so if we want to check if the number is even or odd then we can do and operation with 1 
if the result is 1 it means the number is odd otherwise number is even if result is  0 

let a = 9;
          1001
    (and) 0001
        -------
          0001 --> result is not 0 it means the number is odd 

let a = 6;
         110
    (and)001
      ---------
         000 --> result is zero it means the number is even which is true 

this is how we can check even number using bits and the bit operation is faseter than the modulo(%) operator 


 */
void printBinary(int n){
    for(int i=10;i>=0;i--){

        cout<<((n>>i)&1);
    }cout<<endl;
}
int main(int argc, char const *argv[])
{
    for(int i = 0;i<8;i++){
        printBinary(i);
        if(i&1!=0){
            cout<<"odd number "<<endl;
        }else{
            cout<<"even number"<<endl;
        }
    }

    return 0;
}
