#include <iostream>
using namespace std;
#include <map>
#include<climits>
int solv(string str, int n)
{
    if(str.size() == 1 || str.size() == 2) return str.size();
    cout<<"functionis running"<<endl;
    map<char, int> odd;
    map<char, int> even;
    for (int i = 0; i < str.size(); i += 2)
    {
        even[str[i]]++;
    }
    for (int i = 1; i < str.size(); i += 2)
    {
        odd[str[i]]++;
    }
    int maxiodd = -1;
    for (auto ele : odd)
    {
        maxiodd = max(maxiodd, ele.second);
    }
    int maxieven = -1;
    for (auto ele : even)
    {
        maxieven = max(maxieven, ele.second);
    }
    int op = 0;
    int mid = n / 2;
    op += (mid - maxieven);
    op += (mid - maxiodd);

    if (n % 2 != 0)
        op++;
  

    return op;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int ans = INT_MAX;
        if(n == 1 || n == 2) {
            cout<<n<<endl;
        }
        else if (n % 2 != 0)
        {  
            cout<<"it is running "<<endl;
             char ele = str[0];
            str.erase(str.begin());
            cout<<str<<endl;
            ans = min(ans,solv(str,n));
            str.insert(0,1,ele);
            ele  = str[n-1];
            str.erase(str.end());
            ans  = min(ans,solv(str,n));
            str+=ele;
            cout<<ans<<endl;
        }
        else{
            ans = min(ans,solv(str,n));
            cout<<ans<<endl;
        
        }
            
        // find the element that have the maxFrequence in odd and even position
    }
}