// AdjacencyMatrix.cpp

#include "AdjacencyMatrix.h"
#include <iostream>

AdjacencyMatrix::AdjacencyMatrix(int n) {
    size = n;
    matrix.resize(n, std::vector< bool >(n));
}

void AdjacencyMatrix::createEdge(int i, int j) {
    matrix[i][j] = true;
}

bool AdjacencyMatrix::isEdge(int i, int j) {
    return matrix[i][j];
}

void AdjacencyMatrix::addVertex() {
    matrix.resize(matrix.size() + 1, std::vector< bool >(matrix.size() + 1));

    size++;
}

void AdjacencyMatrix::removeVertex(int i) {
    matrix.erase(matrix.begin() + i);

    for (int j = 0; j < matrix.size(); j++) 
        matrix[j].erase(matrix[j].begin() + i);

    size--;
}

int AdjacencyMatrix::degree(int i) {
    int degree = 0;

    for (int j = 0; j < matrix.size(); j++) {
        if (matrix[i][j])
            degree++;
    }

    return degree;
}

int AdjacencyMatrix::getSize() {
    return size;
}

void AdjacencyMatrix::printMatrix() {
    for (int row = 0; row < size - 1; row++) {
        std::cout << std::endl;

        for (int i = 0; i < row; i++) 
            std::cout << "  ";

        for (int col = row + 1; col < size; col++) {

            if (isEdge(row, col))
                std::cout << "1 ";
            else
                std::cout << "0 ";
        }
    }
}
