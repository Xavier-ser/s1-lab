#include<stdio.h>

#define Max 5

int queue[Max], front = -1, rear = -1;

void enqueue(int value){
    if(rear == Max-1){
        printf("Queue is full\n\n");
    }else{
        if (front == -1) { 
            front = 0;
        }
        rear = rear+1;
        queue[rear] = value;
        printf("Enqueued: %d", value);
    }
}

void dequeue(){
    if(rear == -1 || front > rear){
        printf("Queue is empty\n\n");
    }else{
        printf("Dequeued: %d", queue[front]);
        
        front = front + 1;
        if (front > rear) { 
            front = -1;
            rear = -1;
        }
    }
}

void display(){
    if(front == -1){
        printf("Queue is empty\n\n");
    }else{
        int i;
        printf("\nQueue is : ");
        for(i=front; i<=rear; i++){
            printf("%d\t", queue[i]);
        }
        printf("\n\n");
    }
}

int main(){
    while(1){
        int ch, num;
        printf("\n\nEnter operation you want to perform: \n");
        printf("1. Enqueue \t2. Dequeue\t3. Display \t4. Exit \n ");
        scanf("%d", &ch);

        switch(ch){
            case 1: printf("Enter element to insert:");
                    scanf("%d", &num);
                    enqueue(num);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
                    break;
            default: printf("Invalid Choice\n");            
        }
    }
    return 0;
}