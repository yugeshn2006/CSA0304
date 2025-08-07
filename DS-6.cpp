#include <stdio.h>
int fib(int n) {
    return (n <= 1) ? n : fib(n - 1) + fib(n - 2);
}
int main() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) printf("%d ", fib(i));
    return 0;
}

