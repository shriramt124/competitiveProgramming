#include <iostream>
using namespace std;
#include <vector>

int solv(vector<int> a, vector<int> b, int n, int m)
{
    int start = max(abs(a[0] - b[0]), abs(a[n - 1] - b[m - 1]));
    // atleast this will be the distace shoule be there
    // now i have to check for the rest of the elements if some cell tower resides
    // in between the two points
    int j = 0; // for the tower
    int i = 0; // for the cell
    while (i < n && j < m)
    {
        if (abs(a[i] - b[j]) <= start)
        {
            // if the distance is less than or equal to start
            // then i can move to the next cell but keep the same tower
            // because the distance is less than start
            // so i can check for the next city also if that can be powered by the tower

            i++;
        }
        else
        {
            // if the distance is greater than start
            // then i can move to the next cell tower

            j++;
        }
    }
    return min(start, abs(a[i] - b[j])) % 10000000007;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int ans = solv(a, b, n, m);
    cout << ans % (10000000007) << endl;

    return 0;
}
