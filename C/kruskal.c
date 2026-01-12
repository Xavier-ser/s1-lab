#include <stdio.h>
#include <stdlib.h>

// Structure to store one edge
typedef struct {
    int src, dest, weight;
} Edge;

// Structure for Disjoint Set
typedef struct {
    int parent;
} Subset;

// Compare function for qsort (sort by weight)
int compareEdges(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}

// Find function: finds the parent (leader) of a vertex
int find(Subset subsets[], int i) {
    if (subsets[i].parent == i)
        return i;
    return find(subsets, subsets[i].parent);
}

// Union function: joins two sets
void unionSets(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);
    subsets[rootY].parent = rootX;
}

// Kruskal's Algorithm
void kruskal(Edge edges[], int V, int E) {

    // Step 1: Sort edges by weight
    qsort(edges, E, sizeof(Edge), compareEdges);

    // Step 2: Create subsets
    Subset subsets[V];
    for (int i = 0; i < V; i++)
        subsets[i].parent = i;

    Edge mst[V - 1];  // To store MST edges
    int e = 0; // MST edge count
    int i = 0; // Edge index

    // Step 3: Pick smallest edges and avoid cycles
    while (e < V - 1 && i < E) {
        Edge next = edges[i++];

        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);

        // If no cycle, include the edge
        if (x != y) {
            mst[e++] = next;
            unionSets(subsets, x, y);
        }
    }

    // Print MST
    printf("\nMinimum Spanning Tree:\n");
    int totalWeight = 0;
    for (int j = 0; j < e; j++) {
        printf("%d -- %d (weight = %d)\n", 
               mst[j].src, mst[j].dest, mst[j].weight);
        totalWeight += mst[j].weight;
    }

    printf("Total Weight = %d\n", totalWeight);
}

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    Edge edges[E];

    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskal(edges, V, E);

    return 0;
}
