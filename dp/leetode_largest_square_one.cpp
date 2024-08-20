#include <iostream>
using namespace std;
#include <vector>

/*
Given a binary matrix mat of size n * m, find out the maximum length of a side of a square sub-matrix with all 1s.

 */

int solv(int i, int j, vector<vector<int>> &matrix, int &maxi)
{
    // base case
    if (i >= matrix.size() || j >= matrix[0].size())
    {
        return 0;
    }
    int right = solv(i, j + 1, matrix, maxi);
    int diagonal = solv(i + 1, j + 1, matrix, maxi);
    int down = solv(i + 1, j, matrix, maxi);
    if (matrix[i][j] == 1)
    {
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        return 0;
    }
}
int solvMemo(int i, int j, vector<vector<int>> &matrix, int &maxi, vector<vector<int>> &dp)
{
    // base case
    if (i >= matrix.size() || j >= matrix[0].size())
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int right = solvMemo(i, j + 1, matrix, maxi, dp);
    int diagonal = solvMemo(i + 1, j + 1, matrix, maxi, dp);
    int down = solvMemo(i + 1, j, matrix, maxi, dp);
    if (matrix[i][j] == 1)
    {
        dp[i][j] = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }
    else
    {
        return dp[i][j] = 0;
    }
}

int solvTab(int n, int m, vector<vector<int>> &matrix, int &maxi)
{
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int right = dp[i][j+1];
            int diagonal = dp[i+1][j+1];
            int down = dp[i+1][j];
            if (matrix[i][j] == 1)
            {
                dp[i][j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, dp[i][j]);
      
            }
            else
            {
             dp[i][j] = 0;
            }
        }
    }
    
}
int LargestSquareWithMaxOne(int n, int m, vector<vector<int>> &matrix)
{
    int maxi = 0;
    solv(0, 0, matrix, maxi);
    return maxi;
}

int main()
{

    int row;
    int column;
    cout << "Enter size of row of matrix : " << endl;
    cin >> row;
    cout << "Enter size of column of matrix : " << endl;
    cin >> column;
    vector<vector<int>> matrix(row, vector<int>(column));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int ans = LargestSquareWithMaxOne(row, column, matrix);
    cout << "Largest max one's area is: " << ans << endl;

    return 0;
}