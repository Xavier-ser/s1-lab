#include <stdio.h>
#include <stdlib.h>
#define MAX 2
 

void push(int a[],  int num);
void pop(int a[]);
void display(int a[]);
int top = -1;
int main()
{
    int ch, a[MAX], num;

    while(1){
        printf("Enter Operation\n 1.Push  2.Pop  3.Display  4.Exit\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("Enter value to push: ");
        scanf("%d", &num);
        push(a, num);
        break;

    case 2:
        pop(a);
        break;

    case 3:
        display(a);
        break;

    case 4:
        return 0;
        break;

    default:
        printf("Invalid Choice\n");
    }
}
return 0;
}

void push(int a[],  int num){
    if (top >= MAX -1){
        printf("Stack Overflow");
    }else{
        top++; 
        a[top] = num;

        printf("%d successfully pushed\n", num);
        // printf("top-> %d", top);
    }
}

void pop(int a[]){
    if (top < 0){
        printf("Stack Underflow\n");
    }else{
        printf("%d successfully popped\n", a[top]);
        top--;
    }
}

void display(int a[]){
    if(top<0){
        printf("Stack Is Empty\n");
    }else{
        int i;
        printf("Stack elements: ");
        for(i=(top); i>=0; i--){
            printf("%d ", a[i]);
    }
    printf("\n");
    }
}



















