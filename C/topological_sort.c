#include <stdio.h>

#define MAX 100

int graph[MAX][MAX]; // adjacency matrix to store edges
int visited[MAX];    // marks visited nodes
int stack[MAX];      // to store topological order
int top = -1;        // stack top pointer
int n;               // number of vertices

// Function to push a vertex onto the stack
void push(int v) {
    stack[++top] = v;
}

// Function for Depth-First Search
void dfs(int v) {
    visited[v] = 1;  // mark vertex as visited
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i])
            dfs(i);  // visit all adjacent vertices
    }
    push(v);  // after visiting neighbors, push current vertex
}

// Function for topological sorting
void topologicalSort() {
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i);  // do DFS for all unvisited vertices
    }

    printf("Topological order: ");
    while (top != -1)
        printf("%d ", stack[top--]); // pop from stack
    printf("\n");
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // initialize the graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // mark edge u -> v
    }

    topologicalSort();

    return 0;
}
