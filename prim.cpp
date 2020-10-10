#include "prim.h"

void Graph::printEdges()
{
    for (int i = 0; i < _edges.size(); i++)
        std::cout << _edges[i].first.first << ' ' << _edges[i].first.second << ' ' <<
                  _edges[i].second.first << ' ' << _edges[i].second.second << std::endl;
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
    double a1 = setofCoord[a].first;
    double b1 = setofCoord[a].second;
    double a2 = setofCoord[b].first;
    double b2 = setofCoord[b].second;
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
    std::vector<double> minDist(n + 1, INT_MAX);
    minDist[0] = 0;
    std::vector<bool> visited(n + 1);
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        bool f = false;
        int index = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && (!f || minDist[j] < minDist[index]))
            {
                index = j;
                f = true;
            }
        }
        visited[index] = true;
        res+= minDist[index];
        int parent = 0;
        double dist = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (j != index && (Distance(g, index, j) < dist) && visited[j])
            {
                dist = Distance(g, index, j);
                parent = j;
            }
        }
        if (parent != index)
            mst.pushEdge(std::make_pair((std::make_pair(g[parent].first, g[parent].second)),
                std::make_pair(g[index].first, g[index].second)));
        for (int j = 0; j < n; j++)
            if (!visited[j] && minDist[j] > Distance(g, index, j))
                minDist[j] = Distance(g, index, j);
    }
    return res;
}