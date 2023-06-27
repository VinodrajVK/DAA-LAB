#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define x 10
#define y 100
#define inc 10
int count, countc;
void heapify(int H[], int n)
{
    int i, j, k, v, heap;
    for (i = n / 2; i >= 1; i--)
    {
        k = i;
        v = H[k];
        heap = 0;
        while (!heap && 2 * k <= n)
        {
            // countc++;
            j = 2 * k;
            if (j < n)
            {

                if (H[j] < H[j + 1])
                {
                    countc++;
                    j++;
                }
            }
            if (v >= H[j])
            {
                // countc++;
                heap = 1;
            }
            else
            {
                // countc++;
                H[k] = H[j];
                k = j;
            }
            H[k] = v;
        }
    }
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void heapsort(int H[], int n)
{
    for (int i = n; i >= 2; i--)
    {
        count++;
        swap((H + 1), (H + n));
        // heapsort(H, n - 1);
        heapify(H, n - 1);
    }
}
int main()
{
    int *H, i, n;
    FILE *fp, *fpc;
    fp = fopen("HSort.txt", "w");
    fpc = fopen("HSortCount.txt", "w");
    srand(time(0));
    for (n = x; n <= y; n += inc)
    {
        H = (int *)malloc((n + 1) * sizeof(int));
        fprintf(fp, "\nArray : ");
        H[1] = rand() % 100;
        fprintf(fp, " %d", H[1]);
        for (i = 2; i <= n; i++)
        {
            H[i] = H[i - 1] + rand() % 100;
            fprintf(fp, " %d", H[i]);
        }
        count = 0;
        countc = 0;
        heapify(H, n);
        heapsort(H, n);
        fprintf(fp, "\nSorted Array : ");
        for (i = 1; i <= n; i++)
            fprintf(fp, " %d", H[i]);
        printf("%d\t%d\n", n, (countc));
        fprintf(fpc, "%d\t%d\n", n, (countc));
    }
    fclose(fp);
    fclose(fpc);
    return 0;
}
