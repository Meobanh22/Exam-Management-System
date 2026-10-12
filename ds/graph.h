#pragma once

const int MAX_VERTICES = 100;

struct Graph {
    int vertices[MAX_VERTICES];                 
    int adjMat[MAX_VERTICES][MAX_VERTICES];      
    int numVertices;      
};

inline Graph newGraph() {
    Graph g;
    g.numVertices = 0;
    for (int i = 0; i < MAX_VERTICES; ++i) {
        g.vertices[i] = -1; 
        for (int j = 0; j < MAX_VERTICES; ++j) {
            g.adjMat[i][j] = 0; 
        }
    }
    return g;
}

inline int size(const Graph &g) {
    return g.numVertices;
}

inline int addVertex(Graph& g, int val) {
    if (g.numVertices >= MAX_VERTICES) return -1;
    int newIndex = g.numVertices;
    g.vertices[newIndex] = val;
    g.numVertices++;
    return newIndex; 
}

inline void addEdge(Graph &g, int i, int j) {
    if (i >= 0 && i < g.numVertices && j >= 0 && j < g.numVertices && i != j) {
        g.adjMat[i][j] = 1;
        g.adjMat[j][i] = 1;
    }
}

inline int getVertex(const Graph &g, int index) {
    if (index >= 0 && index < g.numVertices) return g.vertices[index];
    return -1;
}

inline bool hasEdge(const Graph &g, int i, int j) {
    if (i >= 0 && i < g.numVertices && j >= 0 && j < g.numVertices) {
        return g.adjMat[i][j] == 1;
    }
    return false;
}

inline int getDegree(const Graph &g, int i) {
    if (i < 0 || i >= g.numVertices) return 0;
    int deg = 0;
    for (int j = 0; j < g.numVertices; ++j) {
        if (g.adjMat[i][j] == 1) {
            deg++;
        }
    }
    return deg;
}