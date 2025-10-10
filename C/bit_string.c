#include <stdio.h>
#include <string.h>

int main() {
    int n, n1, n2;
    char U[100][20];    
    char set1[100][20], set2[100][20];
    int S1[100] = {0}, S2[100] = {0};
    int setUnion[100], setIntersection[100];

    printf("Enter size of universal set: ");
    scanf("%d", &n);

    printf("Enter elements of universal set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", U[i]);
    }

    printf("Enter size of set1: ");
    scanf("%d", &n1);

    printf("Enter elements of set1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%s", set1[i]);

        for (int j = 0; j < n; j++) {
            if (strcmp(set1[i], U[j]) == 0) {
                S1[j] = 1;
                break;
            }
        }
    }

    printf("Enter size of set2: ");
    scanf("%d", &n2);

    printf("Enter elements of set2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%s", set2[i]);

        for (int j = 0; j < n; j++) {
            if (strcmp(set2[i], U[j]) == 0) {
                S2[j] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        setUnion[i] = S1[i] | S2[i];        
        setIntersection[i] = S1[i] & S2[i]; 
    }

    printf("\nUniversal Set:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", U[i]);
    }

    printf("\n\nBit Vector for Set1:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", S1[i]);
    }

    printf("\n\nBit Vector for Set2:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", S2[i]);
    }

    printf("\n\nUnion Bit Vector:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", setUnion[i]);
    }

    printf("\n\nIntersection Bit Vector:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", setIntersection[i]);
    }

    printf("\n");

    return 0;
}
