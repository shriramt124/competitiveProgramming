#include <iostream>
using namespace std;
#include <vector>
bool isSorted(vector<int> arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (!isSorted(arr))
        {
            cout << 0 << endl;
        }
        else
        {
            int minDiff = INT32_MAX;
            for (int i = 0; i < n - 1; i++)
            {
                minDiff = min(minDiff, abs(arr[i] - arr[i + 1]));
            }
             
            int res = minDiff/2+1 ;
            cout << res << endl;
        }
    }
    return 0;
}
