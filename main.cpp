#include "prim.h"

int main()
{
    Graph energyNetwork = inputGraph();
    Graph mst;
    double mstSize = MSTPrim(energyNetwork, mst);
    std::cout << mstSize;
    mst.printEdges();
    return 0;
}