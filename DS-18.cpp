#include <stdio.h>

int partition(int a[], int l, int r) {
    int p = a[r], i = l-1, t;
    for (int j = l; j < r; j++)
        if (a[j] < p) {
            t = a[++i]; a[i] = a[j]; a[j] = t;
        }
    t = a[i+1]; a[i+1] = a[r]; a[r] = t;
    return i+1;
}

void quickSort(int a[], int l, int r) {
    if (l < r) {
        int pi = partition(a, l, r);
        quickSort(a, l, pi-1);
        quickSort(a, pi+1, r);
    }
}

int main() {
    int a[] = {8, 4, 5, 1, 3}, n = 5;
    quickSort(a, 0, n-1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}

