#include<stdio.h>
#include <string.h>
char myStack[1000];
int top = -1;
char convertInfixToPostfix(char infix[]);
int operatorPrecedence(char ch);
int main()
{
    char infixExpression[100];
    printf("Please Enter Infix Expression : ");
    scanf("%s",infixExpression);
    convertInfixToPostfix(infixExpression);
    return 0;
}
char convertInfixToPostfix(char *infix)
{
    char postfix[100] = {'\0'};
    char ch;
    int i,length;
    length = strlen(infix);
    for(i=0;i<length;i++)
    {
        ch = infix[i];
        if(ch == '(')
        {
            myStack[++top] = ch;
        }
        else if(ch == ')')
        {
            while(top>=0 && myStack[top] != '(')
            {
                int len = strlen(postfix);
                postfix[len]=myStack[top];
                top--;
            }
            if(top>=0 && myStack[top] == '(')
            {
                top--;
            }
        }
        else{ // found operator or operand
            int priority = operatorPrecedence(ch);
            if(priority == 0){
                int len = strlen(postfix);
                postfix[len]=ch;
            }else{ // found operator
                if(top <= 0){
                    myStack[++top] = ch;
                }else{
                    while(top >= 0 && myStack[top] != '(' && priority<=operatorPrecedence(myStack[top]))
                    {
                        int len = strlen(postfix);
                        postfix[len]=myStack[top];
                        top--;
                    }
                    myStack[++top] = ch;
                }
            }
        }
    }
    while(top >=0)
    {
        int len = strlen(postfix);
        postfix[len]=myStack[top];
        top--;
    }
    printf("%s",postfix);
}
//check operator precendence.
int operatorPrecedence(char ch)
{
    if(ch == '^'){
        return 3;
    }else if(ch == '/' || ch == '*'){
        return 2;
    }else if(ch == '+' || ch == '-'){
        return 1;
    }else{
        return 0;
    }
}
