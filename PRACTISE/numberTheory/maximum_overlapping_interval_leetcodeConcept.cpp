#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
static bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
    if (p1.first == p2.first)
    {
        return p1.second > p1.second;
    }
    return p1.first < p2.first;
}

int main()
{
    // the concept is to calculate the maximum overlapping interval
    // in the given array of intervals.
    vector<vector<int>> intervals = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};
    sort(intervals.begin(), intervals.end());
    // create a vector of pairs
    // for start of the interval put +1 and for end put -1
    vector<pair<int, int>> v;
    for (int i = 0; i < intervals.size(); i++)
    {
        v.push_back({intervals[i][0], 1});
        v.push_back({intervals[i][1], -1});
    }
    // sort the vector of pairs
    sort(v.begin(), v.end(), cmp);
    // now we have to find the maximum overlapping interval
    // we will use a variable to store the maximum overlapping interval
    int count = 0;
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        count += v[i].second;
        ans = max(ans, count);
    }
    cout << ans << endl;

    return 0;
}