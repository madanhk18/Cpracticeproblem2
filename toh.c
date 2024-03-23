#include<stdio.h>
void toh(int n,char from,char to, char aux)
{
    if(n==1)
    {
        printf("Move disk 1 from peg %c to peg %c\n",from,to);
    }
    else{
        toh(n-1,from,aux,to);
         printf("Move disk %d from peg %c to peg %c \n",n,from,to);
        toh(n-1,aux,to,from);
    }
}

main()
{
    int n;
    printf("Enter number of terms \n");
    scanf("%d",&n);
    if(n<1)
    {   
        printf("wrong input");
    }
    else
    {
        printf("The disk moves in the tower of hanoi is \n");
        toh(n,'A','B','C');
    }
}