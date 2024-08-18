#include <iostream>
using namespace std;
const int M = 1e9 + 7;

int BinaryExpoRec(int a, int b)
{
    if (b == 0)
        return 1;

    int res = BinaryExpoRec(a, b / 2);
    if (b & 1)
    {
        return (a * (res * 1LL * res) % M) % M;
    }
    else
    {
        return (res * 1LL * res) % M;
    }
}

int binaryExpoItr(int a, int b)
{
    int ans = 1;
    while (b)
    {
        // check if the 0th bit is 1 only then it will contribute
        if (b & 1)
        {
            ans = (ans *1LL* a) %M;
        }
        // if not then just increase the multiple of a
        a = (a *1LL* a) %M;
        b >>= 1;
    }
    return ans;
}

//we will use binary multiplicationn if the M <=10^18
int binExpo(long long a,long long b){
       int ans = 1;
       while(b>0){
       if(b&1){
        ans = binMultiply(ans,a);
       }
       a = binMultiply(a,a);
       b>>=1;
       }
       return ans;
}
int binMultiply(long long a,long long b){
    int ans = 0;
    while(b>0){
        if(b&1){
            ans = (ans +a)%M;
        }
        a = (a+a)%M;
        b>>=1;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int a = 2;
    int b = 13;
    cout << BinaryExpoRec(a, b) << endl;
    cout<<binaryExpoItr(a,b)<<endl;
    return 0;
}
