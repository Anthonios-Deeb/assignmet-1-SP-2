#include "Algorithms.hpp"
#include <iostream>
#include <queue>
#include <limits>

using namespace ariel;
using namespace std;

bool isDirected(vector<vector<int>> &mat)
{
    int n = mat.size(); // Number of vertices in the graph
    // Check if each edge (i, j) has a corresponding edge (j, i)
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (mat[i][j] != mat[j][i])
            {
                // If they are not equal, then the graph is directed
                return true;
            }
        }
    }
    // If no such pair of edges are found, the graph is undirected
    return false;
}

// DFS isConnected
void DFS(vector<vector<int>> &graph, vector<bool> &visited, int node)
{
    visited[node] = true;
    for (size_t i = 0; i < graph.size(); i++)
    {
        if (graph[node][i] != 0 && !visited[i])
        {
            DFS(graph, visited, i);
        }
    }
}

/* we start by creating a vector that contains bool to indicate if we visited a certain node or not
 * then on each node we run Depth search algorithm after each run of DFS we check the values of the vector that we generated
 * and make sure that all the values are true.
 */
int Algorithms::isConnected(Graph &g)
{
    vector<vector<int>> mat = g.getAdjMatrix();

    for (size_t k = 0; k < mat.size(); k++)
    {
        vector<bool> visited(mat.size(), false);
        DFS(mat, visited, k);
        for (size_t i = 0; i < mat.size(); i++)
        {
            if (!visited[i])
            {
                fill(visited.begin(), visited.end(), false);
                return 0; // Graph is not connected
            }
        }
    }
    return 1; // Graph is connected
}

// Shortest Path
string constructPath(vector<int> &parent, int dest)
{
    if (parent[dest] == -1)
    {
        return to_string(dest);
    }
    return constructPath(parent, parent[dest]) + "->" + to_string(dest);
}

