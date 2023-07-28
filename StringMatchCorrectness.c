#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define x 10
#define y 100
#define inc 10
FILE *fc;
int match(char *t, int n, char *p, int m)
{
    int i, j;
    for (i = 0; i < n - m; i++)
    {
        j = 0;
        while (j < m && t[i + j] == p[j])
        {
            j++;
        }
        if (j == m)
            return i;
    }
    return -1;
}
void main()
{
    int i, n, m, pos;
    char t[100], p[10];
    printf("Enter the Text : ");
    scanf("%s", t);
    printf("Enter the Pattern : ");
    scanf("%s", p);
    n = strlen(t);
    m = strlen(p);
    pos = match(t, n, p, m);
    if (pos == -1)
        printf("Pattern not found\n");
    else
        printf("Pattern matched Text at %d\n", (pos + 1));
}
