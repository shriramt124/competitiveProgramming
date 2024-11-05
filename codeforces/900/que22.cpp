#include <bits/stdc++.h>
using namespace std;
#define int long long

/* https://codeforces.com/problemset/problem/1582/B */
//very intresting problem
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;

        cin >> n;
        vector<int> arr(n);
        int s = 0;
        int one = 0;
        int zero = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
           
            if(arr[i] == 1)
            one++;

            if(arr[i] == 0)
            zero++;
        }
        
        //zero ko ya to ham le le or na le to 2 ways for one zero 
        //if one then we just have to not take the one only 1 way 
        int noOfwaysToKeepZeros = 1*1LL<<zero;
        int noOfwaysToKeepOne = one*1LL ;
        int ans = noOfwaysToKeepZeros*1LL*noOfwaysToKeepOne;

        cout<<ans<<endl;
    }

    return 0;
}