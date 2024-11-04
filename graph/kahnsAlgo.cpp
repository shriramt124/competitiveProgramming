#include <bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
set<int> visited;
stack<int> st;

void addEdge(int src, int dest, bool isBidirectional = false)
{
  graph[src].push_back(dest);
  if (isBidirectional)
  {
    graph[dest].push_back(src);
  }
}

void topologicalSort()
{
  int graphSize = graph.size();
  vector<int> indeg;
  indeg.resize(graphSize);
  vector<int> ans;
  for (int i = 0; i < graph.size(); i++)
  {
    for (auto j : graph[i])
    {
      indeg[j]++;
    }
  }

  // now push the vertex whoose indeg = 0
  queue<int> q;
  for (int i = 0; i < indeg.size(); i++)
  {
    if (indeg[i] == 0)
    {
      q.push(i);
    }
  }
  while (!q.empty())
  {
    int front = q.front();
    q.pop();
    ans.push_back(front);
    // now minimize all indeg of the front node
    for (auto neighbour : graph[front])
    {
      indeg[neighbour]--;
      if (indeg[neighbour] == 0)
      {
        q.push(neighbour);
      }
    }
  }
  for (auto ele : ans)
  {
    cout << ele << " ";
  }
}
int main()
{
  int v;
  cout << "Enter the no of vertex you want to add in the graph ";
  cin >> v;
  cout << "Enter the no of Edge in the graph ";
  int e;
  cin >> e;
  graph.resize(v);
  for (int i = 0; i < e; i++)
  {
    int src, dest;
    cin >> src >> dest;
    addEdge(src, dest);
  }

  topologicalSort();
}
