#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define khatam "\n"
#define bhago return
int t;

void solvByRam()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    if (str[0] == '1' || str[n - 1] == '1')
    {
        cout << "YES" << endl;
        bhago;
    }
    else
    {
        if (str.find("11") != string::npos)
        {
            cout << "YES" << endl;
            bhago;
        }
        else
        {
            cout << "NO" << endl;
            bhago;
        }
    }
}

int main()
{
   
    cin >> t;
    while (t--)
    {
        solvByRam();
    }
   return 0;
}