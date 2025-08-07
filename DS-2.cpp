#include <stdio.h>
int main() {
    int n, a[100];
    printf("How many numbers? ");
    scanf("%d", &n);
    printf("Enter numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        printf("%d is %s\n", a[i], a[i] % 2 ? "Odd" : "Even");
    }
    return 0;
}

