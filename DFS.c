#include <stdio.h>
#include <stdlib.h>
int a[10][10],n,visited[10],acyclic=1;

void dfs(int v)
{
int i;
visited[v]=1;
for(i=v;i<=n;i++)
{
if(a[v][i]&&visited[i])
{
acyclic=0;
printf("%d--%d\n",v,i);
}
if(a[v][i]&&!visited[i])
{
printf("%d--%d\n",v,i);
dfs(i);
}
}
}

void connectandcyclic()
{
int i=1;
while(i<=n)
{
if(!visited[i])
break;
i++;
}
if(i==n+1)
printf("Graph is Connected\n");
else
{
printf("Graph is not Connected\n");
dfs(i);
}
if(acyclic)
printf("Graph is Acyclic\n");
else
printf("Graph is Cyclic\n");
}

void main()
{
int i,j,start=1;
printf("Enter the number of nodes : ");
scanf("%d",&n);
for(i=1;i<=n;i++)
visited[i]=0;
printf("Enter the adjacency matrix\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
dfs(start);
connectandcyclic();
}
