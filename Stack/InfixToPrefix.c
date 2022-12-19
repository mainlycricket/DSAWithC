#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100

void infixToPrefix(char[]);
int evaluatePrefix(char[]);
int priority(char);
void push(int);
int pop();

int stack[MAX], top = -1;
char prefix[MAX];

int main()
{
    char infix[MAX];
    int result;
    printf("\nEnter an infix expression: ");
    gets(infix);

    infixToPrefix(infix);
    printf("\nEquivalent prefix expression: ");
    puts(strrev(prefix));

    result = evaluatePrefix(prefix);
    printf("\nResult of expression: %d", result);

    return 0;
}

void infixToPrefix(char infix[])
{
    int infixLen = strlen(infix), prefixCounter = 0;
    int temp;
    for (int i = infixLen - 1; i >= 0; i--)
    {
        switch (infix[i])
        {
        case ')':
        case '}':
        case ']':
            push(')');
            break;

        case '(':
        case '{':
        case '[':
            temp = pop();
            while (temp != ')')
            {
                prefix[prefixCounter++] = temp;
                temp = pop();
            }
            break;

        case '^':
        case '/':
        case '*':
        case '+':
        case '-':
            while (top >= 0 && priority(stack[top]) > priority(infix[i]))
            {
                prefix[prefixCounter++] = pop();
            }
            push(infix[i]);
            break;

        case ' ':
            break;

        default:
            prefix[prefixCounter++] = infix[i];
            break;
        }
    }

    while (top != -1)
    {
        prefix[prefixCounter++] = pop();
    }
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

int evaluatePrefix(char prefix[])
{
    int prefixLen = strlen(prefix);
    for (int i = prefixLen - 1; i >= 0; i--)
    {
        if (prefix[i] >= '0' && prefix[i] <= '9')
        {
            push(prefix[i] - '0');
        }
        else
        {
            int a = pop();
            int b = pop();

            switch (prefix[i])
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
    int data = stack[top];
    top -= 1;
    return data;
}
