#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int bracketsStack[MAX], top = -1;

int verifyExpression(char[]);
int matchBrackets(char);
void push(char);

int main()
{

    char exp[MAX];
    int isValid;
    printf("\nEnter an expression: ");
    gets(exp);

    isValid = verifyExpression(exp);
    if (isValid)
    {
        printf("\nThe given expression is valid!");
    }
    else
    {
        printf("\nThe given expression is invalid!");
    }

    return 0;
}

int verifyExpression(char exp[])
{
    int strLen = strlen(exp);

    for (int i = 0; i < strLen; i++)
    {

        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);

        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            int temp = matchBrackets(exp[i]);
            if (!temp)
                return 0;
        }
    }

    if (top == -1)
        return 1;

    else {
        printf("\nOpening braces are more than closing braces");
        return 0;
    }
        
}

int matchBrackets(char bracket)
{

    char lastBracket;

    if (top == - 1)
    {
        printf("\nClosing braces are more than opening braces!");
        return 0;
    }

    lastBracket = bracketsStack[top];
    top -= 1;

    if (lastBracket == '(' && bracket == ')')
        return 1;
    else if (lastBracket == '{' && bracket == '}')
        return 1;
    else if (lastBracket == '[' && bracket == ']')
        return 1;
    else
        printf("\nOpening & closing braces don't match!");

    return 0;
}

void push(char bracket)
{
    if (top == MAX - 1)
    {
        printf("\nStack OVERFLOW!");
        exit(1);
    }
    top += 1;
    bracketsStack[top] = bracket;
}
