// AdjacencyMatrix.h

#pragma once

#include <vector>

class AdjacencyMatrix {
    private:
        std::vector< std::vector< bool > > matrix;

    public:
        AdjacencyMatrix(int n);
        void createEdge(int i, int j);
        bool isEdge(int i, int j);
};
