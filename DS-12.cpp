#include <stdio.h>
#include <ctype.h>

char stack[100]; int top = -1;

int prec(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void push(char ch) { stack[++top] = ch; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }

void infixToPostfix(char *exp) {
    for (int i = 0; exp[i]; i++) {
        char ch = exp[i];
        if (isalnum(ch)) printf("%c", ch);
        else if (ch == '(') push(ch);
        else if (ch == ')') {
            while (peek() != '(') printf("%c", pop());
            pop();
        } else {
            while (top != -1 && prec(peek()) >= prec(ch)) printf("%c", pop());
            push(ch);
        }
    }
    while (top != -1) printf("%c", pop());
    printf("\n");
}

int main() {
    char exp[] = "A+B*C";
    infixToPostfix(exp);
    return 0;
}

