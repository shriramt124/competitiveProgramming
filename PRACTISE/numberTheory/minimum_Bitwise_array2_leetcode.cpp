#include <bits/stdc++.h>
using namespace std;

// here the main concept is about
// let us say we have a number n and we want to find a number x such that
// x|x+1 == n and n is the prime number
// and the x is the smallest number

/*
so the concept  is that we will iterate orver bites of the number n from the left ro right

and the the last bit that is set is the minimum x such that x|x+1 = n

let n = 5 then

        n =  0 1 0 1
then    j =  0 0 0 1
xor  -------------------
        x =  0 1 0 0  = 4
        xo 4|4+1 = 5

let n = 7
then

n =  0 0 1 1 1
j =  0 0 1 0 0
xor--------------
     0 0 0 1 1 = 3
     3|3+1 = 7


 */

int main()
{
    int n;
    cin >> n;
    int smallest_x = 0;
    for (int i = 1; i < 31; i++)
    {
        if (n & (1 << i))
            continue; // it means that the bit is set

        // else if not set then
        smallest_x = n ^ (1 << (i - 1));
        break;
    }
    cout << smallest_x << endl;

    return 0;
}