#include <stdio.h>
int i,j,n;
int indegree[10],a[10][10];
void toposort()
{
    int source,num=n,f=0;
    printf("Topological Sorting is : ");
    while(num>0)
    {
        for(i=1;i<=n;i++)
        if(indegree[i]==0)
        {
            source=i;
            f=1;
            break;
        }
        if(f==0)
        {
            printf("Not Possible");
            break;
        }
        indegree[source]=-1;
        printf("%d ",source);
        num--;
        for(i=1;i<=n;i++)
        if(a[source][i]==1)
        indegree[i]--;
    }
    printf("\n");
}
void calindegree()
{
    for(i=1;i<=n;i++)
    indegree[i]=0;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(a[i][j])
    indegree[j]++;
}
int main()
{
    printf("Enter the number of Nodes : ");
    scanf("%d",&n);
    printf("Enter the Adjacency Matrix : ");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
    calindegree();
    toposort();
    return 0;
}
