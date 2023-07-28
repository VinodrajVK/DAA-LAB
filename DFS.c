#include <stdio.h>
#include <stdlib.h>
int i, n, j, count = 0, opc, visit[10], acyclic = 1, t = -1;
int a[10][10], traverse[10][10], Stack[10];
void dfs(int s)
{
    int p[n];
    int k = 1, flag = 0;
    count++;
    Stack[++t] = s;
    p[s] = -1;
    while (t != -1)
    {
        flag = 0;
        s = Stack[t];
        if (visit[s] != 1)
            traverse[count][k++] = s;
        visit[s] = 1;
        for (i = 1; i <= n; i++)
        {
            if (a[s][i] && visit[i] == 1 && i != p[s])
                acyclic = 0;
            if (a[s][i] && visit[i] == -1)
            {
                Stack[++t] = i;
                visit[i] = 0;
                flag = 1;
                p[i] = s;
                break;
            }
        }
        if (flag == 0)
        {
            visit[Stack[t]] = 2;
            t--;
        }
    }
}
void connectandcyclic()
{
    int flag = 1;
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == -1)
        {
            flag = 0;
            dfs(i);
        }
    }
    if (flag)
    {
        printf("Graph is Connected\n");
        for (j = 1; j <= n; j++)
            printf("%d ", traverse[1][j]);
    }
    else
    {
        printf("Graph is Disconnected\n");
        printf("Number of Connected Components : %d\n", count);
        printf("They are\n");
        for (i = 1; i <= count; i++)
        {
            printf("Component-%d : ", i);
            for (j = 1; j <= n; j++)
                if (traverse[i][j] != 0)
                    printf("%d ", traverse[i][j]);
            printf("\n");
        }
    }
    if (acyclic)
        printf("\nGraph is Acyclic\n");
    else
        printf("\nGraph is Cyclic\n");
}
int main()
{
    int start;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        visit[i] = -1;
    opc = 0;
    count = 0;
    printf("Enter the adjacency matrix\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            opc++;
            scanf("%d", &a[i][j]);
        }
    printf("Enter the Starting Vertex : ");
    scanf("%d", &start);
    dfs(start);
    connectandcyclic();
    printf("Operation Count : %d\n", opc);
    return 0;
}
