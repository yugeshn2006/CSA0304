#include <stdio.h>
int fact(int n) {
    return (n <= 1) ? 1 : n * fact(n - 1);
}
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial = %d\n", fact(n));
    return 0;
}

