#include <stdio.h>

void merge(int a[], int l, int m, int r) {
    int i = l, j = m+1, k = 0, b[50];
    while (i <= m && j <= r)
        b[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    while (i <= m) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (i = l, j = 0; i <= r; i++, j++)
        a[i] = b[j];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {8, 4, 5, 1, 3}, n = 5;
    mergeSort(a, 0, n-1);
    display(a, n);
    return 0;
}

