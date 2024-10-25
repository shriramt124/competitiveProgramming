#include <iostream>
#include <vector>
using namespace std;

void TraverseDiagonal(vector<vector<int>> &a, int n)
{
    for (int d = 0; d < n; d++)
    {
        int i = 0;
        int j = d;
        while (i < n && j < n)
        {
            cout << a[i][j] << " ";
            i++;
            j++;
        }
        cout << endl;
    }
    for (int d = 1; d < n; d++)
    {
        int i = d;
        int j = 0;
        while (i < n && j < n)
        {
            cout << a[i][j] << " ";
            i++;
            j++;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    TraverseDiagonal(a, n);

    return 0;
}