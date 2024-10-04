#include <iostream>
using namespace std;
#include <unordered_map>
#include <algorithm>
#include <vector>
#define int long long
/*
https://codeforces.com/problemset/problem/276/C
 */

static bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
  return p1.second > p2.second;
}
static bool cmp1(int a, int b)
{
  return a > b;
}
signed main()
{
  int n, q;
  cin >> n >> q;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<pair<int, int>> queries;
  unordered_map<int, int> indexFrequency;
  vector<int>temp(n+2,0);
  for (int i = 1; i <= q; i++)
  {
    int l, r;
    cin >> l >> r;
    queries.push_back({l, r});
    // for (int j = l; j <= r; j++)
    // {
    //   indexFrequency[j]++;
    // }
    temp[l]+=1;
    temp[r+1] += -1;

  }


for(int i = 1;i<=n;i++){
  temp[i] = temp[i-1]+temp[i];
}
// for(auto ele:temp){
//   cout<<ele<<" ";
// }cout<<endl<<endl;
for(int i = 1;i<=n;i++){
  indexFrequency[i] = temp[i];
}
  // count the frequencies of the elements of each l --> r queries

  // create a map to count the frequencies of index (index,frequency)
  
  vector<pair<int, int>> indexFreqArr(indexFrequency.begin(), indexFrequency.end());
  sort(indexFreqArr.begin(), indexFreqArr.end(), cmp);
  // sort the above in the increasing order of their frequency
 
  // sort the array
  sort(arr.begin(), arr.end(), cmp1);
  vector<int> ans(n+1,0);
  int start = 0;
  for (auto p : indexFreqArr)
  {
    ans[p.first] = arr[start];
    start++;
  }
 
//calculate the prefix sum of queries

for(int i = 1;i<n+1;i++){
 ans[i] = ans[i-1]+ans[i];
 
}

long long sum = 0;
for(auto q:queries){
  sum += ans[q.second]- ans[q.first-1];
}
cout<<sum<<endl;



  return 0;
}

/* 
the logic behind this problem was that 
in the queries the maximum number of index that is appearing in all the queries
so on that index we have to put the maximum element of the array

eg. 2 3 5
    1 3
    2 3
    1 2

1--> 2
2 --> 3
3--> 2


so index 2 is appearing the maximum times
so in 2nd index i have to put the maximum element

2 5 3

sum of queries = 7+8+10 = 25



 */