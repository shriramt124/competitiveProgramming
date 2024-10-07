#include "../../common.h"
/* 
https://www.codechef.com/problems/GCDXOR
*/
#define int long long

#define endl '\n'
const int MOD = 1e9 + 7;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vi arr(n);
        int firstBad = INT_MAX;
        int lastBad = INT_MIN;
        rep(i, 0, n)
        {
            cin >> arr[i];
            if (arr[i] != k)
            {
                firstBad = min(i, firstBad);
                lastBad = max(lastBad, i);
            }
        }
        if (firstBad == INT_MAX)
        {
            cout << "0" << endl;
            continue;
        }

        bool flag = true;
        for (int i = firstBad; i <= lastBad; i++)
        {
            // this is to check for the xor
            if (arr[i] != arr[firstBad])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "1" << endl;
            continue;
        }
        flag = true;
        rep(i, 0, n)
        {
            if (__gcd(arr[i], k) != k)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "1" << endl;
            continue;
        }
        cout << "2" << endl;
    }

    return 0;
}

/* 
here the logic is that 
let us say 
arr = 3  3 5 6 1 3
i take x = 1
then take gcd of all elements
arr  = 1 1 1 1 1 1 1  --> this is first operation where all elments become one 

now x = 3 and take the xor 
then all elements will become same 

so basically atmost 2 operations is possible 

if all arr[i] == k then zero operation 

if some elements are arr[i] == k but some elements are same arr[i] =arr[i+1] 
then we will take the xor and opeartion will be one 

if some elements are arr[i] = k but some elments are gcd(arr[i],k) = k 
then also the operation is one

otherwise the operation is 2 



 */