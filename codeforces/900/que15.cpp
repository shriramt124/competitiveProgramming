#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int count = 0;bool NeverPossble = false;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] >= arr[i + 1])
            {

                while (arr[i] >= arr[i + 1] and arr[i]>0)
                {
                    arr[i] = arr[i] / 2;                 
                    count++;
                }
                if(arr[i] == arr[i+1]){
                   
                    NeverPossble = true;
                    break;
                }
              
            }
            if(NeverPossble){
                break;
            }

        }
        if(NeverPossble){
            cout<<"-1"<<endl;
        }else{
            cout<<count<<endl;
        }
        
         
    }
    return 0;
}