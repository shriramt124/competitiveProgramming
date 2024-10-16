#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> cities(n);
    for (int i = 0; i < n; i++)
        cin >> cities[i];
    vector<int> towers(m);

    for (int i = 0; i < m; i++)
    {
        cin >> towers[i];
    }
    sort(towers.begin(), towers.end());
    sort(cities.begin(), cities.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = cities[i];
        auto it = lower_bound(towers.begin(), towers.end(), x);
        int dist1 = LLONG_MAX, dist2 = LLONG_MAX;

        // Check the tower on the left (if exists)
        if (it != towers.begin())
        {
            dist1 = abs(x - *(it - 1));
        }

        // Check the tower on the right (if exists)
        if (it != towers.end())
        {
            dist2 = abs(x - *it);
        }

        // Take the minimum of both distances
        int min_dist = min(dist1, dist2);

        // Update the answer with the maximum minimum distance
        ans = max(ans, min_dist);
    }
    cout << ans << endl;
}