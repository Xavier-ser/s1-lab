#include <stdio.h>
#include <string.h>
#define MAX 100

int top = -1;
char stack[MAX];

void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

void reverseString(char str[]) {
    int i, len = strlen(str);
    for (i = 0; i < len; i++) {
        push(str[i]);
    }
    for (i = 0; i < len; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
