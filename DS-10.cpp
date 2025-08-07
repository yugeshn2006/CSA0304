#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

void insert(int val) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    n->data = val;
    n->next = head;
    head = n;
}

void deleteNode() {
    if (head) {
        struct node *t = head;
        head = head->next;
        free(t);
    }
}

void display() {
    struct node *t = head;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    insert(30);
    insert(20);
    insert(10);
    display();
    deleteNode();
    display();
    return 0;
}

