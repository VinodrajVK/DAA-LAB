#include <stdio.h>
#include <stdlib.h>
int i, j, k, n, count;
void copyarr(int c[n][n], int d[n][n])
{
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            c[i][j] = d[i][j];
}
void warshall(int a[n][n])
{
    int p[n][n], q[n][n];
    copyarr(p, a);
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
            {
                count++;
                q[i][j] = (p[i][j] || (p[i][k] && p[k][j]));
            }

        copyarr(p, q);
    }
    printf("Transitive Closure\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ", q[i][j]);
        printf("\n");
    }
    printf("Operation Count : %d\n", count);
}
void checkdirected(int a[n][n])
{
    int flag = 0;
    for (i = 1; i <= n - 1; i++)
        for (j = i; j <= n; j++)
            if (a[i][j] == 1 && a[j][i] == 1)
            {
                flag = 1;
                break;
            }
    if (flag == 1)
        printf("Warshall Algorithm not Applicable because graph is undirected\n");
    else
        warshall(a);
}
int main()
{
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter the adjacency matrix\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    checkdirected(a);
    return 0;
}
