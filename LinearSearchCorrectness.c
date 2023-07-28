#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define x 10
#define y 100
#define inc 10
int count;
int ls(int *a, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        count++;
        if (a[i] == key)
            return i;
    }
    return -1;
}
void main()
{
    int *a, n, key, pos;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("Enter the Elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter Key: ");
    scanf("%d", &key);
    pos = ls(a, n, key);
    if (pos == -1)
        printf("Key not found\n");
    else
        printf("Key Found at %d\n", (pos + 1));
}
