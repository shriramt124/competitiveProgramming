#include <bits/stdc++.h>
using namespace std;
/* https://leetcode.com/problems/pacific-atlantic-water-flow/ */
vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> h;
int row,col;
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
      row = heights.size();
      col = heights[0].size();
    h = heights;
    queue<pair<int, int>> pacificBfs;
    queue<pair<int, int>> atlanticBfs;
    for (int i = 0; i < row; i++)
    {
        pacificBfs.push({i, 0});
        atlanticBfs.push({i, col - 1});
    }
    for (int j = 1; j < col; j++)
    {
        pacificBfs.push({0, j});
    }
    for (int j = 0; j < col - 1; j++)
    {
        atlanticBfs.push({row - 1, j});
    }

    vector<vector<bool>>pacificbfs = multiSourceBfs(pacificBfs);
    vector<vector<bool>>atlanticbfs = multiSourceBfs(atlanticBfs);
    vector<vector<int>>res;
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            if(pacificbfs[i][j] && atlanticbfs[i][j]){
                res.push_back({i,j});
            }
        }
    }
    return res;
}

vector<vector<bool>> multiSourceBfs(queue<pair<int,int>>&q){
 vector<vector<bool>>visited(row,vector<bool>(col,false));
 while( not q.empty()){
  auto front = q.front();
  int i = front.first;
  int j = front.second;
  visited[i][j] = true;
  //now this can go into 4 directiosn left,right ,top and bottom 
  for(int i  = 0 ;i<4;i++){
    int newRow = i+dir[i][0];
    int newCol  = j+dir[i][1];
    if(newRow<0 or newCol < 0 or newRow >=row or newCol>=col){
        continue;
    }
    //if already visited then just return 
    if(visited[newRow][newCol]) continue;

    if(h[newRow][newCol]<h[i][j]) continue;

    q.push({newRow,newCol});

  }
 }
 return visited;
}

    int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> heights(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> heights[n][m];
        }
    }
    vector<vector<int>> ans = pacificAtlantic(heights);

    for(auto row:ans){
        for(auto ele:row){
            cout<<ele<<" ";
        }cout<<endl;
    }
    return 0;
}