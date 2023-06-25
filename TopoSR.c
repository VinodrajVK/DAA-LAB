#include <stdio.h>
int i, j, n, Queue[10], f = 0, r = -1, opc = 0;
int indegree[10], inqueue[10], a[10][10];
void toposort()
{
    int source, num = n, flag = 0;
    printf("Topological Sorting is : ");
    while (num > 0)
    {
        for (i = 1; i <= n; i++)
            if (indegree[i] == 0 && inqueue[i] == 0)
            {
                inqueue[i] = 1;
                Queue[++r] = i;
                flag = 1;
            }
        if (flag == 0)
        {
            printf("Not Possible");
            break;
        }
        source = Queue[f++];
        indegree[source] = -1;
        printf("%d ", source);
        num--;
        for (i = 1; i <= n; i++)
            if (a[source][i] == 1)
                indegree[i]--;
    }
    printf("\n");
}
void calindegree()
{
    for (i = 1; i <= n; i++)
    {
        indegree[i] = 0;
        inqueue[i] = 0;
    }

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            opc++;
            if (a[i][j])
                indegree[j]++;
        }
}
int main()
{
    printf("Enter the number of Nodes : ");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix :\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    calindegree();
    toposort();
    printf("Operation Count : %d\n", opc);
    return 0;
}
