#include <stdio.h>
int i, n, j, count = 0, opc, visit[10], acyclic = 1, f = 0, r = -1;
int a[10][10], traverse[10][10], queue[10];
void bfs(int s)
{
    int k = 1;
    count++;
    queue[++r] = s;
    while (f <= r)
    {
        s = queue[f++];
        visit[s] = 1;
        traverse[count][k++] = s;
        for (i = s; i <= n; i++)
        {
            opc++;
            if (a[s][i] && (visit[i] == 1))
            {
                opc++;
                acyclic = 0;
            }
            if (a[s][i] && visit[i] == -1)
            {
                opc++;
                queue[++r] = i;
                visit[i] = 0;
            }
        }
    }
}
void connectandcyclic()
{
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == 1)
            visit[i] = 2;
        if (visit[i] == -1)
        {
            f = 0;
            bfs(i);
        }
    }
    if (f)
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
            for (j = 1; j < n; j++)
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
    printf("Enter the adjacency matrix\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter the Starting Vertex : ");
    scanf("%d", &start);
    bfs(start);
    connectandcyclic();
    printf("Operation Count : %d\n", opc);
    return 0;
}
