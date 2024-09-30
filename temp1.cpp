#include <iostream>
using namespace std;
#include <vector>

int solv(vector<int> arr, bool ascending)
{
    int n = arr.size();
    int swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ascending)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    swaps++;
                    swapped = true;
                }
            }
            else
            {
                if (arr[j] < arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    swaps++;
                    swapped = true;
                }
            }
        }
        if (!swapped)
        {
            break;
        }
    }

    return swaps;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count1 = solv(arr, true);
    int count2 = solv(arr, false);
    int ans = min(count1, count2);
    cout << ans << endl;
    return 0;
}