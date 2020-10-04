#ifndef ALGHW2_PRIM_H
#define ALGHW2_PRIM_H
#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<std::pair<double, double>> coordinates;
typedef std::pair<std::pair<double, double>, std::pair<double, double>> edge;

class Graph
{
public:
    void setCoordinates(coordinates x) {_coord = x;}
    void pushCoordinate(std::pair<float, float> x) {_coord.push_back(x);}
    void printEdges();
    void pushEdge(edge x) {_edges.push_back(x);}
    int size() const {return _coord.size();}
    std::pair<double, double>& operator[] (const int index) { return _coord[index];}
    const std::pair<double, double>& operator[] (const int index) const {return _coord[index];}

private:
    coordinates _coord;
    std::vector<edge> _edges;
};

Graph inputGraph();

void printPrimRes();

double Distance(coordinates setofCoord, double a, double b);
double Distance(Graph g, double a, double b);

double MSTPrim(Graph g, Graph& mst);

#endif //ALGHW2_PRIM_H
