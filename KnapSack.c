#include <stdio.h>
#include <stdlib.h>
int i, j, n, c, count;
int maximum(int a, int b)
{
    return (a > b) ? a : b;
}
void composition(int f[][c + 1], int w[])
{
    int num = 0;
    int subset[n];
    j = c;
    for (i = n; i >= 1; i--)
    {
        if (f[i][j] != f[i - 1][j])
        {
            subset[num++] = i;
            j -= w[i];
        }
    }
    printf("Composition is : ");
    for (i = 0; i < num; i++)
        printf("%d ", subset[i]);
    printf("\n");
}
void knapsack(int f[n + 1][c + 1], int w[], int v[])
{
    for (i = 0; i <= n; i++)
    {
        f[i][0] = 0;
        count++;
    }
    for (j = 1; j <= c; j++)
    {
        f[0][j] = 0;
        count++;
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= c; j++)
        {
            count++;
            if (j - w[i] >= 0)
                f[i][j] = maximum(f[i - 1][j], v[i] + f[i - 1][j - w[i]]);
            else
                f[i][j] = f[i - 1][j];
        }
    printf("The Optimal Solution is %d\n", f[n][c]);
}

int main()
{
    printf("Enter the number of items : ");
    scanf("%d", &n);
    printf("Enter the Capacity : ");
    scanf("%d", &c);
    int w[n], v[n], f[n + 1][c + 1];
    printf("Enter the Items' Weights and Value\n");
    printf("Item\tWeight\tValue\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t", i);
        scanf("%d\t%d", &w[i], &v[i]);
    }
    knapsack(f, w, v);
    composition(f, w);
    printf("Operation Count : %d\n", count);
    return 0;
}
