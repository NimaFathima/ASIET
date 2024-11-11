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
    int V = 6;

    // Adjacency matrix representation of the graph
    int adj[MAX][MAX] = {0};

    // Add edges to the graph
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 0, 3);
    addEdge(adj, 4, 5);

    // Initialize visited array
    int visited[MAX] = {0};

    // Perform DFS traversal from all vertices to ensure all nodes are covered
    printf("DFS traversal of the graph:\n");
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(adj, V, i, visited);
        }
    }

    return 0;
}
