#include <iostream>
#include <vector>
using namespace std;

bool canwego(int a, int b, vector<vector<int>> grid)
{
    return (a >= 0 and b >= 0 and a < grid.size() and b < grid.size() and grid[a][b] == 1);
}

int f(int i, int j, vector<vector<int>> &grid)
{

    if (i == grid.size() - 1 and j == grid.size() - 1)
        return 1;

    int ans = 0;
    grid[i][j] = 2;
    if (canwego(i, j + 1, grid))
        ans += f(i, j + 1, grid);

    if (canwego(i+1, j, grid))
        ans += f(i + 1, j, grid);
    if (canwego(i, j - 1, grid))
        ans += f(i, j - 1, grid);
    if (canwego(i-1, j, grid))
        ans += f(i - 1, j, grid);

    grid[i][j] = 1; // backtrack
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> v = {{1, 1, 1, 1},
                             {0, 1, 0, 1},
                             {0, 1, 1, 1},
                             {0, 1, 1, 1}};

    cout<<f(0,0,v)<<endl;;

    return 0;
}
