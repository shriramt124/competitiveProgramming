#include <iostream>
using namespace std;
#include <bits/stdc++.h>
/* que 6 solved */
void solv()
{
  long long n, k, q;
  cin >> n >> k >> q;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++)
    cin >> arr[i];

  long long m = 0, ans = 0;

  for (long long i = 0; i < n; i++)
  {
    if (arr[i] <= q)
      m++;
    else
    {
      if (m >= k)
      {
        long long len = m - k + 1;
        ans += (len * (len + 1)) / 2;
      }
      m = 0;
    }
  }

  if (m >= k)
  {
    long long len = m - k + 1;
    ans += (len * (len + 1)) / 2;
  }

  cout << ans << endl;
}

int main()
{
  long long t;
  cin >> t;
  while (t--)
  {
    solv();
  }
  return 0;
}