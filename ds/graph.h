#pragma once

const int MAX_VERTICES = 200;

struct Graph {
    int vertices[MAX_VERTICES];                 
    int adjMat[MAX_VERTICES][MAX_VERTICES];      
    int numVertices;      

    Graph() {
        numVertices = 0;
        for (int i = 0; i < MAX_VERTICES; ++i) {
            vertices[i] = -1; 
            for (int j = 0; j < MAX_VERTICES; ++j) {
                adjMat[i][j] = 0; 
            }
        }
    }

    int size() const {
        return numVertices;
    }

    int addVertex(int val) {
        if (numVertices >= MAX_VERTICES) return -1;
        int newIndex = numVertices;
        vertices[newIndex] = val;
        numVertices++;
        return newIndex; 
    }

    void addEdge(int i, int j) {
        if (i >= 0 && i < numVertices && j >= 0 && j < numVertices && i != j) {
            adjMat[i][j] = 1;
            adjMat[j][i] = 1;
        }
    }

    int getVertex(int index) {
        if (index >= 0 && index < numVertices) return vertices[index];
        return -1;
    }

    bool hasEdge(int i, int j) {
        if (i >= 0 && i < numVertices && j >= 0 && j < numVertices) {
            return adjMat[i][j] == 1;
        }
        return false;
    }

    int getDegree(int i) {
        if (i < 0 || i >= numVertices) return 0;
        int deg = 0;
        for (int j = 0; j < numVertices; ++j) {
            if (adjMat[i][j] == 1) {
                deg++;
            }
        }
        return deg;
    }
};
