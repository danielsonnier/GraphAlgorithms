// Main.cpp
// Implement triangle algorithim here and run it through adjacency matrices

#include <iostream>
#include <AdjacencyMatrix.h>

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
AdjacencyMatrix generateGraph(int size, boolean bipartite) {


}


int main() {

    // non-bipartite graphs
    AdjacencyMatrix graph8, graph64, graph256, graph512, graph1024, graph2048;
    // bipartite graphs
    AdjacencyMatrix bi_graph8, bi_graph64, bi_graph256, bi_graph512, bi_graph1024, bi_graph2048;

    // AdjacencyMatrix bi_graph8 = generateGraph(8, false);





    
    




}
