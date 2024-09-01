#include <iostream>
using namespace std;
#include <vector>
// https://www.geeksforgeeks.org/problems/max-sum-path-in-two-arrays/1
/*
Given two sorted arrays of distinct integers arr1 and arr2. Each array may have some elements in common with the other array.
 Find the maximum sum of a path from the beginning of any array to the end of any array.
You can switch from one array to another array only at the common elements.

Note:  When we switch from one array to other,  we need to consider the common element only once in the result.
 */

int maxPathSum(vector<int> &arr1, vector<int> &arr2)
{
    int sum1 = 0;
    int sum2 = 0;
    int ans = 0;
    int i = 0;
    int j = 0;
    while (i < arr1.size() and j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            sum1 += arr1[i];
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            sum2 += arr2[j];
            j++;
        }
        else
        {
            ans += max(sum1, sum2) + arr1[i];
            sum1 = 0;
            sum2 = 0;
            i = i + 1;
            j = j + 1;
        }
    }
    while (i < arr1.size())
    {
        sum1 += arr1[i];
        i++;
    }
    while (j < arr2.size())
    {
        sum2 += arr2[j];
        j++;
    }
    ans += max(sum1, sum2);
    return ans;
}

int main()
{

    int n1;
    cout << "enter len of arr1 " << endl;
    cin >> n1;
    vector<int> arr1(n1);
    cout << "Enter elements of arr1 " << endl;
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    int n2;
    cout << "Enter the len of arr2 " << endl;
    cin >> n2;
    cout << "Enter elements of arr2 : " << endl;
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    int ans = maxPathSum(arr1, arr2);
    cout << "Max path sum is :" << ans << endl;

    return 0;
}

/*
This code defines a method to find the maximum sum path between two sorted arrays,
`arr1` and `arr2`, where the path can switch between the arrays at any common elements.
It starts by initializing two accumulators, `sum1` and `sum2`, to store the sums of the elements from `arr1` and `arr2`, respectively,
and a variable `ans` to store the final result. The algorithm then iterates through both arrays simultaneously, adding elements to `sum1` or `sum2`
depending on whether the current element in `arr1` is less than, greater than, or equal to the current element in `arr2`. When a common element is found,
the algorithm adds the greater of `sum1` or `sum2` plus the common element to `ans`, and resets the sums. After traversing one array, the remaining elements
 of the other array are added to the respective sum, and finally, the maximum of `sum1` and `sum2` is added to `ans`. The method then returns `ans`, which represents
 the maximum path sum achievable by potentially switching between the arrays at the common elements.

 */