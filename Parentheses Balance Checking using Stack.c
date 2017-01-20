#include <stdio.h>
int main()
{
    char string[1000],myStack[1000];
    int top = -1,i;
    printf("Enter Expression to check :");
    scanf("%s",string);
    int length = strlen(string);
    char ch;
    for(i=0;i<length;i++)
    {
        ch = string[i];
        if(top >= 0 && myStack[top] == '(' && ch == ')')
            top--;
        else
            myStack[++top] = ch;
    }
    if(top < 0)
        printf("%s is Balanced\n", string);
    else
        printf("%s is Not-balanced\n", string);
}
