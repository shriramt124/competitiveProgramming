#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, t;
        cin >> n >> t;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        int ans = 0;
        int r = 0;
        for (int l = 0; l < n; l++)
        {
            r = max(r, l);
            while (r + 1 < n and abs(arr[r + 1] - arr[r] < 2) and (arr[r + 1] - arr[l]) < t)
                r++;

            ans = max(ans, r - l + 1);
        }
        cout << ans << endl;
    }

    return 0;
}
