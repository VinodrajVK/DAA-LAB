#include <stdio.h>
#include <stdlib.h>
int i, n, j, opc, visit[10], acyclic = 1, f = 0, r = -1;
int a[10][10], queue[10];
void bfs(int s)
{
    int k = 1, p[n];
    queue[++r] = s;
    p[s] = 0;
    visit[s] = 0;
    while (f <= r)
    {
        s = queue[f++];
        visit[s] = 1;
        for (i = 1; i <= n; i++)
        {
            opc++;
            if (a[s][i] && visit[i] == 1 && p[s] != i)
                acyclic = 0;
            if (a[s][i] && visit[i] == -1)
            {
                queue[++r] = i;
                visit[i] = 0;
                p[i] = s;
            }
        }
    }
}
void connectandcyclic()
{
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == 1)
            visit[i] = 2;
        if (visit[i] == -1)
            bfs(i);
    }
}
int main()
{
    FILE *fp = fopen("BFSCount.txt", "w");
    for (n = 4; n <= 8; n++)
    {
        opc = 0;
        for (i = 1; i <= n; i++)
            visit[i] = -1;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                {
                    if(i==j)
                        a[i][j]=0;
                    else
                        a[i][j]=1;
                }
        bfs(1);
        connectandcyclic();
        fprintf(fp, "%d\t%d\n", n, opc);
    }
    fclose(fp);
}
