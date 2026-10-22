#include<stdio.h>
#include<string.h>
#include "defines.h"
#include "dec.c"
#define MAX 100
char stack[MAX];
int top=-1;
int main()
{
        char Infix[MAX];
        char Postfix[MAX];
        printf("Enter the infix Expression\n");
        scanf("%s",Infix);
        InfixToPostfix(Infix,Postfix);
        printf("Postfix expression is: %s\n",Postfix);
}
