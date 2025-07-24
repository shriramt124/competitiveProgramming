#include <bits/stdc++.h>
using namespace std;

/* 
https://codeforces.com/contest/977/problem/F
You are given an integer array of length n
.

You have to choose some subsequence of this array of maximum length such that this subsequence forms a increasing sequence of consecutive integers. In other words the required sequence should be equal to [x,x+1,…,x+k−1]
 for some value x
 and length k
.

Subsequence of an array can be obtained by erasing some (possibly zero) elements from the array. You can erase any elements, not necessarily going successively. The remaining elements preserve their order. For example, for the array [5,3,1,2,4]
 the following arrays are subsequences: [3]
, [5,3,1,2,4]
, [5,1,4]
, but the array [1,3]
 is not



*/


int main(void)
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    map<int, int> dp;

    int mx = 0;
    int last;
    for (auto i : v)
    {
        dp[i] = dp[i - 1] + 1;

        if (dp[i] > mx)
        {
            mx = dp[i];
            last = i;
        }
    }

    cout << mx << '\n';
    int curr = last-mx+1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == curr)
        {
            cout << i + 1 << ' ';
            curr++;
        }
    }

    return 0;
}