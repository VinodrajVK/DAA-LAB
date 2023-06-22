#include <stdio.h>
int a[10][10],n,visit[10],acyclic=1,queue[10],f=0,r=-1;
void bfs(int s)
{
for(int i=s;i<=n;i++)
{
if(a[s][i]&&visit[i])
acyclic=0;
if(a[s][i]&&!visit[i])
{
queue[++r]=i;
printf("%d--%d\n",s,i);
}
if(r>=f)
{
visit[queue[r]]=1;
bfs(queue[f++]);
}
}
}
void connectandcyclic()
{
int f=1;
for(int i=1;i<=n;i++)
if(!visit[i])
{
f=0;
bfs(i);
}
if(f)
printf("Graph is Connected\n");
else
printf("Graph is Disconnected\n");
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
visit[i]=0;
printf("Enter the adjacency matrix\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
bfs(start);
connectandcyclic();
}
