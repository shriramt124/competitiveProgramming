#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
vector<int> arr;
// https://codeforces.com/contest/1201/problem/C
// this problem is about the binary search concept expecially for jumping binary search
bool check(int x)
{
    int op = 0;
    for (int i = (n - 1) / 2; i < n; i++)
    {
        op += max(0 * 1LL, x - arr[i]);
    }
    if (op <= k)
        return true;
    else
        return false;
}

int solv()
{
    int low = 0;
    int high = 2e9;
    for (int jump = high; jump >= 1; jump /= 2)
    {
        while (check(low + jump))
            low += jump;
    }
    return low;
}
signed main()
{

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    sort(arr.begin(), arr.end());
    cout << solv() << endl;

    return 0;
}