#include <bits/stdc++.h>
using namespace std;

/* 
https://codeforces.com/problemset/problem/1849/B

*/
/* 

Let's simulate the game process until the number of health points of each monster becomes k
 or less. Then we can consider that the i
-th monster has aimodk
 health instead of ai
 (except for the case when ai
 is divisible by k
, then the remaining health is k
, not 0
).

Now, the health points of all monsters are from 1
 to k
, so each time we damage a monster, we kill it. Therefore, monsters with k
 health points will die first, then the ones with k−1
 health points, and so on. So, let's sort the monsters by their remaining health points in descending order (don't forget that,
  if two monsters have the same health, 
  then they should be compared by index). And the order you get after sorting is the answer to the problem.
*/


bool cmp(pair<int, int> &p, pair<int, int> &q)
{
  if (p.first == q.first)
    return p.second < q.second;
  return p.first > q.first;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
      if (arr[i] % k != 0)
        v.push_back({arr[i] % k, i + 1});
      else
        v.push_back({k, i + 1});  
    }

    sort(v.begin(), v.end(), cmp);

    for (auto ele : v)
    {
      cout << ele.second << " ";
    }
    cout << endl;
  }

  return 0;
}
