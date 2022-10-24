#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char a[20];
int top= -1;
char r[20];
int rp=0;

int z[20];
int topz=-1;
void push(char c)
{
 top++;
 a[top]=c;
}

char pop()
{
    if(top<0)
    {
        exit(1);
    }
    else{
        int e=a[top];
        top=top-1;
        return(e);

    }

}
void pushz(char c)
{
 topz++;
 printf("%d",c-48);
 z[topz]=c-48;
}

char popz()
{
    if(topz<0)
    {
        exit(1);
    }
    else{
        int e=z[topz];
        topz=topz-1;
        return(e);

    }


}

int precedence(char a)
{
    if (a == '(')
    {
        return 0;
    }
    else if (a == '*' || a == '/')
        {
        return 2;
    }
    else if (a=='+'||a=='-')
        {
        return 1;
    }
    else
    {
        return 0;
    }

    return 0;

}


int main()
    {
        char s[30];
        int l;
        char x;
        printf("enter string");
        scanf("%s",&s);
        l=strlen(s);

        for(int i=0;i<l;i++)
        {
            if (isalnum(s[i]))
            {
                printf("%c",s[i]);
                r[rp]=s[i];
                rp++;

            }

            else if (s[i] == '(')
            {
                push(s[i]);

            }
            else if(s[i]==')')
            {

                x=pop();
                while(x!='(')
                {
                    if(x=='+'||x=='-'||x=='*'||x=='/')
                    {
                        printf("%c",x);
                        r[rp]=x;
                        rp++;
                        x=pop();
                    }

                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                while(precedence(a[top])>precedence(s[i]) || precedence(a[top]=precedence(s[i])))
                {

                    x=pop();
                    printf("%c",x);
                    r[rp]=x;
                    rp++;


                }

                push(s[i]);
            }


        }

        printf("\n");



        while (top!=-1)
        {
            char x=pop();

            r[rp]=x;
            rp++;
        }



        int m=strlen(r);

        float t=0;
        for(int i=0;i<m;i++)
        {
            if(isdigit(r[i]))
            {
                pushz(r[i]);
            }
            else
            {
                int q=popz();
                int w=popz();
                char ch=r[i];
                switch(ch)
                {
                case '+':
                    {
                        t=w+q;
                        break;

                    }
                case '-':
                    {
                        t=w-q;

                        break;

                    }
                case '*':
                    {
                        t=w*q;
                        break;

                    }
                case '/':
                    {
                        t=w/q;
                        break;


                    }
                }
                topz++;
                z[topz]=t;

            }
        }

        float result=popz();

        printf("the result of the expression is %f",result);

        return 0;
    }



