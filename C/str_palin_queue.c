#include <stdio.h>
#include <string.h>
#define MAX 100

char queue[MAX];
int front = -1, rear = -1;

void enqueue(char ch) {
    if (rear < MAX - 1) {
        if (front == -1) front = 0;
        queue[++rear] = ch;
    }
}

char dequeue() {
    if (front != -1 && front <= rear) {
        return queue[front++];
    }
    return '\0';
}

int isPalindrome(char str[]) {
    int i, len = strlen(str);

    for (i = 0; i < len; i++) {
        enqueue(str[i]);
    }

    int left = 0, right = rear;
    while (left < right) {
        if (queue[left] != queue[right]) {
            return 0; 
        }
        left++;
        right--;
    }
    return 1; 
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';  

    if (isPalindrome(str))
        printf("The string is a palindrome.\n");
    else
        printf("The string is NOT a palindrome.\n");

    return 0;
}
