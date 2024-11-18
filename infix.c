#include <stdio.h>
#include <ctype.h> // For isalnum function

int max = 20; // Maximum size of the stack
char stack[20];
int top = -1;

// Function to push an element onto the stack
void push(char x) {
    if (top == max - 1) { // Check stack overflow
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) { // Check stack underflow
        return -1;
    }
    return stack[top--];
}

// Function to check the priority of operators
int priority(char x) {
    if (x == '(') {
        return 0;
    }
    if (x == '+' || x == '-') {
        return 1;
    }
    if (x == '*' || x == '/'||x == '%') {
        return 2;
    }
    if(x== '^')
    {
        return 3;
    }
    return -1; // For unsupported operators
}

int main() {
    char exp[20], *e, x;
    printf("Enter the infix expression: ");
    scanf("%s", exp);
    e = exp;

    printf("Postfix expression: ");
    while (*e != '\0') {
        if (isalnum(*e)) {
            // If the character is alphanumeric, print it directly
            printf("%c", *e);
        } else if (*e == '(') {
            // Push '(' onto the stack
            push(*e);
        } else if (*e == ')') {
            // Pop and print until '(' is encountered
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        } else {
            // For operators, check precedence and handle accordingly
            while (priority(stack[top]) >= priority(*e)) {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }

    // Pop all the remaining operators from the stack
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");

    return 0;
}
