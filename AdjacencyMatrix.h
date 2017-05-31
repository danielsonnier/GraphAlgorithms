// AdjacencyMatrix.h

#pragma once

#include <vector>

class AdjacencyMatrix {
    private:
        std::vector< std::vector< bool > > matrix;
        int size;

    public:
        AdjacencyMatrix(int n);
        void createEdge(int i, int j);
        bool isEdge(int i, int j);
        void addVertex();
        void removeVertex(int i);
        int degree(int i);
        int getSize();
        void printMatrix();
};
