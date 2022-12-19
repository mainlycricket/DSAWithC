// Converts an infix expression to postfix notation and evaluates the result (1-digit whole numbers)

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100

void infixToPostfix(char[]);
int postfixEvaluation(char[]);
int priority(char);
void push(int);
int pop();

// global variables
int stack[MAX], top = -1;
char postfix[MAX];

int main()
{
    char infix[MAX];
    int result;
    printf("\nEnter an infix expression: ");
    gets(infix);

    infixToPostfix(infix);
    printf("\nPostfix Equivalent: ");
    puts(postfix);

    result = postfixEvaluation(postfix);
    printf("\nResult of expression: %d", result);

    return 0;
}

void infixToPostfix(char infix[])
{
    int infixLen = strlen(infix), postfixCounter = 0;
    char temp;

    for (int i = 0; i < infixLen; i++)
    {
        switch (infix[i])
        {
        case '(':
        case '{':
        case '[':
            push('(');
            break;

        case ')':
        case '}':
        case ']':
            temp = pop();
            while (temp != '(')
            {
                postfix[postfixCounter++] = temp;
                temp = pop();
            }
            break;

        case '^':
        case '/':
        case '*':
        case '+':
        case '-':
            while (priority(stack[top]) >= priority(infix[i]))
            {
                postfix[postfixCounter++] = pop();
            }
            push(infix[i]);
            break;

        case ' ':
            break;

        default:
            postfix[postfixCounter++] = infix[i];
            break;
        }
    }

    while (top != -1)
    {
        postfix[postfixCounter++] = pop();
    }
}

int postfixEvaluation(char postfix[])
{
    int postfixLen = strlen(postfix);
    for (int i = 0; i < postfixLen; i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            push(postfix[i] - '0');
        }
        else
        {
            int b = pop();
            int a = pop();

            switch (postfix[i])
            {
            case '^':
                push(pow(a, b));
                break;
            case '/':
                push(a / b);
                break;
            case '*':
                push(a * b);
                break;
            case '+':
                push(a + b);
                break;
            case '-':
                push(a - b);
                break;
            }
        }
    }
    return pop();
}

int priority(char symbol)
{

    switch (symbol)
    {
    case '^':
        return 3;
        break;

    case '/':
    case '*':
        return 2;
        break;

    case '+':
    case '-':
        return 1;
        break;

    default:
        return 0;
        break;
    }
}

void push(int symbol)
{
    if (top == MAX - 1)
    {
        printf("\nStack OVERFLOW!");
        exit(1);
    }

    top += 1;
    stack[top] = symbol;
}

int pop()
{
    if (top == -1)
    {
        printf("\nStack UNDERFLOW!");
        exit(1);
    }

    int data;
    data = stack[top];
    top -= 1;
    return data;
}
