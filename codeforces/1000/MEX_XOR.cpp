#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/problemset/problem/1567/B

/* 
First consider the MEX condition: the shortest array with MEX a
 is the array [0,1,…,a−1]
, which has length a
. Now we'll consider the XOR condition. Let the XOR of the array [0,1,…,a−1]
 be x
. We have three cases.

Case 1: x=b
. Then we don't need to add any elements to the array, so the answer is a
.

Case 2: x≠b
 and x⊕b≠a
. Then we can add the element x⊕b
 to the array since x⊕b≠a
, so the MEX will still be a
. The XOR of the array will then be x⊕x⊕b=b
. The answer is a+1
.

Case 3: x≠b
 and x⊕b=a
. Then we cannot add the element x⊕b
 to the end of the array. We can just add x⊕b⊕1
 and 1
, so the XOR of the array will be x⊕x⊕b⊕1⊕1=b
. The answer is a+2
.

Time complexity: O(n)
 precomputation and O(1)
 per test case if you precalculate the XOR of the numbers from 0
 to n−1
, or O(1)
 if you use the well-known formula for it.

*/
long long till_xor(long long n){
    if(n%4 == 0){
        return n;
    }
    else if(n%4 == 1){
        return 1;
    }
    else if(n%4 == 2){
        return n+1;
    }
    else{
        return 0;
    }
}

int main(){
    long long t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        long long axor = till_xor(a-1);
        if(axor == b){
            cout<<a<<endl;
        }
        else if((axor^b) != a){
            cout<<a+1<<endl;
        }
        else {
            cout<<a+2<<endl;
        }

    }
    return 0;
}