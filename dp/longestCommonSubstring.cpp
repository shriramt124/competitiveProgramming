#include <iostream>
using namespace std;
#include <vector>

//https://www.geeksforgeeks.org/dsa/longest-common-substring-dp-29/

//longest common substring article on gfg
int f(int i, int j, string &a, string &b)
{
    if ((i == 0 or j == 0) or a[i - 1] != b[j - 1])
    {
        return 0;
    }
    return 1 + f(i - 1, j - 1, a, b);
}

int longestcommonsubstringdp(string &a, string &b)
{
    int n = a.size();
    int m = b.size();
    int ans = 0;

    // dp[i][j] --> it is representing the length of the longest common substring till [o..n-1][0...m-1]

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int longestsubstringoptimized(string &a, string &b)
{
    int n = a.size();
    int m = b.size();
    vector<int> prev(n + 1);
    int res = 0;
    for (int i = 1; i <= m; i++)
    {
        vector<int> curr(n + 1, 0);
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                curr[j] = prev[j - 1] + 1;
                res = max(res, curr[j]);
            }
            else
                curr[j] = 0;
        }
        prev = curr;
    }
    return res;
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int res = 0;
        for (int i = 1; i <= a.size(); i++)
        {
            for (int j = 1; j <= b.size(); j++)
            {
                int lcs = f(i, j, a, b);
                res = max(res, lcs);
            }
        }
        cout << (a.size() + b.size() - 2 * res) << endl;
    }
    return 0;
}