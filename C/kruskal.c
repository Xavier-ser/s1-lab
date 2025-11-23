#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int src, dest, weight;
} Edge;

typedef struct {
    int parent;
    int rank;
} Subset;

int compareEdges(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

void kruskal(Edge edges[], int V, int E) {
    qsort(edges, E, sizeof(Edge), compareEdges);

    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    Edge* mst = (Edge*)malloc((V - 1) * sizeof(Edge));
    int e = 0;   // index for mst[]
    int i = 0;   // index for sorted edges

    while (e < V - 1 && i < E) {
        Edge next = edges[i++];

        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);

        if (x != y) {
            mst[e++] = next;
            unionSets(subsets, x, y);
        }
    }

    printf("\nMinimum Spanning Tree (Kruskal):\n");
    int totalWeight = 0;
    for (int j = 0; j < e; j++) {
        printf("%d -- %d  (weight = %d)\n", mst[j].src, mst[j].dest, mst[j].weight);
        totalWeight += mst[j].weight;
    }

    printf("Total MST Weight = %d\n", totalWeight);

    free(mst);
    free(subsets);
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    Edge* edges = (Edge*)malloc(E * sizeof(Edge));

    printf("Enter edges: src dest weight\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskal(edges, V, E);

    free(edges);
    return 0;
}
