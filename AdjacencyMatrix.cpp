// AdjacencyMatrix.cpp

#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int n) {
    matrix.resize(n, std::vector< bool >(n));
}

void AdjacencyMatrix::createEdge(int i, int j) {
    matrix[i][j] = true;
}

bool AdjacencyMatrix::isEdge(int i, int j) {
    return matrix[i][j];
}
