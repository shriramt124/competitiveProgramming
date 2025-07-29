#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/* 
https://codeforces.com/problemset/problem/1876/A

*/
 
bool static cmp(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
    if (a.second == b.second)
    {
        return a.first > b.first; 
    }
    return a.second < b.second; 
}

void solve()
{
    int n;
    long long p;
    cin >> n >> p;

    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

  
    vector<pair<long long, long long>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({a[i], b[i]});
    }

    sort(v.begin(), v.end(), cmp);

 
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({v[i].second, v[i].first});
    }

    long long total_cost = p;
    long long informed_count = 1;

    while (informed_count < n && !pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        long long cost = top.first;
        long long capacity = top.second;

        if (cost >= p)
        {
            break;
        }

        long long people_to_inform = min(capacity, n - informed_count);
        total_cost += people_to_inform * cost;
        informed_count += people_to_inform;
    }  

    if (informed_count < n)
    {
        long long remaining_needed = n - informed_count;
        total_cost += remaining_needed * p;
    }

    cout << total_cost << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
