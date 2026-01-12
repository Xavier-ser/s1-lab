#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Create new node */
struct node* createNode(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

/* Insert at end */
void insertEnd(int val) {
    struct node *newNode = createNode(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

/* Display list */
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* 1. Print even position nodes */
void printEvenPos() {
    struct node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (pos % 2 == 0)
            printf("%d ", temp->data);
        temp = temp->next;
        pos++;
    }
    printf("\n");
}

/* 2. Print odd position nodes */
void printOddPos() {
    struct node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (pos % 2 != 0)
            printf("%d ", temp->data);
        temp = temp->next;
        pos++;
    }
    printf("\n");
}

/* 3. Print alternate nodes */
void printAlternate() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        if (temp->next != NULL)
            temp = temp->next->next;
        else
            break;
    }
    printf("\n");
}

/* 4. Find middle */
void findMiddle() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *slow = head;
    struct node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle element: %d\n", slow->data);
}

/* 5. Reverse list */
void reverseList() {
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    printf("List reversed\n");
}

/* 6. Reverse in pairs */
void reversePairs() {
    if (head == NULL || head->next == NULL)
        return;

    struct node *prev = NULL;
    struct node *curr = head;
    head = head->next;

    while (curr != NULL && curr->next != NULL) {
        struct node *nextPair = curr->next->next;
        struct node *second = curr->next;

        second->next = curr;
        curr->next = nextPair;

        if (prev != NULL)
            prev->next = second;

        prev = curr;
        curr = nextPair;
    }

    printf("Reversed in pairs\n");
}

/* 7. Print reverse (recursion) */
void printReverseRec(struct node *temp) {
    if (temp == NULL)
        return;
    printReverseRec(temp->next);
    printf("%d ", temp->data);
}

void printReverse() {
    printReverseRec(head);
    printf("\n");
}

/* 8. Remove duplicates from sorted list */
void removeDuplicatesSorted() {
    struct node *temp = head;

    while (temp != NULL && temp->next != NULL) {
        if (temp->data == temp->next->data) {
            struct node *dup = temp->next;
            temp->next = dup->next;
            free(dup);
        } else {
            temp = temp->next;
        }
    }
    printf("Duplicates removed (sorted list)\n");
}

/* 9. Remove duplicates from unsorted list */
void removeDuplicatesUnsorted() {
    struct node *i, *j, *prev;

    for (i = head; i != NULL; i = i->next) {
        prev = i;
        for (j = i->next; j != NULL; ) {
            if (i->data == j->data) {
                prev->next = j->next;
                free(j);
                j = prev->next;
            } else {
                prev = j;
                j = j->next;
            }
        }
    }
    printf("Duplicates removed (unsorted list)\n");
}

/* 10. Count occurrences */
void countOccurrence(int key) {
    int count = 0;
    struct node *temp = head;

    while (temp != NULL) {
        if (temp->data == key)
            count++;
        temp = temp->next;
    }

    printf("Count of %d = %d\n", key, count);
}

/* 11. Nth node from end */
void nthFromEnd(int n) {
    struct node *first = head;
    struct node *second = head;

    for (int i = 0; i < n; i++) {
        if (first == NULL) {
            printf("N is larger than list size\n");
            return;
        }
        first = first->next;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    printf("Nth node from end: %d\n", second->data);
}

/* 12. Check palindrome */
int isPalindrome() {
    int arr[100], i = 0;
    struct node *temp = head;

    while (temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    int start = 0, end = i - 1;
    while (start < end) {
        if (arr[start] != arr[end])
            return 0;
        start++;
        end--;
    }
    return 1;
}

/* 13. Swap two nodes */
void swapNodes(int x, int y) {
    if (x == y)
        return;

    struct node *prevX = NULL, *currX = head;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    struct node *prevY = NULL, *currY = head;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    if (currX == NULL || currY == NULL) {
        printf("One or both elements not found\n");
        return;
    }

    if (prevX != NULL)
        prevX->next = currY;
    else
        head = currY;

    if (prevY != NULL)
        prevY->next = currX;
    else
        head = currX;

    struct node *temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    printf("Nodes swapped\n");
}

/* 14. Delete alternate nodes */
void deleteAlternate() {
    struct node *temp = head;

    while (temp != NULL && temp->next != NULL) {
        struct node *del = temp->next;
        temp->next = del->next;
        free(del);
        temp = temp->next;
    }

    printf("Alternate nodes deleted\n");
}

/* 15. Move last node to first */
void moveLastToFirst() {
    if (head == NULL || head->next == NULL)
        return;

    struct node *prev = NULL;
    struct node *temp = head;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    temp->next = head;
    head = temp;

    printf("Last node moved to first\n");
}

/* 16. Detect loop */
int detectLoop() {
    struct node *slow = head;
    struct node *fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return 1;
    }
    return 0;
}

/* 17. Length of loop */
void loopLength() {
    struct node *slow = head;
    struct node *fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            int count = 1;
            fast = fast->next;
            while (slow != fast) {
                count++;
                fast = fast->next;
            }
            printf("Loop length: %d\n", count);
            return;
        }
    }

    printf("No loop found\n");
}

