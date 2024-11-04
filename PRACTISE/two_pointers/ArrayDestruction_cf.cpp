#include <bits/stdc++.h>
using namespace std;
/* https://codeforces.com/problemset/problem/1474/C */
/*
Hint 1
: How does x
 changes after each operation?

Hint 2
: Suppose, that you know x
. What pairs of elements can you throw out now?

Hint 3
: Suppose, that you did some operations. Note, that if you have integer b
 that is greater or equal to x
 and b
 is still in array a
, you can't remove b
 from a
, thus you can't throw out all elements of a
.

Hint 4
: You don't know x
 only before the first operation and n≤1000
.

Solution:

Since all integers are positive, x=c+d→c,d<x
, thus x
 decreaces after each operation.

Suppose that we have integers ai≤aj≤ak
 in our array. If we throw out ai+aj=x
, x
 becomes equal aj≤ak
 and we can't throw out ak
 any time later. So, we should throw out the biggest element of array on each operation.

If we know x
 and the biggest element of array, we can easily determine the second element we throw out on this operation.

We can try all possibilities of the second element of array we throw out on the first operation. x
 will become equal the biggest element of initial array. After that we put all other elements in multiset S
 and just simulate opertations by taking max
 from S
 and x−max
 (if it doesn't exists, we can't throw out all elements) and replacing x
 with max
.

Total time complexity: O(n2⋅logn)
.

There is also a solution without set, that runs in O(n2+maxA)
.
 */
#define int long long
vector<int> checkIfPossible(vector<int> &arr, int x)
{
    int n = arr.size();
    multiset<int> s;
    vector<int> ans;
    for (auto el : arr)
        s.insert(el);
    for (int i = 0; i < n / 2; i++)
    {
        auto it = s.end();
        it--;
        int y = x - *it;
        s.erase(it);
        auto it1 = s.find(y);
        if (it1 == s.end())
        {
            return {};
        }
        ans.push_back(x - y);
        ans.push_back(y);
        x = max(x - y, y);
        s.erase(it1);
    }
    return ans;
}
void solv()
{
    int n;
    cin >> n;
    n = 2 * n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    // make all possible pairs of the largest and smallest element
    for (int i = 0; i < n - 1; i++)
    {
        int x = arr[i] + arr[n - 1];
        vector<int> ans = checkIfPossible(arr, x);
        if (ans.size())
        {
            cout << "YES" << endl;
            cout << x << endl;
            for (int j = 0; j < n; j += 2)
            {
                cout << ans[j] << " " << ans[j + 1] << endl;
            }
            return;
        }
    }
    cout << "NO" << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solv();
    }
}