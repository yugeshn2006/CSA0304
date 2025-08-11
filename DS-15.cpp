#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void insert(int key) {
    int i = key % SIZE;
    int start = i;
    while (hashTable[i] != -1) {
        i = (i + 1) % SIZE;
        if (i == start) return; // table full
    }
    hashTable[i] = key;
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d ", hashTable[i]);
    printf("\n");
}

int main() {
    for (int i = 0; i < SIZE; i++) hashTable[i] = -1;
    insert(5); insert(15); insert(25); insert(35);
    display();
    return 0;
}

