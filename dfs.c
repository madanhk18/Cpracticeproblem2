#include<stdio.h>
#include<stdlib.h>

int a[10][10],n,src,i,j;

bfs(int src)
{
    int q[10],f=-1,r=-1;
    int v[10],i,j;

    for(j=1;j<=n;j++)
        v[j]=0;

    q[++r]=src;
    v[src]=1;
    while(f<r)
    {
        i=q[++f];
        printf("%d->",i);
        for(j=1;j<=n;j++)
        {
            if(a[i][j]==1 && v[j]!=1)
            {
                v[j]=1;
                q[++r]=j;
            }
        }
    }
    printf("\n");
    for(j=1;j<=n;j++)
    {
        if(v[j]==1)
        printf("\n Visited %d",j);
        else
        printf("Not visited");
    }
}

dfs(int src)
{
    int s[10],top=-1;
    int v[10],i,j;

    for(j=1;j<=n;j++)
    {
        v[j]=0;
    }
    v[src]=1;
    s[++top]=src;
    while(top!=-1)
    {
        i=s[top--];
        printf("%d->",i);
        for(j=1;j<=n;j++)
        {
            if(a[i][j]==1 && v[j]!=1)
            {
                v[j]=1;
                s[++top]=j;
            }
        }
    }
    printf("\n");
    for(j=1;j<=n;j++)
    {
        if(v[j]==1)
        printf("\n Visited %d",j);
        else
        printf("\n Not visited %d",j);
    }
}
int main()
{
    int ch;
    printf("\n Enter the n for matrix \n");
    scanf("%d",&n);
    printf("\n enter the matrix \n ");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        scanf("%d",&a[i][j]);

    printf("\n Matrix has been created \n");
    for(;;)
    {
        printf("\n 1.BFS\n 2.DFS \n 3.Exit \n");
        printf("Enter coice -> \n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:for(i=1;i<=n;i++)
        {
            printf("Enter the source vertex for BFS \n");
            scanf("%d",&src);
            bfs(src);
        }
        break;

        case 2:
        for(i=1;i<=n;i++)
        {
            printf("Enter the source vertex for DFS\n");
            scanf("%d",&src);
            dfs(src);
        }
        break;
       
       case 3: exit(0);
       break;
        
        default:printf("\n Invalid ");
            break;
        }
    }
    return 0;
}