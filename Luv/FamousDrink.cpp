#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int binarySearch(int arr[], int target, int n)
{

    int ans = 0;
    int s = 0;
    int e = n;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] <= target)
        {
            ans = mid + 1; // storing the index
            s = mid + 1;   // updating the start pointer
        }
        else
        {
            e = mid - 1;
        }
        // updating the mid
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //sorting the array to apply binary search
    sort(arr,arr+n);
    
    int q;
    cin >> q;
    int coins[q];
    for (int i = 0; i < q; i++)
    {
        cin >> coins[i];
    }

  
   
    for (int i = 0; i < q; i++)
    {
        int target = coins[i];
        // applying binary search for each element
      cout<<binarySearch(arr,target,n-1)<<endl;
        
    }
 
  
    return 0;
}
