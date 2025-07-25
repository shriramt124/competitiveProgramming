#include <iostream>
using namespace std;
#include <vector>
#include<map>
#include<algorithm>

/* 
If one array is a permutation or subset of the other — or if you can map elements of
 one array to indices of another — then yes, you can reduce LCS to a Longest Increasing Subsequence
  (LIS) problem, which runs in O(n log n).

*/


int lis(vector<int>&a){
  vector<int>temp;
  for(auto ele:a){
    auto it = lower_bound(temp.begin(),temp.end(),ele);
    if(it == temp.end()){
        temp.push_back(ele);
    }else{
        *it = ele;
    }
  }
  return temp.size();
}
int solv(vector<int> &a, vector<int> &b)
{
     map<int,int>m;
    for(int i = 0;i<b.size();i++){
        m[b[i]] = i;
    }
    for(int i = 0;i<a.size();i++){
        a[i] = m[a[i]];
    }
    //now find the lis 
    int ans = lis(a);
    return ans;
}
int main(int argc, char const *argv[])
{

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

   cout<<solv(a,b)<<endl;

    return 0;
}
