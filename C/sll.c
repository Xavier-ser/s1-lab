#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head=NULL;

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBegining(int value){
    struct Node* newNode = createNode(value);
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtCustom(int value, int pos){
    
}

void insertAtEnd(int value){
    struct Node* newNode=createNode(value);
    if(head == NULL){
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while(temp->next!==NULL){
        temp=temp->next
    }
    temp->next=newNode;
}

void deleteAtFront(){
    
}

void deleteAtCustom(int pos){
    
}

void deleteAtEnd(){
    
}

void display(){
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main(){
    int ch, value, op, pos;
    while(1){
            printf("Enter operation to perform\n");
        printf("1. Insertion  2.Deletion  3.Display  4.Exit: ");
        scanf("%d",&ch);printf("\n");
        switch(ch){
            case 1: printf("1. Beginning, 2. Custom,  3. End: ");
                    scanf("%d",&op);printf("\n");
                    switch(op){
                        case 1: printf("Enter element to insert: ");
                                scanf("%d", &value);
                                insertAtBegining(value);
                                printf("\n")
                                break;
                        case 2: printf("Enter element to insert: ");
                                scanf("%d", &value);
                                printf("Enter position to insert: ");
                                scanf("%d", &pos);
                                insertAtCustom(value,pos);
                                printf("\n")
                                break;
                        case 3: printf("Enter element to insert: ");
                                scanf("%d", &value);
                                insertAtEnd(value);
                                printf("\n")

                                break;
                    }
                    break;
            case 2: printf("1. Begining, 2. Custom,  3. End: ");
                    scanf("%d",&op);printf("\n");
                    switch(op){
                        case 1: deleteAtFront();
                                printf("\n")

                                break;
                        case 2: printf("Enter pos to insert: ");
                                scanf("%d", &pos);
                                deleteAtCustom(pos);
                                printf("\n")

                                break;
                        case 3: deleteAtEnd();
                                printf("\n")
                                break;
                    }
                    break;
            case 3: display();
                    printf("\n")

                    break;
            case 4: return 1;
                    break;

        }
    }
}