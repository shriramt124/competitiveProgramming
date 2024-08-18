#include<iostream>
using namespace std;
/* 

you are given an integer M and you need to find the higest set bit(left most set bit) in M 

***************sol******************
bruteforce 

for(int i = 31;i>=0;i--){
    if((i and (1<<i)!=0){
        ans = i;
        break;
    }
}

//but in the above in worst case the time complexity will be O(n)
 */
int main(int argc, char const *argv[])
{
    int n = 0110100010;

    
    return 0;
}
