#include <iostream>
using namespace std;
#include<vector>
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        //the point where the left product == right product shoud have the same no of twos on both the left and right side
        vector<int>freq(n,0);
        int prevTwo = 0;
        for(int i = 0;i<n;i++){
          if(arr[i] == 2){
            prevTwo++;
            freq[i] = prevTwo;
          }else{
            freq[i] = prevTwo;
          }
        }
        int ans = -1;
        int last = freq[n-1];
        for(int i = 0;i<n;i++){
           if(freq[i] == (last-freq[i])){
            ans = i;
            break;
           }
        }

           ans == -1 ? ans = ans : ans = ans+1;
          cout<<ans<<" "<<endl;

         
    }
    return 0;
}
