#include <stdio.h>

#define MAX 100

void dfs(int adj[MAX][MAX], int V, int s, int visited[MAX]) {
    // Mark the current node as visited
    visited[s] = 1;
    printf("%d ", s);

    // Recur for all adjacent vertices
    for (int i = 0; i < V; i++) {
        if (adj[s][i] == 1 && visited[i] == 0) {
            dfs(adj, V, i, visited);
        }
    }
}

void addEdge(int adj[MAX][MAX], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;  // Undirected graph
}

int main() {
    // Number of vertices in the graph
    int V = 5;

    // Adjacency matrix representation of the graph
    int adj[MAX][MAX] = {0};

    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    // Initialize visited array
    int visited[MAX] = {0};

    // Perform DFS traversal starting from vertex 0
    printf("DFS starting from 0:\n");
    dfs(adj, V, 0, visited);

    return 0;
}
