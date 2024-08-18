#include <iostream>
using namespace std;
#include <stdlib.h>
#include <climits>
#include <vector>
const int N = 1e5 + 10;
int arr[N];
vector<int> dp(N, -1);

int fun(int i, int k)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int cost = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (i - j >= 0)
            cost = min(cost, fun(i - j, k) + abs(arr[i] - arr[i - j]));
    }

    return dp[i] = cost;
}
 
int main()
{

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << fun(n - 1, k) << endl;
 

    return 0;
}
