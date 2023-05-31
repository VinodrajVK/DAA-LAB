#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define x 10
#define y 100
#define inc 10
int count;
void quicksort(int *a, int l, int r);
void swap(int *a, int *b);
int partition(int *a, int l, int r);
void main()
{
int *a,i,n;
srand(time(0));
FILE *fp = fopen("QSortCount.txt","w");
for(n=x;n<=y;n+=inc)
{
a=(int *)malloc(n*sizeof(int));
//Best case
a[0]=rand()%100;
count=0;
for(i=1;i<n;i++)
a[i]=a[0];
quicksort(a,0,n-1);
fprintf(fp,"%d\t%d\t",n,count);

//Average Case
for(i=0;i<n;i++)
a[i]=rand()%100;
count=0;
quicksort(a,0,n-1);
fprintf(fp,"%d\t",count);

//Worst case
a[0]=rand()%100;
for(i=1;i<n;i++)
a[i]=a[i-1]+rand()%100;
count=0;
quicksort(a,0,n-1);
fprintf(fp,"%d\n",count);
}
fclose(fp);
free(a);
system("gedit QSortCount.txt");
}

void quicksort(int *a, int l, int r)
{
if(l<r)
{
int s = partition(a,l,r);
quicksort(a,l,s-1);
quicksort(a,s+1,r);
}
}

int partition(int *a, int l, int r)
{
int i=l,j=r+1,t=a[l];
do{
do{
i++;
count++;
}while(a[i]<t&&i<=r);
do{
j--;
count++;
}while(a[j]>t&&j>=l);
swap(a+i,a+j);
}while(i<=j);
swap(a+i,a+j);
swap(a+l,a+j);
return j;
}

void swap(int *a,int *b)
{
int t=*a;
*a=*b;
*b=t;
}
