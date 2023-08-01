#include <stdio.h>
#include <stdlib.h>
int n, f = 0, r = -1, Q[10], a[10][10], indeg[10], inqueue[10], Q[10], opc = 0, order[10], ord = 1;
void toposr()
{
    int source, num = n, flag;
    while (num > 0)
    {
        flag = 0;
        for (int i = 1; i <= n; i++)
        {
            opc++;
            if (indeg[i] == 0 && inqueue[i] == 0)
            {
                Q[++r] = i;
                inqueue[i] = 1;
                flag = 1;
            }
        }
        if (f <= r)
            flag = 1;
        if (flag == 0)
        {
            printf("Not Possible\n");
            exit(0);
        }
        source = Q[f++];
        order[ord++] = source;
        num--;
        indeg[source] = -1;
        for (int i = 1; i <= n; i++)
            if (a[source][i])
                indeg[i]--;
    }
}
void main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency Matrix\n");
    for (int i = 1; i <= n; i++)
    {
        indeg[i] = 0;
        inqueue[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j])
                indeg[j]++;
        }
    }
    printf("Topological Sorting : ");
    toposr();
    for (int i = 1; i < ord; i++)
        printf("%d ", order[i]);
    printf("\nOperation Count : %d\n", opc);
}
