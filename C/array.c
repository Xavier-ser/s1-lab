#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX], n = 0, choice, pos, val, i, key, found;

    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Update\n5.Display\n6.Sort\n7.Reverse\n8.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (n == MAX) break;
                printf("Enter position and value: ");
                scanf("%d %d", &pos, &val);
                if (pos < 0 || pos > n) break;
                for (i = n; i > pos; i--)
                    arr[i] = arr[i - 1];
                arr[pos] = val;
                n++;
                break;

            case 2:
                if (n == 0) break;
                printf("Enter position: ");
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) break;
                for (i = pos; i < n - 1; i++)
                    arr[i] = arr[i + 1];
                n--;
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &key);
                found = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == key) {
                        printf("Found at index %d\n", i);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Not found\n");
                break;

            case 4:
                printf("Enter position and new value: ");
                scanf("%d %d", &pos, &val);
                if (pos < 0 || pos >= n) break;
                arr[pos] = val;
                break;

            case 5:
                for (i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;

            case 6:
                for (i = 0; i < n - 1; i++)
                    for (int j = 0; j < n - i - 1; j++)
                        if (arr[j] > arr[j + 1]) {
                            int t = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = t;
                        }
                break;

            case 7:
                for (i = 0; i < n / 2; i++) {
                    int t = arr[i];
                    arr[i] = arr[n - i - 1];
                    arr[n - i - 1] = t;
                }
                break;

            case 8:
                return 0;
        }
    }
}
