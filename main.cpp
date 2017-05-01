// Main.cpp

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "AdjacencyMatrix.h"

using namespace std;

/* Paramaters: Size of graph, whether or not graph is bipartitek
 * Returns: AdjacencyMatrix representing graph
 */
AdjacencyMatrix generateGraph(int size, bool bipartite) {

    AdjacencyMatrix graph(size);

    // generate bipartite graph
    if (bipartite) {
        for (int row = 0; row < (size/2); row++) {
            for (int col = (size/2); col < size; col++) {

                // 50% chance edge is created
                if (rand() % 2) {
                    graph.createEdge(row, col);
                    graph.createEdge(col, row);
                }
            }
        }
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


/* Paramaters: Graph
 * Returns: Size of maximum independent set in graph
 */
int sizeOfMaxSet(AdjacencyMatrix graph) {
    int size = 0;

    while (graph.getSize() != 0) {
        for (int i = 1; i < graph.getSize(); i++) {
            if (graph.isEdge(0, i)) {
                    graph.removeVertex(i); 
                    i--;
            }
        }

        graph.removeVertex(0);
        size++;
    }

    return size;
}


/* Paramaters: Graph
 * Returns: Whether or not graph contains triangle of vertices
 */
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
    srand((unsigned)time(0));

    // FIND MAXIMUM INDEPENDENT SET
    vector<AdjacencyMatrix> graphs;
    graphs.push_back(generateGraph(8, false));
    graphs.push_back(generateGraph(64, false));
    graphs.push_back(generateGraph(256, false));
    graphs.push_back(generateGraph(512, false));
    graphs.push_back(generateGraph(1024, false));
    graphs.push_back(generateGraph(2048, false));
    graphs.push_back(generateGraph(4096, false));

    for (AdjacencyMatrix graph : graphs) {
        cout << "Graph size: " << graph.getSize() << endl;
        cout << "Max independent set: " << sizeOfMaxSet(graph) << endl;
        cout << endl;
    }


    /* 
    // FIND TRIANGLE
    clock_t start;
    double length;
    vector<int> times;
    vector<int> bi_times;
    vector<AdjacencyMatrix> graphs;
    vector<AdjacencyMatrix> bi_graphs;
    srand((unsigned)time(0));

    // generate normal graphs
    graphs.push_back(generateGraph(8, false));
    graphs.push_back(generateGraph(64, false));
    graphs.push_back(generateGraph(256, false));
    graphs.push_back(generateGraph(512, false));
    graphs.push_back(generateGraph(1024, false));
    graphs.push_back(generateGraph(2048, false));

    // generate biparte graphs
    bi_graphs.push_back(generateGraph(8, true));
    bi_graphs.push_back(generateGraph(64, true));
    bi_graphs.push_back(generateGraph(256, true));
    bi_graphs.push_back(generateGraph(512, true));
    bi_graphs.push_back(generateGraph(1024, true));
    bi_graphs.push_back(generateGraph(2048, true));

    // runs each graph and times how long to find triangle or not
    for (AdjacencyMatrix graph : graphs) {
        start = clock();
        containsTriangle(graph);
        length = clock() - start;
        times.push_back(length);
    }

    for (AdjacencyMatrix graph : bi_graphs) {
        start = clock();
        containsTriangle(graph);
        length = clock() - start;
        bi_times.push_back(length);
    }

    cout << "Normal graph times: " << endl;
    for (int time : times)
        cout << time << " ";

    cout << "\n\nBipartite graph times :" << endl;
    for (int time : bi_times)
        cout << time << " ";
    cout << endl;
    */
}