/* 18. Merge two sorted lists */
struct node* mergeSorted(struct node* a, struct node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct node* result = NULL;

    if (a->data <= b->data) {
        result = a;
        result->next = mergeSorted(a->next, b);
    } else {
        result = b;
        result->next = mergeSorted(a, b->next);
    }

    return result;
}

/* 19. Split list into two halves */
void splitList() {
    if (head == NULL || head->next == NULL) {
        printf("Cannot split\n");
        return;
    }

    struct node *slow = head;
    struct node *fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct node *secondHalf = slow->next;
    slow->next = NULL;

    printf("First half: ");
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\nSecond half: ");
    temp = secondHalf;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* 20. Rearrange odd position nodes first, then even */
void rearrangeOddEven() {
    if (head == NULL || head->next == NULL)
        return;

    struct node *odd = head;
    struct node *even = head->next;
    struct node *evenHead = even;

    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    printf("List rearranged (odd positions first)\n");
}


/* Menu */
int main() {
    int ch, val;

    while (1) {
        printf("\n----- LINKED LIST OPERATIONS MENU -----\n");
printf("1. Insert at end\n");
printf("2. Display list\n");
printf("3. Print even position nodes\n");
printf("4. Print odd position nodes\n");
printf("5. Print alternate nodes\n");
printf("6. Find middle of list\n");
printf("7. Reverse list\n");
printf("8. Reverse list in pairs\n");
printf("9. Print list in reverse\n");
printf("10. Remove duplicates (sorted list)\n");
printf("11. Remove duplicates (unsorted list)\n");
printf("12. Count occurrences of an element\n");
printf("13. Nth node from end\n");
printf("14. Check palindrome\n");
printf("15. Swap two nodes\n");
printf("16. Delete alternate nodes\n");
printf("17. Move last node to first\n");
printf("18. Detect loop\n");
printf("19. Find length of loop\n");
printf("20. Split list into two halves\n");
printf("21. Rearrange odd-even positions\n");
printf("0. Exit\n");
printf("--------------------------------------\n");
printf("Enter your choice: ");

        scanf("%d", &ch);

        switch(choice)
{
    case 1:
        printf("Enter value: ");
        scanf("%d", &val);
        insertEnd(val);
        break;

    case 2:
        display();
        break;

    case 3:
        printEvenPos();
        break;

    case 4:
        printOddPos();
        break;

    case 5:
        printAlternate();
        break;

    case 6:
        findMiddle();
        break;

    case 7:
        reverseList();
        break;

    case 8:
        reversePairs();
        break;

    case 9:
        printReverse();
        break;

    case 10:
        removeDuplicatesSorted();
        break;

    case 11:
        removeDuplicatesUnsorted();
        break;

    case 12:
        printf("Enter element: ");
        scanf("%d", &val);
        countOccurrence(val);
        break;

    case 13:
        printf("Enter N: ");
        scanf("%d", &val);
        nthFromEnd(val);
        break;

    case 14:
        if(isPalindrome())
            printf("Palindrome\n");
        else
            printf("Not Palindrome\n");
        break;

    case 15:
        printf("Enter two values to swap: ");
        scanf("%d %d", &x, &y);
        swapNodes(x, y);
        break;

    case 16:
        deleteAlternate();
        break;

    case 17:
        moveLastToFirst();
        break;

    case 18:
        if(detectLoop())
            printf("Loop detected\n");
        else
            printf("No loop\n");
        break;

    case 19:
        loopLength();
        break;

    case 20:
        splitList();
        break;

    case 21:
        rearrangeOddEven();
        break;

    case 0:
        exit(0);

    default:
        printf("Invalid choice\n");
}

    }
}
