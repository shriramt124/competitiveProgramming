#include<iostream>
using namespace std;
void printBinary(int n){
    for(int i = 10;i>=0;i--){
        cout<<((n>>i) & 1);
    }cout<<endl;
}
void isSetOrNot(int n){
    /* 
    le a = 6;
    --> 110 
    to check if 0th bit is set or not we will take a number in which only 0th bit is set 
    and then we will perform and operation if result is non zero then the 0th bit is set 
    otherwise not set 
    110
    001
    ----
    000 --> the result is 0 it means 0th bit is not set 


    let a = 9
    --> 1001  -> to check if 0th bit is set 
  (and) 0001
       -------
       0001 --> result is not zero it means the 0th bit is set 
     */

     int i = 1;
     if((n & (1<<i))!=0){
       cout<<i<<"th bit is set"<<endl;
     }else{
        cout<<i<<"th bit is not set"<<endl;
     }


}
void SetBit(int a){
    
    /* 
    let a = 9
    --> 1001
    to set the 1st bit we will take the bit in which only 1st bit is set and 
    then we will perform the or operation on that bit 
     1001
(or) 0010
    ------
    1011 --> now the 1st bit is set
     */
    int i = 1;
    int res = (a | (i<<i));
    cout<<"after setting the "<<i<<"th bit"<<endl;
    printBinary(res);

}
void UnsetBit(int a){
    /* 
    let a = 9;
    1001
    if we want to set the 0th bit then take the number in which only that bit is unset 
    and then from that number perform the and operation 
         1001
    (and)1110
       --------
         1000 --> here the 0th bit is unsetted 
   
     */
    int i = 0;
    int res = (a & (~(1<<i)));
    cout<<"after unset "<<i<<"th bit"<<endl;
    printBinary(res);
}
void ToggleBit(int a){
    int i = 0;
    int res = (a^(1<<i));
    cout<<"after flipping "<<i<<"th bit"<<endl;
    printBinary(res);
}
int main(int argc, char const *argv[])
{
    int a = 9;
    printBinary(a);
    //to check if the bit is set or not 
    isSetOrNot(a);
    //to set the bit we will perform or operation 
    SetBit(a);
    //to unset the bit we wil use and operator 
    UnsetBit(a);
    //to flip the bit we will take the help of xor operator 
    ToggleBit(a);
    return 0;
}
