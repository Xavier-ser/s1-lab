#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

void push(int v) {
    if (top == MAX - 1)
        printf("Stack overflow\n");
    else
        stack[++top] = v;
}

int pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

void DFS(int start) {
    int i, v;
    push(start);
    while (top != -1) {
        v = pop();
        if (!visited[v]) {
            printf("%d ", v);
            visited[v] = 1;
        }
        for (i = n - 1; i >= 0; i--) { 
            if (adj[v][i] == 1 && !visited[i])
                push(i);
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

    printf("DFS Traversal using stack starting from vertex %d: ", start);
    DFS(start);
    printf("\n");

    return 0;
}
