#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

void bfs(int start) {
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        for (int i = 0; i < n; i++) {
            if (graph[curr][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int start) {
    int stack[MAX], top = -1;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    stack[++top] = start;

    printf("DFS Traversal: ");

    while (top != -1) {
        int curr = stack[top--];

        if (visited[curr] == 0) {
            printf("%d ", curr);
            visited[curr] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (graph[curr][i] == 1 && visited[i] == 0) {
                stack[++top] = i;
            }
        }
    }
}

int main() {
    int choice, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\n1. BFS (Queue)\n2. DFS (Stack)\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bfs(start);
            break;
        case 2:
            dfs(start);
            break;
        default:
            printf("Invalid choice!");
    }

    return 0;
}
