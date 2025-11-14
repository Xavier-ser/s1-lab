#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int n;

void enqueue(int v) {
    if (rear == MAX - 1)
        printf("Queue overflow\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = v;
    }
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void BFS(int start) {
    int i, v;
    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int edges, v1, v2, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (v1 v2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &v1, &v2);
        adj[v1][v2] = adj[v2][v1] = 1;  
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal starting from vertex %d: ", start);
    BFS(start);
    printf("\n");

    return 0;
}
