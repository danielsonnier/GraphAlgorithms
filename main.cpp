// Main.cpp
// Implement triangle algorithim here and run it through adjacency matrices

#include <iostream>
#include <ctime>
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

    return graph;
}


// graph: checks this for a triangle between vertices
bool containsTriangle(AdjacencyMatrix graph) {

    // for each element in 2d adjacnecy matrix ( this is an edge)
    // for each vertex in the graph, check if theres an edge from it to both
    // vertes of the above edge
    // if so return true


    
    /*
    // loops through every edge in graph
    for (edge in graph) {

        // loops through every vertex in graph
        for (vertex in graph) {

            // checks if vertex has edge to both vertices in first edge
            if ([vertex][edge1] && [vertex][edge2])
                return true;
            }
        }
    }

    return false;
    */
}


int main() {

    clock_t start;
    double length;

    // non-bipartite graphs
    //AdjacencyMatrix graph8, graph64, graph256, graph512, graph1024, graph2048;
    // bipartite graphs
    //AdjacencyMatrix bi_graph8, bi_graph64, bi_graph256, bi_graph512, bi_graph1024, bi_graph2048;

    AdjacencyMatrix bi_graph8 = generateGraph(8, false);
    
    start = clock();
    // run stuff here
    length = (clock() - start) / (double)CLOCKS_PER_SEC;

    cout << "test" << endl;

}
