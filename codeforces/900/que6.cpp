#include<iostream>
using namespace std;
#define int long long 
/* https://codeforces.com/problemset/problem/1855/B */
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%2!=0){
            cout<<1<<endl;
             continue;
        }
        int firstNum = n;
        for(int i = 1;i<=n;i++){
                if(n%i != 0){
                    firstNum =i;
                    break;
                }
        }
        if(firstNum == n){
            cout<<firstNum<<endl;
        }else
        cout<<firstNum-1<<endl;
    }
    return 0;
}
/* 
The concept behind the Codeforces problem "Longest Divisors Interval" is rooted in **divisibility** and **continuous intervals**. Here's how you can break it down and think about the problem:

### Problem Concept:

You are given a number `n`, and your task is to find the **longest contiguous interval** `[1, k]` where every integer in this interval divides `n`. Essentially, for all `i` from 1 to `k`, the condition `n % i == 0` must hold true.

### Key Insight:

- Every number has divisors, but as you go higher (beyond certain values), numbers stop being divisors of `n`. For example, if `n = 12`, its divisors are 1, 2, 3, 4, and 6. However, numbers like 5, 7, etc., will not divide `12`.
- The largest such interval will start from 1 and extend up to the largest integer `k` such that **all integers from 1 to k divide `n`**.

### Thought Process:

1. **Understand Divisors**:  
   A divisor of `n` is any number `i` where `n % i == 0`. This problem asks you to find the maximum range `[1, k]` where all numbers from 1 to `k` are divisors of `n`.

2. **Incremental Check**:  
   Start checking from `i = 1`. If `n % i == 0`, continue incrementing `i`. The moment you find an `i` such that `n % i != 0`, stop, because it breaks the condition of being a divisor.

3. **Optimization**:  
   You don't need to check divisors beyond `sqrt(n)` for some optimizations, but since you are checking small intervals starting from 1, a simple linear loop will suffice.

### How to Approach:

1. **Initialize**: Start with the smallest number, i.e., `i = 1`.
2. **Expand the Interval**: For each number `i`, check if `n % i == 0`. If true, keep expanding the interval.
3. **Stop When Condition Breaks**: Once you find an `i` where `n % i != 0`, stop and return the largest interval `[1, k]` you found.

### Example:

For `n = 12`:
- Start checking from 1.
- 1 divides 12.
- 2 divides 12.
- 3 divides 12.
- 4 divides 12.
- 5 does not divide 12 (stop here).
- The largest interval is `[1, 4]`.

 
 
  */