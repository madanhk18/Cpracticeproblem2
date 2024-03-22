#include<stdio.h>
#include<math.h>
int a[10][10],n;
void dfs(int src)
{
int st[10],top=-1;
int vis[10],i,j;
for(j=1;j<=n;j++)
vis[j]=0;
vis[src]=1;
st[++top]=src;
while(top!=-1)
{
i=st[top--];
for(j=1;j<=n;j++)
if(a[i][j]==1 && vis[j]!=1)
{ vis[j]=1;
st[++top]=j;
}
}
for(j=1;j<=n;j++)
if(vis[j]!=1)
printf("\n node %d is not reachable\n",j);
else
printf("\n node %d is reachable\n",j);
}
int main()
{
int i,j,src;
printf("\n enter the number of nodes\t");
scanf("%d",&n);
printf("\n enter the adjacency matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
printf("\n enter the source node:\n");
scanf("%d",&src);
dfs(src);
return 0;
}