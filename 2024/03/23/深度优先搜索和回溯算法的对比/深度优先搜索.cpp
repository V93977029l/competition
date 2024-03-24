#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int node)
{
    visited[node] = true;
    cout << "Visited node: " << node << endl;

    for (int i = 0; i < graph[node].size(); ++i)
    {
        int neighbor = graph[node][i];
        if (!visited[neighbor])
        {
            dfs(graph, visited, neighbor);
        }
    }
}

int main()
{
    vector<vector<int>> graph = {{1, 2}, {0, 3, 4}, {0, 5}, {1}, {1}, {2}};
    int startNode = 0;
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);

    dfs(graph, visited, startNode);

    return 0;
}
