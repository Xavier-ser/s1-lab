#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int graph[MAX][MAX];
int indegree[MAX];
int n;

// Function to find indegree of each vertex
void findIndegree() {
    for (int i = 0; i < n; i++)
        indegree[i] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (graph[i][j] == 1)
                indegree[j]++;
}

// Function to perform Topological Sort (Kahn’s Algorithm)
void topologicalSort() {
    int count = 0;
    int queue[MAX], front = 0, rear = -1;
    int topo[MAX];

    findIndegree();

    // Enqueue vertices with indegree 0
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[++rear] = i;

    while (front <= rear) {
        int node = queue[front++];
        topo[count++] = node;

        // For each adjacent vertex, reduce indegree
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[++rear] = i;
            }
        }
    }

    if (count != n) {
        printf("\nCycle detected! Topological sorting not possible.\n");
        return;
    }

    printf("\nTopological Order: ");
    for (int i = 0; i < n; i++)
        printf("%d ", topo[i]);
    printf("\n");
}

// Function to create a graph
void createGraph() {
    int edges, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &src, &dest);
        graph[src][dest] = 1; // Directed edge
    }
}

// Display adjacency matrix
void displayGraph() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- TOPOLOGICAL SORTING MENU ---\n");
        printf("1. Create Graph\n");
        printf("2. Display Graph\n");
        printf("3. Perform Topological Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createGraph();
                break;
            case 2:
                displayGraph();
                break;
            case 3:
                topologicalSort();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
