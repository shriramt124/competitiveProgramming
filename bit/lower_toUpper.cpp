#include<iostream>
using namespace std;

/* 
A 00001000001
B 00001000010
C 00001000011
D 00001000100
E 00001000101
a 00001100001
b 00001100010
c 00001100011
d 00001100100
e 00001100101

upar ke sumilarities ko dekh ke pata chala ki uppercase me 5th bit unset hoti hai 
aur lower case me 5th bit set hoti hai 

so if we want to change the upper case character to lower case the we 
have to just set the 5th bit 


 */
void printBinary(int num){
    for(int i = 10;i>=0;i--){
        cout<<((num>>i)&1);
    }cout<<endl;
}
int main(int argc, char const *argv[])
{
    for(char ch = 'A';ch<='E';ch++){
        cout<<ch<<" ";
        printBinary(int(ch));
    }
    
    for(char ch = 'a';ch<='e';ch++){
        cout<<ch<<" ";
        printBinary(int(ch));
    }

    cout<<char('C' | (1<<5))<<endl;//--> c
    cout<<char('c' & (~(1<<5)))<<endl;//--> C
    cout<<char(' ')<<endl;//--> 1<<5  it is a binary of space  ' '
    //if we perform or operation with a upper case and C then we will get lower case character 
       cout<<char('C' | ' ')<<endl;
    cout<<char(~(1<<5))<<endl; //-> it is a binary of _ underscore 
    //so if we preform and operation with _ then we will get the uppercase character 
    cout<<char('c' & '_')<<endl;


    return 0;
}
