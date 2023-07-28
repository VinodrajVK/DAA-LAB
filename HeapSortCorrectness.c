#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count = 0;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    count++;
    if (left <= n && a[left] > a[largest])
        largest = left;

    if (right <= n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(a + i, a + largest);
        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n)
{
    int i;
    for (i = n / 2; i >= 1; i--)
        heapify(a, n, i);
    for (i = n; i > 1; i--)
    {
        swap(a + 1, a + i);
        heapify(a, i - 1, 1);
    }
}

int main()
{
    int *a, n;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    a = (int *)malloc((n + 1) * sizeof(int));
    printf("Enter the Elements\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    heapsort(a, n);
    printf("Sorted Array\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
}
