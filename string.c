#include<stdio.h>
#include<stdlib.h>

char str[100],pat[200],repl[100],ans[100];
int i,j,k,m,fl,c;
void read();
void match();
int main()
{
    read();
    match();
    return 0;
}
void read()
{
    printf("\n Enter the string \n");
    gets(str);
    printf("\n Enter the string patern \n");
    gets(pat);
    printf("\n Enter the replacement string \n");
    gets(repl);
}
void match()
{
    i=j=m=c=0;
    while(str[c]!='\0')
    {
        if(str[m]==pat[i])
        {
            i++;
            m++;
            if(pat[i]=='\0')
            {
                fl=1;
                for(k=0;repl[k]!='\0';k++,j++)
                {
                    ans[j]=repl[k];
                }
                i=0;;
                c=m;
            }
        }
        else{
            ans[j]=str[c];
            j++;
            c++;
            m=c;
            i=0;
        }
    }
    ans[j]='\0';
    if(fl==1)
    printf("\n rsultant string is \n %s ",ans);
    else
        printf("\n rsultant string not fount ");
}