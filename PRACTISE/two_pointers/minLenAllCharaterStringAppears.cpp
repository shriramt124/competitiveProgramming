#include<bits/stdc++.h>
using namespace std;
#define int long long
set<char>st;
/* https://usaco.guide/silver/two-pointers#problem-cf-701C */
bool solv(int start,int end,string &str){
      string res = str.substr(start,end);
      set<char>temp(res.begin(),res.end());
      if(st == temp) return true;
      return false;
}

int solvBYMyLogicGivingMeTleOnTEST11(){
 int n;
    cin>>n;
    string str;
    cin>>str;
    if(n == 1 ) {
        cout<<1<<endl;
        return 0;
    }
    if(n == 2){
        if(str[0] == str[1]){
            cout<<1<<endl;
        }else{
            cout<<2<<endl;
        }
        return 0;
    }
    st.insert(str.begin(),str.end());
  

    int i = 0;
    int j = 0;
    int ans = INT_MAX;
    while(j<n){
         //if from i to j all the elements are less then we will do j++ 
         //while doing j++ we have to make sure that if arr[j] == arr[i] then do i++ 
         //if we got all the elements then we will just return 
         if(solv(i,j,str)){
            // cout<<(j-i+1)<<endl;
            int res   = str.substr(i,j).size();
             
               ans = min(ans,res);
           i++;
         
         }else{
            j++;
            if(str[j] == str[i]){
                i++;
               
            }
            // cout<<(str.substr(i,j))<<endl;
         }
    }
    if(ans == INT_MAX){
        cout<<n<<endl;
    }else
    cout<<ans<<endl;
    return 0;

}
signed main(){
    
int n;
cin>>n;
string str;
cin>>str;
set<char>uniqchar(str.begin(),str.end());
int totalUniq = uniqchar.size();
unordered_map<char,int>freq;
int i = 0;
int j = 0;
int ans = INT_MAX;
int count = 0;//to count the uniq chars in the sliding window
while(j<n){
    freq[str[j]]++;
    if(freq[str[j]] == 1) count++;

    //try to minimize the sliding window 
    while(count == totalUniq){
        ans =  min(ans,j-i+1);
        freq[str[i]]--;
        if(freq[str[i]] == 0) count--;
        i++;
    }
    j++;

}
cout<<ans<<endl;


}

/* 
Your current solution for the Codeforces problem 701C is giving a **TLE (Time Limit Exceeded)** because of the following reason:

### Inefficient Sliding Window
In your implementation, the `solv()` function creates a substring for each window `str.substr(start, end)` and then generates a temporary set `temp(res.begin(), res.end())` for every iteration of `i` and `j`. This results in **O(n²)** complexity due to the substring creation and set operations, which is too slow for `n = 100,000`.

### How to Improve:
You should avoid repeatedly creating substrings and sets. Instead, use a **sliding window** approach combined with a **frequency map** (or array) to track the occurrences of each character in the window.

### Optimized Approach:
1. **Use a Frequency Map**:  
   Maintain a frequency count of each character within the current window `[i, j]`.
   
2. **Sliding Window Logic**:  
   Expand the window by moving `j` to the right, and shrink the window by moving `i` to the right, ensuring that all unique characters are in the current window.

3. **Optimal Time Complexity**:  
   Using a frequency map allows the solution to work in **O(n)** time because you only traverse the string once, updating the frequency count in constant time.

 

### Explanation:
- **Set**: We first create a set of all unique characters in the string, so we know how many unique characters we need in the window.
- **Sliding Window**: 
   - `i` is the left pointer, and `j` is the right pointer.
   - As we expand the window by moving `j`, we increase the count of characters in the frequency map.
   - Once we have all the unique characters in the window (i.e., `count == total_unique`), we try to shrink the window by moving `i` to minimize the window size while maintaining all unique characters.
   - The moment a unique character is removed (frequency becomes 0), we stop shrinking and continue expanding.

### Time Complexity:
- **O(n)**: Both `i` and `j` traverse the string once, and each update to the frequency map takes constant time. Hence, the overall complexity is linear, which is efficient for `n = 100,000`.

Let me know if you need further clarification!

 */