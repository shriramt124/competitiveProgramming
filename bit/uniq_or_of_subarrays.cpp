#include <iostream>
using namespace std;
#include <unordered_set>
#include <vector>
/*
https://leetcode.com/problems/bitwise-ors-of-subarrays/description/
Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
*/

/*
At each position in the array,
 we want to know: "What are all the possible OR values of subarrays that END at this current position?"


If we know all possible OR values ending at position i-1,
 then we can easily compute all possible OR values ending at position i.
*/

int maxBitwiseOR(vector<int> &arr)
{
    int n = arr.size();
    // the intution is
    // at each position we want to calculate the maxium or ends with the current element
    unordered_set<int> ans, prev;
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> curr;
        curr.insert(arr[i]);
        for(int val:prev){
            curr.insert(val|arr[i]);
        }
        ans.insert(curr.begin(),curr.end());
        prev = curr;
    }
    return ans.size();
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = maxBitwiseOR(arr);
    cout << "Length of maximum bitwiseOR is : " << ans << endl;

    return 0;
}
