#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        vector<int> pref(n + 1);
        for (int i = 1; i <= n; i++)
        {
            pref[i] = pref[i-1] +arr[i];
        }
        while(q--){
            int l,r,k;
            cin>>l>>r>>k;
            int sum = pref[n];
            sum-=pref[r]-pref[l-1];
            sum+=((r-l+1)*k);
            if(sum%2 == 0){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
            }
        }


    }
    return 0;
}