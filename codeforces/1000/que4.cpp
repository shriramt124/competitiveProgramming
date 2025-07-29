#include <iostream>
using namespace std;
#include <bits/stdc++.h>
/* 
https://codeforces.com/problemset/problem/1859/B
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++)
        {
            int m;
            cin >> m;
            vector<int> a(m);
            for (int i = 0; i < m; i++)
                cin >> a[i];
            sort(a.begin(), a.end());
            arr.push_back(a);
        }
        vector<int> firstmin;
        vector<int> secmin;
        long long secminsum = 0;
        for (int i = 0; i < n; i++)
        {
            firstmin.push_back(arr[i][0]);
            secmin.push_back(arr[i][1]);
            secminsum+=arr[i][1];
        }
        sort(firstmin.begin(),firstmin.end());
        sort(secmin.begin(),secmin.end());
        int ans = firstmin[0]+secminsum-secmin[0];
        cout<<ans<<endl;
    }
}