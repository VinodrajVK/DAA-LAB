#include <stdio.h>
int a[10][10],n,visit[10],acyclic=1,S[10],top=-1,pop[10],k=0;
void dfs(int v)
{
int i,f=0,f1=0;
S[++top]=v;
while(top!=-1)
{
f=0,f1=0;
v=S[top];
visit[v]=1;
for(i=1;i<=n;i++)
{
if(a[v][i]&&visit[i]==1)
{
acyclic=0;
}
if(a[v][i]&&visit[i]==-1)
{
S[++top]=i;
visit[i]=0;
f1=1;
break;
}
}
if(f1==0)
{
visit[S[top]]=2;
pop[k++]=S[top--];
}
}
}
void connectandcyclic()
{
int f=1,i,j;
for(i=1;i<=n;i++)
{
if(visit[i]==-1||visit[i]==0)
{
f=0;
dfs(i);
}
}
if(f==1&&acyclic==1)
{
printf("\nToplogical Sorting is \n");
for(j=n-1;j>=0;j--)
printf("%d ",pop[j]);
printf("\n");
}
else if(!acyclic)
printf("Toplogical Sorting is not possible because graph is Cyclic\n");
else if(f==0&&acyclic)
{
printf("\nToplogical Sorting is \n");
for(j=n-1;j>=0;j--)
printf("%d ",pop[j]);
printf("\n");
}
}
void main()
{
int i,j,start=1;
printf("Enter the number of nodes : ");
scanf("%d",&n);
for(i=1;i<=n;i++)
visit[i]=-1;
printf("Enter the adjacency matrix\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
dfs(start);
connectandcyclic();
}
