#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define x 10
#define y 100
#define inc 10
int count;
void join(int arr[],int left[],int right[],int l,int m,int r)
{
int i,j;
for(i=0;i<=m-l;i++)
arr[i]=left[i];
for(j=0;j<r-m;j++)
arr[i+j]=right[j];
}

void split(int arr[],int left[],int right[],int l,int m,int r)
{
for(int i=0;i<=m-l;i++)
left[i]=arr[i*2];
for(int j=0;j<r-m;j++)
right[j]=arr[j*2+1];
}

void genWorstCase(int arr[],int l,int r)
{
if(l<r)
{
int m=l+(r-l)/2;
int left[m-l+1];
int right[r-m];
split(arr,left,right,l,m,r);
genWorstCase(left,l,m);
genWorstCase(right,m+1,r);
join(arr,left,right,l,m,r);
}
}

void copy(int *a,int l, int r, int *b)
{
int i=l;
int j=0;
while(i<=r&&j<=r)
b[j++]=a[i++];
}
void merge(int *b,int n1,int *c,int n2, int *a)
{
int i=0,j=0,k=0;
while(i<n1&&j<n2)
{
count++;
if(b[i]<=c[j])
a[k]=b[i++];
else 
a[k]=c[j++];
k++;
}
if(j==n2)
while(i<n1)
a[k++]=b[i++];
else
while(j<n2)
a[k++]=c[j++];
}
void mergesort(int *a,int n)
{
if(n>1)
{
int n1 = n/2;
int n2 = (n+1)/2;
int *b=(int *)malloc(n1*sizeof(int));
int *c=(int *)malloc(n2*sizeof(int));
copy(a,0,(n-1)/2,b);
copy(a,n/2,n-1,c);
mergesort(b,n1);
mergesort(c,n2);
merge(b,n1,c,n2,a);
}
}
void main()
{
int *a,i,n;
FILE *fp = fopen("MSortCount.txt","w");
FILE *fpa = fopen("Array.txt","w");
srand(time(0));
for(n=x;n<=y;n+=inc)
{
a = (int*)malloc(n*sizeof(int));

//Best Case
a[0]=rand()%100;
for(i=1;i<n;i++)
a[i]=a[i-1]+rand()%100;
fprintf(fpa,"\nBest Case Array :");
for(i=0;i<n;i++)
fprintf(fpa," %d",a[i]);
count=0;
mergesort(a,n);
fprintf(fp,"%d\t%d\t",n,count);
fprintf(fpa,"\nBest Case Sorted Array :");
for(i=0;i<n;i++)
fprintf(fpa,"%d ",a[i]);

//Average Case
for(i=0;i<n;i++)
a[i]=rand()%100;
count=0;
fprintf(fpa,"\nAverage Case Array :");
for(i=0;i<n;i++)
fprintf(fpa,"%d ",a[i]);
mergesort(a,n);
fprintf(fp,"%d\t",count);
fprintf(fpa,"\nAverage Case Sorted Array :");
for(i=0;i<n;i++)
fprintf(fpa,"%d ",a[i]);

//Worst Case
a[0]=rand()%100;
for(i=1;i<n;i++)
a[i]=a[i-1]+rand()%100;
genWorstCase(a,0,n-1);
count=0;
fprintf(fpa,"\nWorst Case Array :");
for(i=0;i<n;i++)
fprintf(fpa,"%d ",a[i]);
fprintf(fpa,"\n");
mergesort(a,n);
fprintf(fp,"%d\n",count);
fprintf(fpa,"\nWorst Case Sorted Array :");
for(i=0;i<n;i++)
fprintf(fpa,"%d ",a[i]);
}
fclose(fp);
system("gedit MSortCount.txt Array.txt");
}
