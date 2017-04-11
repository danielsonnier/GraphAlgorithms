// Main.cpp
// Implement triangle algorithim here and run it through adjacency matrices

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "AdjacencyMatrix.h"

using namespace std;

// random graphs size powers of 2 as number of verts (4, 8, up to 2^11)
// each pair of vertices has 0.5 chance of an edge between them
// measure cpu time for each 
// plot time vs size on a log2n vs log graph
// try on random barpitite graphs next

// generate random graphs with certain constricutions (paramaters: size, type
// of graph?) (returns: adajaceny matrix)
// implement algo to find triangles in graphs (should take in an adjacency matrix)
// record times for each algo impelmentation
// generate random barpitite graphs


// size: number of vertices
// bipartite: generate a bipartite graph if true
AdjacencyMatrix generateGraph(int size, bool bipartite) {

    AdjacencyMatrix graph(size);

    // generate bipartite graph
    if (bipartite) {
    }

    // generate non-bipartite graph
    else {
        for (int row = 0; row < size - 1; row++) {
            for (int col = row + 1; col < size; col++) {

                // 50% chance edge is created
                if (rand() % 2) {
                    graph.createEdge(row, col);
                    graph.createEdge(col, row);
                }
            }
        }
    }

    return graph;
}


// graph: checks this for a triangle between vertices
bool containsTriangle(AdjacencyMatrix graph) {

    int size = graph.getSize();

    // loops through every edge in graph
    for (int row = 0; row < size - 1; row++) {
        for (int col = row + 1; col < size; col++) {
            if (graph.isEdge(row, col)) { 
                    
                // loops through every vertex in graph
                for (int vertex = 0; vertex < size; vertex++) {

                    // check if vertex has edge to vertices in first edge
                    if (graph.isEdge(row, vertex) && graph.isEdge(col, vertex)) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}


int main() {

    clock_t start;
    double length;
    vector<int> times(6, 0);
    vector<AdjacencyMatrix> graphs;
    srand((unsigned)time(0));

    graphs.push_back(generateGraph(8, false));
    graphs.push_back(generateGraph(64, false));
    graphs.push_back(generateGraph(256, false));
    graphs.push_back(generateGraph(512, false));
    graphs.push_back(generateGraph(1024, false));
    graphs.push_back(generateGraph(2048, false));

    // runs each graph and times how long to find triangle or not
    for (AdjacencyMatrix graph : graphs) {
        start = clock();
        containsTriangle(graph);
        length = (clock() - start) / (double)CLOCKS_PER_SEC;
        times.push_back(length);
    }



}
