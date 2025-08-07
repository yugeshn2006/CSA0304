#include <stdio.h>
int main() {
    int a[100], n, key, found = 0;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter key: ");
    scanf("%d", &key);
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("Found at position %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found) printf("Not Found\n");
    return 0;
}

