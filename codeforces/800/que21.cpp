#include <iostream>
using namespace std;
#include <vector>
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = i; j < n; j++)
            {
                if (arr[j] == 0)  ++count;
                else{
                    
                    count = 0;
                }
                 ans = max(ans,count);
                 
            }
        }
        cout << ans << endl;
    }

    return 0;
}
