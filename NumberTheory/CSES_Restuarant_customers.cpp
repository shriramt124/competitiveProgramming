#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
/* 
https://cses.fi/problemset/result/10799040/
https://usaco.guide/problems/cses-1619-restaurant-customers/solution

 */
signed main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        v.push_back({start, 1});
        v.push_back({end, -1});
    }
    sort(v.begin(), v.end());
    int count = 0;
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        count += v[i].second;
        ans = max(ans, count);
    }
    cout << ans << endl;
    return 0;
}