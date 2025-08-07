#include <stdio.h>
int main() {
    int a[100], n = 0, ch, pos, val;
    while (1) {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter position and value: ");
            scanf("%d%d", &pos, &val);
            for (int i = n; i > pos; i--) a[i] = a[i - 1];
            a[pos] = val; n++;
        } else if (ch == 2) {
            printf("Enter position: ");
            scanf("%d", &pos);
            for (int i = pos; i < n - 1; i++) a[i] = a[i + 1];
            n--;
        } else if (ch == 3) {
            printf("Array: ");
            for (int i = 0; i < n; i++) printf("%d ", a[i]);
        } else break;
    }
    return 0;
}

