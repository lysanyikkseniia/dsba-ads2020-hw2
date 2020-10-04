#include "prim.h"

void Graph::printEdges()
{
    for (int i = 0; i < size(); i++)
        std::cout << _edges[i].first.first << ' ' << _edges[i].first.second << ' ' <<
                  _edges[i].second.first << ' ' << _edges[i].second.second;
}

Graph inputGraph()
{
    int n;
    std::cin >> n;
    Graph g;
    double a, b;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a >> b;
        g.pushCoordinate(std::make_pair(a, b));
    }
    return g;
}

double Distance(coordinates setofCoord, double a, double b)
{
    int a1 = setofCoord[a].first;
    int b1 = setofCoord[a].second;
    int a2 = setofCoord[b].first;
    int b2 = setofCoord[b].second;
    return sqrt((a2 - a1) * (a2 - a1) + (b2 - b1) * (b2 - b1));
}

double Distance(Graph g, double a, double b)
{
    double a1 = g[a].first;
    double b1 = g[a].second;
    double a2 = g[b].first;
    double b2 = g[b].second;
    return sqrt((a2 - a1) * (a2 - a1) + (b2 - b1) * (b2 - b1));
}

double MSTPrim(Graph g, Graph& mst)
{
    // Graph mst;
    int n = g.size();
    std::vector<double> min_dist(n + 1, INT_MAX);

    min_dist[0] = 0;
    std::vector<bool> visited(n + 1);

    double res = 0;
    for (int i = 0; i < n; i++)
    {
        bool f = false;
        int index = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && (!f || min_dist[j] < min_dist[index]))
            {
                index = j;
                f = true;
            }
        }
        visited[index] = true;
        res+= min_dist[index];
        // тут запомнить i j
        mst.pushEdge(std::make_pair((std::make_pair(g[i].first, g[i].second)),
                std::make_pair(g[index].first, g[index].second)));
        // std::cout << g[i].first << ' ' << g[i].second << ' ' << g[index].first << ' ' << g[index].second  << std::endl;

        for (int j = 0; j < n; j++)
            if (!visited[j] && min_dist[j] > Distance(g, index, j))
                min_dist[j] = Distance(g, index, j);
    }
    // std::cout << res;
    return res;
}