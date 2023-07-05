#include <stdio.h>
#include <stdlib.h>
int i, j, k, n, count;
int minimum(int a, int b)
{
    return (a < b) ? a : b;
}
void copyarr(int c[n][n], int d[n][n])
{
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            c[i][j] = d[i][j];
}
void floyd(int a[n][n])
{
    int d[n][n];
    copyarr(d, a);
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
            {
                count++;
                d[i][j] = minimum(d[i][j], (d[i][k] + d[k][j]));
            }
    }
    printf("Distance Matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ", d[i][j]);
        printf("\n");
    }
}
int main()
{
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter the Weight matrix\n");
    printf("!!Note : Enter 999 for Infinity!!\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    floyd(a);
    printf("Operation Count : %d\n", count);
    return 0;
}
