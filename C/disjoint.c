#include <stdio.h>

#define MAX 100

int parent[MAX];
int rank[MAX];

/* Initialize disjoint sets */
void makeSet(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

/* Find with path compression */
int findSet(int x)
{
    if (parent[x] != x)
        parent[x] = findSet(parent[x]);
    return parent[x];
}

/* Union by rank */
void unionSet(int x, int y)
{
    int rootX = findSet(x);
    int rootY = findSet(y);

    if (rootX == rootY)
    {
        printf("Already in the same set\n");
        return;
    }

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else
    {
        parent[rootY] = rootX;
        rank[rootX]++;
    }

    printf("Union completed\n");
}

int main()
{
    int n, choice, x, y;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    makeSet(n);

    while (1)
    {
        printf("\n1. Union\n2. Find\n3. Check Same Set\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter two elements: ");
            scanf("%d %d", &x, &y);
            unionSet(x, y);
            break;

        case 2:
            printf("Enter element: ");
            scanf("%d", &x);
            printf("Set representative: %d\n", findSet(x));
            break;

        case 3:
            printf("Enter two elements: ");
            scanf("%d %d", &x, &y);
            if (findSet(x) == findSet(y))
                printf("Same set\n");
            else
                printf("Different sets\n");
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
