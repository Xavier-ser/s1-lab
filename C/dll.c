#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(Node* prevNode, int data) {
    if (prevNode == NULL) return;

    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    prevNode->next = newNode;

    if (newNode->next != NULL)
        newNode->next->prev = newNode;
}

void deleteNode(Node** head, Node* delNode) {
    if (*head == NULL || delNode == NULL) return;

    if (*head == delNode)
        *head = delNode->next;

    if (delNode->next != NULL)
        delNode->next->prev = delNode->prev;

    if (delNode->prev != NULL)
        delNode->prev->next = delNode->next;

    free(delNode);
}

void deleteFromBeginning(Node** head) {
    if (*head == NULL) return;

    Node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL)
        (*head)->prev = NULL;

    free(temp);
}

void deleteFromEnd(Node** head) {
    if (*head == NULL) return;

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        *head = NULL;

    free(temp);
}

void printList(Node* head) {
    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 20);
    insertAfter(head->next, 15); 

    printList(head); 

    deleteFromBeginning(&head);
    printList(head); 

    deleteFromEnd(&head);
    printList(head); 

    deleteNode(&head, head->next); 
    printList(head); 

    return 0;
}
