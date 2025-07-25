#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int lis_Binary_Search(vector<int> &arr)
{
    // time complexity of this is O(nlog n)
    // It always stores the smallest possible tail of an increasing subsequence of each length.
    vector<int> temp;
    for (int ele : arr)
    {
        auto it = lower_bound(temp.begin(), temp.end(), ele);
        if (it == temp.end())
        {
            temp.push_back(ele);
        }
        else
        {
            *it = ele;
        }
    }
    return temp.size();
}
int lis_optimized(vector<int> &arr)
{
    // dp[j] stores the maximum length of LIS ending at j
    vector<int> dp(arr.size(), 1);
    vector<int> pos(arr.size(), -1);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                int nottake = dp[i];
                int take = 0;
                if (dp[i] < dp[j] + 1)
                {
                    take = dp[j] + 1;
                }
                if (take > nottake)
                {
                    dp[i] = take;
                    pos[i] = j;
                }
            }
        }
    }
    int ans = dp[0];
    int po = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (dp[i] > ans)
        {
            ans = dp[i];
            po = i;
        }
    }
    vector<int> restore;

    while (po != (-1))
    {
        restore.push_back(arr[po]);
        po = pos[po];
    }
    reverse(restore.begin(), restore.end());

    cout << "The LIS is : " << endl;

    for (auto ele : restore)
    {
        cout << ele << " ";
    }
    cout << endl;
    return dp[arr.size() - 1];
}
int lis(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = i - 1; prev >= -1; prev--)
        {
            int nottake = dp[i + 1][prev + 1];
            int take = 0;
            if (prev == -1 or arr[prev] < arr[i])
            {
                take = 1 + dp[i + 1][i + 1];
            }
            dp[i][prev + 1] = max(take, nottake);
        }
    }
    return dp[0][0];
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = lis(arr);
    cout << "LIS is : " << ans << endl;

    cout << "LIS using optimize is : " << lis_optimized(arr) << endl;

    cout << "LIS using binary search is : " << lis_Binary_Search(arr) << endl;

    return 0;
}
