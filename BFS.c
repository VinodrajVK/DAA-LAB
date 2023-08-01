#include <stdio.h>
#include <stdlib.h>
int a[10][10], visit[10], n, Q[20], f = 0, r = -1, traverse[10][10], count = 0, opc = 0, cyclic = 0;
void bfs(int start)
{
    count++;
    int p[n], v, k = 1, flag;
    Q[++r] = start;
    p[start] = 0;
    while (f <= r)
    {
        flag = 0;
        v = Q[f++];
        traverse[count][k++] = v;
        visit[v] = 1;
        for (int i = 1; i <= n; i++)
        {
            opc++;
            if (a[v][i])
                flag = 1;
            if (a[v][i] && visit[i] == 1 && i != p[v])
                cyclic = 1;
            if (a[v][i] && visit[i] == -1)
            {
                Q[++r] = i;
                visit[i] = 0;
                p[i] = v;
            }
        }
        if (flag == 0)
            visit[v] = 2;
    }
}
void connectcyclic()
{
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == 1)
            visit[i] = 2;
        if (visit[i] == -1)
        {
            bfs(i);
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        printf("The Graph is Disconnected\n");
        printf("The Graph has %d connected Components\n", count);
        printf("The Connected Components are\n");
        for (int i = 1; i <= count; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (traverse[i][j] != 0)
                    printf("%d ", traverse[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("The Graph is Connected\n");
        printf("The BFS Traversal is : ");
        for (int j = 1; j <= n; j++)
        {
            if (traverse[1][j] != 0)
                printf("%d ", traverse[1][j]);
        }
        printf("\n");
    }
    if (cyclic)
        printf("Graph is Cyclic\n");
    else
        printf("Graph is Acyclic\n");
}
void main()
{
    int start;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency Matrix\n");
    for (int i = 1; i <= n; i++)
    {
        visit[i] = -1;
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            traverse[i][j] = 0;
        }
    }
    printf("Enter the Starting Vertex : ");
    scanf("%d", &start);
    bfs(start);
    connectcyclic();
    printf("Operation Count : %d\n", opc);
}
