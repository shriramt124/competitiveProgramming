#include <bits/stdc++.h>
using namespace std;
vector<long long> sources;
vector<vector<pair<long long, long long>>> graph;
long long n, m;

void multiSourceDijkstra()
{
    vector<long long> dist = sources;;
   
    dist[0] = LLONG_MAX;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
    for (long long i = 1; i <= n; i++)
    {
        pq.push({dist[i], i});
    }
    while (not pq.empty())
    {
        auto [currdistance, currNode] = pq.top();
        pq.pop();
        if (currdistance > dist[currNode])
            continue;
        for (auto [neighbour, distance] : graph[currNode])
        {
            if (dist[currNode] + 2 * distance < dist[neighbour])
            {
                dist[neighbour] = dist[currNode] + 2 * distance;
                pq.push({dist[neighbour], neighbour});
            }
        }
    }
    for (long long i = 1; i <=n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}
void addEdge(long long from, long long to, long long weight)
{
    graph[from].push_back({to, weight});
    graph[to].push_back({from, weight});
}
int main(long long argc, char const *argv[])
{

    cin >> n >> m;
    graph.resize(n + 1);
    for (long long i = 0; i < m; i++)
    {
        long long from, to, weight;
        cin >> from >> to >> weight;
        addEdge(from, to, weight);
    }
    sources.resize(n + 1);
    for(long long i = 1;i<=n;i++){
        cin>>sources[i];
    }
    multiSourceDijkstra();

    return 0;
}
