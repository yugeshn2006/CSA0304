#include <stdio.h>
#define SIZE 100
int stack[SIZE], top = -1;

void push(int val) {
    if (top < SIZE - 1) stack[++top] = val;
}

void pop() {
    if (top >= 0) top--;
}

void peek() {
    if (top >= 0) printf("Top = %d\n", stack[top]);
}

void display() {
    for (int i = top; i >= 0; i--) printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    push(10); push(20); push(30);
    display(); peek(); pop(); display();
    return 0;
}

