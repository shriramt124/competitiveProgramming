#include <bits/stdc++.h>
using namespace std;
/* https://codeforces.com/contest/1696/problem/B */
void solv(){
int n;
        cin >> n;
        vector<int> arr(n);
        int l = INT_MAX;
        int r = -100000000;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i]>0){
            l = min(l,i);
            r = max(r,i);
            }
        }
        int maxEle = *max_element(arr.begin(),arr.end());
        if(maxEle == 0){
            cout<<0<<endl;
           return;
        }
        for(int i = l;i<=r;i++){
            if(arr[i] == 0){
                cout<<2<<endl;
              return;
            }
        }
        cout<<1<<endl;

        return ;
       
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solv();
         
        }

        return 0;
    }
   
 /* 
 The answer is at most 2
, because doing the operation on [1,n]
 at most twice will always work. (If the array contains at least one zero, we need 2
 operations. Otherwise we need 1
 operation.)

If the array consists of zeroes, the answer is 0
.

If all non-zero elements form a contiguous segment in the array, the answer is $1$​. To check this, you can find the leftmost and rightmost occurrence of non-zero elements and check if elements in the middle of them are also non-zero.

Otherwise the answer is 2
.

Time complexity is O(n)

  */