#include <iostream>
using namespace std;
#include <vector>
#define ll long long

/*
https://codeforces.com/problemset/problem/1/A
 */
int main(){
    ll n, m ,a;
    cin>>n>>m>>a;
    ll row;
    if(n%a == 0){
        row = n/a;
    }else row = n/a+1;

    //minus to the m 
    m = m-a;ll col;
    if(m<=0){ //to ensure that if the number of columns is not left or no of columns is only   1 
        col = 0;
    }
    else if(m%a == 0){
        col = m/a * row;
    }else{
        col = m/a * row+row;
    }
    cout<<(row+col)<<endl;
    return 0;
}