#include <iostream>
using namespace std;
#include <vector>
vector<int> dp; // dp array --> it will store ans for states which are computed for the first time

int fib(int n)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fib(n - 1) + fib(n - 2);
}

int fib_bottom_up(int n)
{
    if(n == 0 || n == 1) return n;
    dp.resize(n + 1, -1);
    // setting up the base case
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main()
{

    int n;
    cin >> n;
    dp.resize(n + 1, -1);
    cout << fib(n) << endl;
    cout << fib_bottom_up(n) << endl;

    return 0;
}
// dp[i]--> -1
// represent that the ith state is not yet computed
// dp[i]!= -1
// represent that the ith state is already computed
