#include <stdio.h>
#define INF 9999
#define MAX 100

int main() {
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int n, i, j, ne = 1;
    int min, a, b, u, v;
    int total_cost = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;  
        }
    }

    visited[0] = 1;  

    printf("\nEdges in the Minimum Spanning Tree:\n");
    while (ne < n) {
        min = INF;

        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        if (!visited[v]) {
            printf("Edge %d: (%d -> %d) cost = %d\n", ne, a, b, min);
            total_cost += min;
            visited[b] = 1;
            ne++;
        }

        cost[a][b] = cost[b][a] = INF;  
    }

    printf("\nMinimum cost = %d\n", total_cost);

    return 0;
}
