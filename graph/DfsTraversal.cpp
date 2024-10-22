#include <bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
set<int> visited;
vector<vector<int>> result;

void addEdge(int src, int dest, bool bidirectional = true)
{
    graph[src].push_back(dest);
    if (bidirectional)
    {
        graph[dest].push_back(src);
    }
}

bool checkIfThereIsAnyPathBetweenTwoVertex(int curr, int end)
{
    if (curr == end)
    {
        return true;
    }
    visited.insert(curr);
    for (auto neighbour : graph[curr])
    {
        if (!visited.count(neighbour))
        {
            if (checkIfThereIsAnyPathBetweenTwoVertex(neighbour, end))
            {
                return true;
            }
        }
    }
}

void dfsTraversalGraph(int curr, int end)
{
    if (curr == end)
    {
        cout << curr << " ";
        return;
    }
    cout << curr << " ";
    visited.insert(curr);
    for (auto neighbour : graph[curr])
    {
        if (!visited.count(neighbour))
        {
            dfsTraversalGraph(neighbour, end);
        }
    }
}

void allPaths(int curr, int end, vector<int> &v)
{
    if (curr == end)
    {
        v.push_back(curr);
        result.push_back(v);
        v.pop_back();
        return;
    }

    visited.insert(curr);
    v.push_back(curr);
    for (auto neighbour : graph[curr])
    {
        if (!visited.count(neighbour))
        {
            allPaths(neighbour, end, v);
        }
    }
    v.pop_back();
    visited.erase(curr);
    return;
}

void printAllPaths(int start, int end)
{
    vector<int> v;
    allPaths(start, end, v);
    for (auto row : result)
    {
        for (auto ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}

void printGraph()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << "->";
        for (auto j : graph[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int nodes;
    cout << "enter no of nodes in graph : ";
    cin >> nodes;
    graph.resize(nodes, list<int>());

    int edges;
    cout << "Enter no of edges in the graph : ";
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        cout << "Enter source and destination of edge (src,dest) : ";
        cin >> src >> dest;
        addEdge(src, dest);
    }
    int start, end;
    cout << "Enter the start and end vertes to traverse the graph (start,end ): ";
    cin >> start >> end;
    // // dfsTraversalGraph(start, end) ;
    // cout << endl;
    // cout << checkIfThereIsAnyPathBetweenTwoVertex(start, end);
    printAllPaths(start, end);

    // printGraph();
    return 0;
}