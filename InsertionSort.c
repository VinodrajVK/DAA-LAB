#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define x 10
#define y 100
#define inc 10
int countb,count;
void insertsort(int *a, int n);
void main()
{
int *a,i,n;
srand(time(0));
FILE *fp = fopen("ISortCount.txt","w");
for(n=x;n<=y;n+=inc)
{
a=(int *)malloc(n*sizeof(int));
//Best case
a[0]=rand()%100;
countb=0;
for(i=1;i<n;i++)
a[i]=a[i-1]+rand()%100;
insertsort(a,n);
fprintf(fp,"%d\t%d\t",n,countb);

//Average Case
for(i=0;i<n;i++)
a[i]=rand()%100;
count=0;
insertsort(a,n);
fprintf(fp,"%d\t",count);

//Worst case
a[n-1]=rand()%100;
count=0;
for(i=n-2;i>=0;i--)
a[i]=a[i+1]+rand()%100;
insertsort(a,n);
fprintf(fp,"%d\n",count);
}
fclose(fp);
free(a);
system("gedit ISortCount.txt");
}

void insertsort(int *a,int n)
{
int t,i,j;
for(i=1;i<n;i++)
{
j=i-1;
t=a[i];
countb++;
while(j>=0&&a[j]>t)
{
j--;
count++;
a[j+1]=a[j];
}
a[j+1]=t;
}
}
