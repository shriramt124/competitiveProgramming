#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str = to_string(n);
        int len = str.length();
        if (len < 3)
        {
            cout << "NO" << endl;
        }
        else
        {
            // take the last two digit
            int thousandNum = pow(10, len - 1);
            if ((n / thousandNum )> 1 || str.substr(0,2) != "10")
            {
                cout << "NO" << endl;
            }
            else
            {
                string lastTwo = str.substr(2, n);
                int lastTwoNum = stoi(lastTwo);
                // there should be no leading zeros
                if (lastTwo[0] == '0')
                {
                    cout << "NO" << endl;
                }
                else if (lastTwoNum >= 2)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
    }

    return 0;
}