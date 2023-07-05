#include <stdio.h>
#include <stdlib.h>
int i, j, n,c, count;
int maximum(int a, int b)
{
    return (a > b) ? a : b;
}
void knapsack(int w[n], int v[n])
{
    int f[n+1][c+1];
    for (i = 0; i <= n; i++)
       for (j = 0; j <= c; j++)
            {
            		count++;
                if(j-w[i]>=0)
                	f[i][j]=maximum(f[i-1][j],v[i]+f[i-1][j-w[i]]);
                else
                	f[i][j]=f[i-1][j];
            }
    printf("The Optimal Solution is %d\n",f[n][c]);
}
int main()
{
    printf("Enter the number of items : ");
    scanf("%d", &n);
    printf("Enter the Capacity : ");
    scanf("%d",&c);
    int w[n],v[n];
    printf("Enter the Items' Weights and Value\n");
    printf("Item\tWeight\tValue\n");
    for(i=1;i<=n;i++)
    {
    	printf("%d\t",i);
    	scanf("%d\t%d",&w[i],&v[i]);
    }
    knapsack(w,v);
    printf("Operation Count : %d\n",count);
    return 0;
}
