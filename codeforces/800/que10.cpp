#include <iostream>
using namespace std;
#include <vector>
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n = 10;
        // create a 2d vector of size n*n
        vector<vector<char>> v(n, vector<char>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < 5; i++)
        {

            for (int j = i; j < 10 - i; j++)
            {
                // loop for left row

                if (v[j][i] == 'X')
                {
                    
                    v[j][i] = '.';
                    ans += i + 1;
                }

                // loop top bottom

                if (v[i][j] == 'X')
                {
                    
                    v[i][j] = '.';
                    ans += i + 1;
                }

                // bottom

                if (v[j][9 - i] == 'X')
                {
                   
                    v[j][9 - i] = '.';
                    ans += i + 1;
                }

                // right

                if (v[9 - i][j] == 'X')
                {
                   
                    v[9-i][j] = '.';
                    ans += i + 1;
                }
            }
        }
         

        cout << ans << endl;
    }
    return 0;
}
