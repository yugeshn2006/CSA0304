#include <stdio.h>
int main() {
    int a[100], n, key, low = 0, high, mid;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter key: ");
    scanf("%d", &key);
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key) return printf("Found at position %d\n", mid), 0;
        else if (key < a[mid]) high = mid - 1;
        else low = mid + 1;
    }
    printf("Not Found\n");
    return 0;
}

