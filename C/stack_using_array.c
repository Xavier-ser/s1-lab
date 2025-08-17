#include <stdio.h>
#include <stdlib.h>
#define MAX 30
void push(int a[], int *top, int num);
void pop(int a[], int *top);
void display(int a[], int *top);

int main()
{
    int ch, a[MAX], num, top = -1;

    while(1){
        printf("Enter Operation\n 1.Push  2.Pop  3.Display  4.Exit\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("Enter value to push: ");
        scanf("%d\n", &num);
        push(a, &top, num);
        break;

    case 2:
        pop(a, &top);
        break;

    case 3:
        display(a, &top);
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

void push(int a[], int *top, int num){
    if (*top >= MAX -1){
        printf("Stack Overflow");
    }else{
        (*top)++; 
        a[*top] = num;

        printf("%d successfully pushed\n", num);
    }
}

void pop(int a[], int *top){
    if (*top < 0){
        printf("Stack Underflow");
    }else{
        printf("%d successfully popped\n", a[*top]);
        (*top)--;
    }
}

void display(int a[], int *top){
    if(*top<0){
        printf("Stack Is Empty");
    }else{
        int i;
        printf("Stack elements: ");
        for(i=(*top); i>=0; i--){
            printf("%d ", a[i]);
    }
    printf("\n");
    }
}
