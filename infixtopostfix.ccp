#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

// Stack for operators
char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (top >= 0) return stack[top];
    return '\0';
}

int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return -1;
    }
}

int isRightAssociative(char c) {
    return (c == '^');
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int infixToPostfix(char* infix, char* postfix) {
    int i, k = 0;
    int len = strlen(infix);
    int lastWasOperator = 1;  // expression should not start with operator

    for (i = 0; i < len; i++) {
        char c = infix[i];
        if (c == ' ') continue;

        if (isalnum(c)) {  
            postfix[k++] = c;
            lastWasOperator = 0;
        } 
        else if (c == '(') {
            push(c);
            lastWasOperator = 1;
        } 
        else if (c == ')') {
            if (lastWasOperator) return 0;
            while (top >= 0 && peek() != '(') {
                postfix[k++] = pop();
            }
            if (top < 0) return 0; // mismatched parenthesis
            pop(); // remove '('
            lastWasOperator = 0;
        } 
        else if (isOperator(c)) {
            if (lastWasOperator) return 0; // consecutive operators
            while (top >= 0 && isOperator(peek())) {
                char op = peek();
                if ((precedence(op) > precedence(c)) ||
                    (precedence(op) == precedence(c) && !isRightAssociative(c))) {
                    postfix[k++] = pop();
                } else break;
            }
            push(c);
            lastWasOperator = 1;
        } 
        else {
            return 0; // invalid char
        }
    }

    if (lastWasOperator) return 0; // ends with operator → invalid

    while (top >= 0) {
        if (peek() == '(') return 0; // mismatched
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
    return 1;
}

int main() {
    char infix[MAX], postfix[MAX];
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    if (infixToPostfix(infix, postfix))
        printf("%s\n", postfix);
    else
        printf("Invalid expression\n");

    return 0;
}
