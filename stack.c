#include<stdio.h>
#define SIZE 10
int S[SIZE],top=-1;
push()
{
    int ele;
    if(top==SIZE-1)
    {
        printf("stack in overflow\n");
        return 0;
    }
    printf("Enter the element to insert\n");
    scanf("%d",&ele);
    top++;
    S[top]=ele;
}
pop()
{
    if(top==-1)
    {
        printf("stack is underflow\n");
        return 0;
    }
    printf("Deleted element is %d",S[top]);

    top--;
}
void palindrome()
{
    char s[100],str[100];
    int i,flag=-1,top=-1;
    printf("\n Enter the string to check for palindrome \n");
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++)
    s[++top]=str[i];
        for(i=0;str[i]!='\0';i++)
        {
            if(str[i]!=s[top--])
            {
                flag=0;
            }
        }
        if(flag==-1)
        printf("\n it is palindrome \n");
        else
        printf("Not a palindrome ");


}
display()
{
int i,n;
    if(top==-1)
    {
        printf("stack is underflow\n");
        return 0;
    }
    printf("display the element\n");
    for(i=0;i<=top;i++)
    {
        printf("%d \n",S[i]);
    }
}

main()
{
int ch;
for(;;)
{
    printf("\n 1.push \n 2.pop \n 3.display \n 4.palindrome \n");
    printf("Enter the choice\n");
    scanf("%d",&ch);
switch(ch)
{
    case 1:push();
    break;
    case 2:pop();
    break;
    case 3:display();
    break;
    case 4:palindrome();
    break;
}
}
}
