#include <iostream>
using namespace std;
#define ll long long
bool SumHelper(ll n, ll k, ll x)
{
     
    
    ll sum = ((n) * (n + 1)) / 2;
   
    // minimum digit form by the k elements is
    ll minByK = (k * (k + 1)) / 2;
     
    ll maxByK = (n * (n + 1)) / 2 - ((n - k) * (n - k + 1)) / 2;
     
    // if our element x lie between minByK and maxByK then return true; else return false
    if (x >= minByK && x <= maxByK)
        return true;
    else
        return false;
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, x;
        cin >> n >> k >> x;
        bool ans = SumHelper(n, k, x);
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
