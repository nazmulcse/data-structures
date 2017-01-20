#include<stdio.h>
#include <string.h>
#include <math.h>

char postfix[1000];
char convertInfixToPostfix(char infix[]);
int evaluatePostfixExpression(char postfix[]);
int operatorPrecedence(char ch);
int calculate(int a, int b, char operatorSign);
int main()
{
    char infixExpression[100];
    printf("Please Enter Infix Expression : ");
    scanf("%s",infixExpression);
    convertInfixToPostfix(infixExpression);
    printf("The Postfix Expression is :%s\n",postfix);
    int result = evaluatePostfixExpression(postfix);
    printf("The Result is %d",result);
    return 0;
}
char convertInfixToPostfix(char *infix)
{
    char ch;
    char myStack[1000];
    int top = -1;
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
int evaluatePostfixExpression(char *postfixExp)
{
    //printf("%s",postfixExp);
    int myStack[1000];
    int top = -1,i,length;
    length = strlen(postfixExp);
    char ch;
    for(i=0;i<length;i++)
    {
        ch = postfixExp[i];
        if(ch >= '0' && ch <= '9')
            myStack[++top] = ch-'0';
        else{
            int a,b;
            b = myStack[top];
            top--;
            a = myStack[top];
            top--;
            myStack[++top] = calculate(a,b,ch);
        }
    }
   //printf("%d",myStack[top]);
    return myStack[top];
}
int calculate(int a, int b, char operatorSign)
{
    if(operatorSign == '+'){
        return a+b;
    }else if(operatorSign == '-'){
        return a-b;
    }else if(operatorSign == '*'){
        return a*b;
    }else if(operatorSign == '/'){
        return a/b;
    }else if(operatorSign == '^'){
        int res = pow(a,b);
        return res;
    }
}
