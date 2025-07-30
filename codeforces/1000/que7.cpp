#include <bits/stdc++.h>
using namespace std;

/* 
https://codeforces.com/problemset/problem/1831/B
*/

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> a(n), b(n);

 
    map<int, int> ma, mb;

    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
 
    for (int i = 0; i < n;)
    {
      int val = a[i];
      int cnt = 0;
      while (i < n && a[i] == val)
      {
        cnt++;
        i++;
      }
      ma[val] = max(ma[val], cnt);
    }

    // Count max consecutive in b
    for (int i = 0; i < n;)
    {
      int val = b[i];
      int cnt = 0;
      while (i < n && b[i] == val)
      {
        cnt++;
        i++;
      }
      mb[val] = max(mb[val], cnt);
    }
 
    int ans = 0;
    for (auto &[val, cnt] : ma)
    {
      ans = max(ans, cnt + mb[val]);
    }
    for (auto &[val, cnt] : mb)
    {
      ans = max(ans, cnt + ma[val]);
    }

    cout << ans << '\n';
  }

  return 0;
}

/* 
✔️ Plan to Solve:
For each test case:

For each unique number in a, calculate the maximum consecutive occurrence (e.g., 2 appears consecutively 2 times, 3 appears 1 time).

Do the same for b.

For all numbers, compute:
max_in_a[number] + max_in_b[number]

The answer is the maximum among all these combined values.
*/