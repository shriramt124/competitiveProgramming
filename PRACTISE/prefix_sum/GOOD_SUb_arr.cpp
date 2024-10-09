#include<iostream>
using namespace std;
#include<vector>
#include<map>
#define int long long

/* 
https://codeforces.com/contest/1398/problem/C

 */
  

/* 
The key to solving this problem efficiently is to recognize that you are looking for subarrays where the sum of elements is equal to the number of elements in the subarray. 

### Intuition:

1. **Reformulate the condition**: For a subarray to be "good", the sum of its elements must equal its length. Mathematically:
    
   This means we are looking for subarrays where the difference between the prefix sum and the index is the same for two indices.

2. **Use prefix sums**: Compute the prefix sum of the array and at each index, track the difference between the prefix sum and the index (`prefix_sum[i] - i`). If this difference has appeared before, it means there exists a subarray where the condition holds.

3. **Use a hash map**: To efficiently count how many times each `prefix_sum[i] - i` has appeared, store these values in a hash map (or unordered map). For each index, if the current difference exists in the map, it means there are subarrays ending at the current index that satisfy the condition.

This approach reduces the problem to checking conditions with prefix sums in O(n) time using a hash map.
 */


signed main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    string str;
    cin>>str;
    
    vector<int>arr(n+1);
    vector<int>prefix(n+1);
    for(int i = 1;i<=n;i++){
        prefix[i] = prefix[i-1]+(str[i-1]-'0');
    }
    map<int,int>m;
    m[0] = 1;
    int count = 0;
    for(int i = 1;i<=n;i++){
        int diff = prefix[i]-i;
       count+=m[diff];
       m[diff]++;  
    } 
     cout<<count<<endl;
    }
    return 0;
    


}