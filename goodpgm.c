//18.1.19
#include <stdio.h>
#include<string.h>
#include<ctype.h>

char S[100],E[100],ch,ele;
int j=0;

char pop()
{
    char a;
    a=S[j-1];
    j--;
    return a;
}

int push()
{
    S[j]=ch;
    j++;
}

int priority(char x)
{
    if(x=='+'||x=='-')
        return 1;
    if(x=='*'||x=='/')
        return 2;
    if(x=='^')
        return 3;
return 0;
}

int empty()
{
    if(j==0)
        return 1;
    else
        return 0;
}

int main()
{
    int i=0;
    printf("Enter the expression: ");
    scanf("%s",E);
    while(E[i]!='\0')
    {
        ch=E[i];
        if(isalpha(ch))
            printf("%c",ch);
        else if(ch=='(')
            push();
        else if(ch==')')
        {
            while((ele=pop())!='(')
                {printf("%c",ele);}
        }
        else
        {
            if(j!=0)
            {
                while(priority(S[j-1])>=priority(ch))
                {
                    ele=pop();
                    printf("%c",ele);
                }
                
            }
            push();
        }
        i++;
    }
    while(!empty())
    {
        ele=pop();
        printf("%c",ele);
    
    }
        ele=pop();
        printf("%c\n",ele);
    return 0;
}