string Algorithms::shortestPath(Graph &g, int start, int end)
{
    vector<vector<int>> graph = g.getAdjMatrix();
    vector<int> dist(graph.size(), numeric_limits<int>::max());
    vector<int> parent(graph.size(), -1);

    dist[start] = 0;

    for (size_t i = 0; i < graph.size() - 1; ++i)
    {
        for (size_t u = 0; u < graph.size(); ++u)
        {
            for (size_t v = 0; v < graph.size(); ++v)
            {
                if (graph[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    for (size_t u = 0; u < graph.size(); ++u)
    {
        for (size_t v = 0; v < graph.size(); ++v)
        {
            if (u != v && graph[u][v] && dist[u] != numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v])
            {
                return "Graph contains negative weight cycle.";
            }
        }
    }

    if (dist[end] != numeric_limits<int>::max())
    {
        return constructPath(parent, end);
    }
    else
    {
        return "-1";
    }
}

// this function is used to check if the graph is cyclic or not and prints the cycle if it exists
string isCyclicUnDirected_AUX(vector<vector<int>> &graph, vector<bool> &visited, int node, size_t parent, int *startOfCycle, bool *isCycle)
{
    //   0
    if (visited[node])
    {
        *startOfCycle = node;
        return to_string(node);
    }

    visited[node] = true;
    for (size_t i = 0; i < graph.size(); i++)
    {
        if (graph[node][i] != 0 && i != parent)
        {
            string s = isCyclicUnDirected_AUX(graph, visited, i, node, startOfCycle, isCycle);
            if (s != "-1")
            {
                if (node == *startOfCycle)
                {
                    *isCycle = true;
                    return to_string(node) + "->" + s;
                }
                else if (!*isCycle)
                {
                    return to_string(node) + "->" + s;
                }
                else
                {
                    return s;
                }
            }
        }
    }
    return "-1";
}

string isCyclicUnDirected(vector<vector<int>> &graph, vector<bool> &visited, int node, size_t parent)
{
    int startOfCycle = -1;
    bool isCycle = false;
    return isCyclicUnDirected_AUX(graph, visited, node, parent, &startOfCycle, &isCycle);
}

string isCyclicDirected_AUX(vector<vector<int>> &graph, vector<int> &visited, int node, int *startOfCycle, bool *isCycle)
{
    if (visited[node] == 1)
    {
        *startOfCycle = node;
        return to_string(node);
    }
    if (visited[node] == 2)
    {
        return "-1";
    }

    visited[node] = 1;
    for (size_t i = 0; i < graph.size(); i++)
    {
        if (graph[node][i] != 0)
        {
            string s = isCyclicDirected_AUX(graph, visited, i, startOfCycle, isCycle);
            if (s != "-1")
            {
                if (node == *startOfCycle)
                {
                    *isCycle = true;
                    return to_string(node) + "->" + s;
                }
                else if (!*isCycle)
                {
                    return to_string(node) + "->" + s;
                }
                else
                {
                    return s;
                }
            }
        }
    }
    visited[node] = 2;
    return "-1";
}

string isCyclicDirected(vector<vector<int>> &graph, vector<int> &visited, int node)
{
    int startOfCycle = -1;
    bool isCycle = false;
    return isCyclicDirected_AUX(graph, visited, node, &startOfCycle, &isCycle);
}

// this function is used to check if the graph contains a cycle or not and prints the cycle if it exists
string Algorithms::isContainsCycle(ariel::Graph &g)
{
    vector<vector<int>> adjMat = g.getAdjMatrix();

    if (isDirected(adjMat))
    {
        vector<int> visited(adjMat.size(), 0);

        for (size_t i = 0; i < adjMat.size(); i++)
        {
            if (visited[i] == 0)
            {
                string s = isCyclicDirected(adjMat, visited, i);
                if (s != "-1")
                {
                    return s;
                }
            }
        }
    }
    else
    {
        vector<bool> visited(adjMat.size(), false);

        for (size_t i = 0; i < adjMat.size(); i++)
        {
            if (!visited[i])
            {
                string s = isCyclicUnDirected(adjMat, visited, i, -1);
                if (s != "-1")
                {
                    return s;
                }
            }
        }
    }
    return "-1";
}

// this function is used to check if the graph is bipartite and prints the two sets if it exists the graph might be directed or undirected
string Algorithms::isBipartite(ariel::Graph &g)
{
    vector<vector<int>> adjMat = g.getAdjMatrix();
    vector<int> color(adjMat.size(), -1);
    queue<int> q;
    bool found = false;
    for (size_t i = 0; i < adjMat.size() && !found ; i++)
    {
        color = vector<int>(adjMat.size(), -1);
        if (i>0)
        {
            color[i] = 1 - color[i-1];
        }

        q.push(i);
        color[i] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (size_t v = 0; v < adjMat.size(); v++)
            {
                if (adjMat[u][v] && color[v] == -1)
                {
                    color[v] = 1 - color[u];
                    q.push(v);
                    
                }
                else if (adjMat[u][v] && color[v] == color[u])
                {
                    return "-1";
                }
            }
        }

        for (size_t i = 0; i < color.size(); i++)
        {
            if (color[i] == -1)
            {
                found = false;
                break;
            }
            else
            {
                found = true;
            }
        }
    }

    // Construct the two sets
    string setA = "";
    string setB = "";
    for (size_t i = 0; i < color.size(); i++)
    {
        if (color[i] == 0)
        {
            if (setB != "")
            {
                setB += ",";
            }
            setB += to_string(i);
        }
        else
        {
            if (setA != "")
            {
                setA += ",";
            }
            setA += to_string(i);
        }
    }
    return "The graph is bipartite: A={" + setA + "}, B={" + setB + "}.";
}

// this function is used to check if the graph contains a negative cycle or not and prints the cycle if it exists
string Algorithms::negativeCycle(ariel::Graph &g)
{
    vector<vector<int>> graph = g.getAdjMatrix();
    vector<int> dist(graph.size(), numeric_limits<int>::max());
    vector<int> parent(graph.size(), -1);
    dist[0] = 0;
    
    for (size_t i = 0; i < graph.size() - 1; ++i)
    {
        for (size_t u = 0; u < graph.size(); ++u)
        {
            for (size_t v = 0; v < graph.size(); ++v)
            {
                if (graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    for (size_t u = 0; u < graph.size(); ++u)
    {
        for (size_t v = 0; v < graph.size(); ++v)
        {
            if (graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v])
            {
                size_t start = v;
                string str = to_string(v);
                while (true)
                {
                    start = parent[start];
                    if (start == v)
                    {
                        return  to_string(start) + "->" + str;
                    }
                    str = to_string(start) + "->" + str;
                }
                
            }
        }
    }
    return "-1";
}