#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int v) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = v;
    n->next = NULL;
    return n;
}

void insertBeg(int v) {
    struct Node* n = createNode(v);
    n->next = head;
    head = n;
}

void insertEnd(int v) {
    struct Node* n = createNode(v);
    if (!head) {
        head = n;
        return;
    }
    struct Node* t = head;
    while (t->next)
        t = t->next;
    t->next = n;
}

void insertPos(int v, int p) {
    if (p == 1) {
        insertBeg(v);
        return;
    }
    struct Node* n = createNode(v);
    struct Node* t = head;
    for (int i = 1; i < p - 1 && t; i++)
        t = t->next;
    if (!t) return;
    n->next = t->next;
    t->next = n;
}

void deleteBeg() {
    if (!head) return;
    struct Node* t = head;
    head = head->next;
    free(t);
}

void deleteEnd() {
    if (!head) return;
    if (!head->next) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* t = head;
    while (t->next->next)
        t = t->next;
    free(t->next);
    t->next = NULL;
}

void deletePos(int p) {
    if (!head) return;
    if (p == 1) {
        deleteBeg();
        return;
    }
    struct Node* t = head;
    for (int i = 1; i < p - 1 && t->next; i++)
        t = t->next;
    if (!t->next) return;
    struct Node* d = t->next;
    t->next = d->next;
    free(d);
}

void search(int k) {
    struct Node* t = head;
    int pos = 1;
    while (t) {
        if (t->data == k) {
            printf("Found at position %d\n", pos);
            return;
        }
        t = t->next;
        pos++;
    }
    printf("Not found\n");
}

void update(int p, int v) {
    struct Node* t = head;
    for (int i = 1; i < p && t; i++)
        t = t->next;
    if (!t) return;
    t->data = v;
}

void count() {
    int c = 0;
    struct Node* t = head;
    while (t) {
        c++;
        t = t->next;
    }
    printf("Count = %d\n", c);
}

void reverse() {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void display() {
    struct Node* t = head;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int ch, v, p;

    while (1) {
        printf("\n1.Insert Beg");
        printf("\n2.Insert End");
        printf("\n3.Insert Pos");
        printf("\n4.Delete Beg");
        printf("\n5.Delete End");
        printf("\n6.Delete Pos");
        printf("\n7.Search");
        printf("\n8.Update");
        printf("\n9.Count");
        printf("\n10.Reverse");
        printf("\n11.Display");
        printf("\n12.Exit\n");

        scanf("%d", &ch);

        switch (ch) {
            case 1: scanf("%d", &v); insertBeg(v); break;
            case 2: scanf("%d", &v); insertEnd(v); break;
            case 3: scanf("%d %d", &v, &p); insertPos(v, p); break;
            case 4: deleteBeg(); break;
            case 5: deleteEnd(); break;
            case 6: scanf("%d", &p); deletePos(p); break;
            case 7: scanf("%d", &v); search(v); break;
            case 8: scanf("%d %d", &p, &v); update(p, v); break;
            case 9: count(); break;
            case 10: reverse(); break;
            case 11: display(); break;
            case 12: exit(0);
        }
    }
}
